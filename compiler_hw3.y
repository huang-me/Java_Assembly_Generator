/*	Definition section */
%{
    #include "common.h" //Extern variables that communicate with lex
    #include <stdio.h>
    #include <math.h>
    #include <string.h>
    // #define YYDEBUG 1
    // int yydebug = 1;

    extern int yylineno;
    extern int yylex();
    extern FILE *yyin;

    /* for symbol table */
    int scope = 0;
    int indexArr[50], lineno[50], scopeArr[50];
    char* name[50], *typeArr[50], *elementType[50];
    int symNum[5];
    int varNum = 0;

    /* for println flag */
    int printflag = 0;

    /* for type */
    char *tmp_type;

    /* for check scope */
    int tmp_scope, i;

    /* for check type */
    int type1, type2;
    int add1, add2;
    char ty1[10],ty2[10];

    void yyerror (char const *s)
    {
        printf("error:%d: %s\n", yylineno, s);
    }

    /* Symbol table function - you can add new function if needed. */
    static void create_symbol();
    static void insert_symbol(int, char*, char*, int, char*);
    static int lookup_symbol(char*, int);
    static void dump_symbol(int);

    FILE *file;
    int tmp_id = -1;
    int label = 0,forcount = 0;
    int infor = 0;
    int error = 0;
    int lastScope = -1;
%}

%error-verbose

/* Use variable or self-defined structure to represent
 * nonterminal and token type
 */
%union {
    int i_val;
    int si_val;
    float f_val;
    float sf_val;
    char *s_val;
    char *id_val;
    /* ... */
}

/* Token without return */
%token VAR
%token INT FLOAT BOOL STRING
%token INC DEC GEQ LEQ EQL NEQ ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN
%token QUO_ASSIGN REM_ASSIGN LAND LOR NEWLINE PRINT PRINTLN IF ELSE FOR 
%token TRUE FALSE

/* Token with return, which need to sepcify type */
%token <i_val> INT_LIT
%token <si_val> SIGN_INT_LIT
%token <f_val> FLOAT_LIT
%token <sf_val> SIGN_FLOAT_LIT
%token <s_val> STRING_LIT
%token <id_val> ID

/* Nonterminal with return, which need to sepcify type */
/*
%type <type> Type TypeName ArrayType
*/

/* Yacc will start at this nonterminal */
%start Program

/* Grammar section */
%%

Program
    : stmt stmts    { create_symbol(); }
    |
;

stmts
    : stmt stmts
    |               { dump_symbol(scope); }
;

stmt
    : Def
    | NEWLINE
    | cal
    | print
    | block
    | setVal
    | error_assign
    | ifelse
    | FOR {
        infor = 1;
        if(lastScope == scope) {
            forcount = forcount + 1;
            if(forcount == 0) forcount++;
        }
        fprintf(file, "for%d%d:\n", scope*2, forcount);
    } forloop {
        fprintf(file, "goto for%d%d\nfor%d%d:\n", scope*2, forcount, scope*2+1, forcount);
        infor = 0;
        lastScope = scope;
    }
    | const_add
;

const
    : INT_LIT {
        fprintf(file, "ldc %d\n", $1);
    }
    | FLOAT_LIT     {
        printf("FLOAT_LIT %f\n", $1);
        fprintf(file, "ldc %f\n", $1);
        }
;

const_add
    : INT_LIT '+' FLOAT_LIT     {
        printf("INT_LIT %d\nFLOAT_LIT %f\n", $1, $3);
        printf("error:%d: invalid operation: ADD (mismatched types int32 and float32)\n", yylineno+1);
        printf("ADD\n");
    }
    | FLOAT_LIT '+' FLOAT_LIT   {
        printf("FLOAT_LIT %f\nFLOAT_LIT %f\n", $1, $3);
        printf("ADD\n");
    }
    | ID '%' INT_LIT            {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
        printf("INT_LIT %d\n", $3);
        printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno+1);
        printf("REM\n");
    }
    | INT_LIT LAND TRUE         {
        printf("INT_LIT %d\n", $1);
        printf("TRUE\n");
        printf("error:%d: invalid operation: (operator LAND not defined on int32)\n", yylineno+1);
        printf("LAND\n");
    }
    | FALSE {printf("FALSE\n");} LOR expr    {
        printf("error:%d: invalid operation: (operator LOR not defined on int32)\n", yylineno);
        printf("LOR\n");
    }
    | ID '+' INT_LIT            {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
        printf("INT_LIT %d\n", $3);
        printf("ADD\n");
    }
;

forloop
    : const '{' {
        printf("error:%d: non-bool (type float32) used as for condition\n", yylineno+1);
    } {scope++;} stmts '}'    {scope--;}

    | const_add '{' {
        printf("error:%d: non-bool (type int32) used as for condition\n", yylineno+1);
    } {scope++;} stmts '}'    {scope--;}

    | ID '=' {
        for(int i=0;i<=scope;i++) {
            if(lookup_symbol($1, i) != -1) tmp_scope = lookup_symbol($1, i);
        }
        fprintf(file, "iload %d\n", tmp_scope);
    } const {
        fprintf(file, "istore %d\n", tmp_scope);
        fprintf(file, "for%d%d:\n", scope*2, forcount);
    } ';' ident compare ';' ID INC '{' {scope++;} stmts '}'     {
        for(int i=0; i<=scope; i++) {
            if(lookup_symbol($1, i) != -1)
                tmp_scope = lookup_symbol($1, i);
        }
        fprintf(file, "iload %d\n", tmp_scope);
        fprintf(file, "ldc 1\niadd\nistore %d\n", tmp_scope);
        scope--;
        }

    | expr '{' {scope++;} stmts '}'     {scope--;}
;

elses
    : ELSE IF expr '{' {
        scope++;
        fprintf(file, "ifeq label%d\n", label);
        fprintf(file, "ldc 0\ngoto label%d\n", label+1);
        fprintf(file, "label%d:\nldc 1\n", label);
        } stmts '}' {
            scope--;
            fprintf(file, "goto endif%d\n", scope);
        } elses {
            fprintf(file, "goto endif%d\n", scope);
            fprintf(file, "label%d:\n", label+1);
            label = label + 2;
            }
    | ELSE '{' {
        scope++;
        } stmts '}'         {
        scope--;
        }
    |
;

ifelse
    : IF expr '{' {
        scope++;
        fprintf(file, "ifeq label%d\n", label);
        fprintf(file, "ldc 0\ngoto label%d\n", label+1);
        fprintf(file, "label%d:\nldc 1\n", label);
        } stmts '}'      { 
            scope--; 
            fprintf(file, "goto endif%d\n", scope);
            fprintf(file, "label%d:\n", label+1);
            label = label + 2;
        } elses {
            fprintf(file, "endif%d:\n", scope);
        }
    | IF ID {
        printf("IDENT (name=%s, address=%d)\n", $2, lookup_symbol($2, scope));
        printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, "int32");
    } '{' {scope++;} stmts '}'        {scope--;}

    | IF FLOAT_LIT {
        printf("FLOAT_LIT %f\n", $2);
        printf("error:%d: non-bool (type %s) used as for condition\n", yylineno+1, "float32");
    } '{' {scope++;} stmts '}'        {scope--;}
;

error_assign
    : INT_LIT {printf("INT_LIT %d\n", $1); } assign
    | FLOAT_LIT {printf("FLOAT_LIT %f\n", $1);} assign
;

assign
    : '=' expr           { printf("ASSIGN\n"); }
    | ADD_ASSIGN expr    { printf("error:%d: cannot assign to int32\nADD_ASSIGN\n", yylineno); 
        error = 1;
    }
    | SUB_ASSIGN     { printf("SUB_ASSIGN\n"); }
    | MUL_ASSIGN     { printf("MUL_ASSIGN\n"); }
    | QUO_ASSIGN     { printf("QUO_ASSIGN\n"); }
    | REM_ASSIGN     { printf("REM_ASSIGN\n"); }
;

setVal
    : ID '[' INT_LIT    { 
        fprintf(file, "aload %d\n", lookup_symbol($1, scope));
        printf("IDENT (name=%s, address=%d)\nINT_LIT %d\n", $1, lookup_symbol($1, scope), $3);
        fprintf(file, "ldc %d\n", $3);
    } ']' value_initial  { 
        printf("ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "iastore\n");
        else if(printflag == 2)
            fprintf(file, "fastore\n");
    }
    | ident assignVal NEWLINE {
        if(printflag == 0 || printflag == 1)
            fprintf(file, "istore %d\n", tmp_scope);
        else if(printflag == 2)
            fprintf(file, "fstore %d\n", tmp_scope);
        else if(printflag == 3)
            fprintf(file, "astore %d\n", tmp_scope);
    }
    | ID '=' var NEWLINE {
        if(type2 != type1) {
            printf("error:%d: invalid operation: ASSIGN (mismatched types %s and %s)\n", yylineno, typeArr[add1], typeArr[add2]);
        }
        printf("ASSIGN\n"); 

        if(printflag == 0 || printflag == 1)
            fprintf(file, "istore %d\n", lookup_symbol($1, scope));
        else if(printflag == 2)
            fprintf(file, "fstore %d\n", lookup_symbol($1, scope));
        else if(printflag == 3)
            fprintf(file, "astore %d\n", lookup_symbol($1, scope));
    }
;

var
    : INT_LIT               {
        printf("INT_LIT %d\n", $1);
        type2 = 0;
        fprintf(file, "ldc %d\n", $1);
    }
    | FLOAT_LIT             {
        printf("FLOAT_LIT %f\n", $1); 
        type2 = 2;
        fprintf(file, "ldc %f\n", $1);
    }
    | '"' STRING_LIT '"'    {
        printf("STRING_LIT %s\n", $2); 
        type2 = 3;
        fprintf(file, "ldc \"%s\"\n", $2);
    }
    | TRUE                  {
        printf("TRUE\n"); 
        type2 = 1;
        fprintf(file, "ldc 1\n");
    }
    | FALSE                 {
        printf("FALSE\n"); 
        type2 = 1;
        fprintf(file, "iconst_0\n");
    }
    | ID                    {
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
        type2 = 0;
        if( strcmp(typeArr[lookup_symbol($1, scope)],"bool") == 0 ) {
            printflag = 1;
            type2 = 1;
        }
        else if( strcmp(typeArr[lookup_symbol($1, scope)],"float32") == 0 ) {
            printflag = 2;
            type2 = 2;
        }
        else if( strcmp(typeArr[lookup_symbol($1, scope)],"string") == 0 ) {
            printflag = 3;
            type2 = 3;
        }
        add2 = lookup_symbol($1, scope);
    }
    | expr
;

assignVal
    : ADD_ASSIGN var    { 
        printf("ADD_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "iadd\n");
        else if(printflag == 2)
            fprintf(file, "fadd\n");
    }
    | SUB_ASSIGN var    { 
        printf("SUB_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "isub\n");
        else if(printflag == 2)
            fprintf(file, "fsub\n");
    }
    | MUL_ASSIGN var    { 
        printf("MUL_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "imul\n");
        else if(printflag == 2)
            fprintf(file, "fmul\n");
    }
    | QUO_ASSIGN var    { 
        printf("QUO_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "idiv\n");
        else if(printflag == 2)
            fprintf(file, "fdiv\n");
    }
    | REM_ASSIGN var    { 
        printf("REM_ASSIGN\n"); 
        if(printflag == 0)
            fprintf(file, "irem\n");
    }
;

ident
    : ID    { tmp_scope = -1;
        type1 = 0;
        for(i=0; i<=scope; i++) {
            if(lookup_symbol($1, i) != -1) tmp_scope = lookup_symbol($1, i);
        }
        add1 = tmp_scope;
        if( tmp_scope == -1 ) {
            printf("error:%d: undefined: %s\n", yylineno+1, $1);
        }
        else {
            printf("IDENT (name=%s, address=%d)\n", $1, tmp_scope); 
            if( strcmp(typeArr[tmp_scope],"bool") == 0 ) {
                printflag = 1;
                type1 = 1;
            }
            else if( strcmp(typeArr[tmp_scope],"float32") == 0 ) {
                printflag = 2;
                type1 = 2;
                fprintf(file, "fload %d\n", tmp_scope);
                tmp_id = tmp_scope;
            }
            else if( strcmp(typeArr[tmp_scope],"string") == 0 ) {
                printflag = 3;
                type1 = 3;
            }
            else {
                fprintf(file, "iload %d\n", tmp_scope);
                tmp_id = tmp_scope;
            }
        }
    }
;

value_initial
    : '=' expr NEWLINE
    |
;

block
    : '{' NEWLINE {scope++;} stmts '}' NEWLINE     { scope--; }
;

Def
    : VAR ID INT INT_initial        {
        insert_symbol( scope, $2, "int32", yylineno, "-"); 
        fprintf(file, "istore %d\n", lookup_symbol($2, scope));
    }
    | VAR ID STRING STR_initial     { 
        insert_symbol( scope, $2, "string", yylineno, "-"); 
        fprintf(file, "astore %d\n", lookup_symbol($2, scope));
    }
    | VAR ID FLOAT FLOAT_initial    {
        insert_symbol( scope, $2, "float32", yylineno, "-");
        fprintf(file, "fstore %d\n", lookup_symbol($2, scope));
    }
    | VAR ID BOOL BOOL_initial      { 
        insert_symbol( scope, $2, "bool", yylineno, "-"); 
        fprintf(file, "fstore %d\n", lookup_symbol($2, scope));
    }
    | VAR ID '[' INT_LIT { 
        printf("INT_LIT %d\n", $4);
        fprintf(file, "ldc %d\n", $4);
        } ']' typee NEWLINE   { 
            insert_symbol( scope, $2, "array", yylineno, tmp_type); 
            if(strcmp(tmp_type, "int32") == 0)
                fprintf(file, "newarray int\n");
            else 
                fprintf(file, "newarray float\n");
            fprintf(file, "astore %d\n", lookup_symbol($2, scope));
    }
;

typee
    : INT           { tmp_type = "int32"; }
    | FLOAT         { tmp_type = "float32"; }
;

BOOL_initial
    : '=' TRUE NEWLINE          {
        printf("TRUE\n");
        fprintf(file, "ldc 1\n");
    }
    | '=' FALSE NEWLINE         {
        printf("FALSE\n");
        fprintf(file, "ldc 0\n");
    }
    | NEWLINE
;

FLOAT_initial
    : '=' FLOAT_LIT NEWLINE     {
        printf("FLOAT_LIT %f\n", $2);
        fprintf(file, "ldc %f\n", $2);
    }
    | NEWLINE {
        fprintf(file, "ldc 0.0\n");
    }
;

INT_initial
    : '=' INT_LIT NEWLINE   {
        printf("INT_LIT %d\n", $2);
        fprintf(file, "ldc %d\n", $2);
    }
    | NEWLINE {
        fprintf(file, "ldc 0\n");
    }
;

STR_initial
    : '=' '"' STRING_LIT '"' NEWLINE    {
        printf("STRING_LIT %s\n", $3);
        fprintf(file, "ldc \"%s\"\n", $3);
    }
    | NEWLINE {
        fprintf(file, "ldc \"\"\n");
    }
;

cal
    : ident INC       {
                        printf("INC\n");
                        if(strcmp(typeArr[tmp_id], "int32") == 0) {
                            fprintf(file, "ldc 1\n");
                            fprintf(file, "iadd\n");
                            fprintf(file, "istore %d\n", tmp_id);
                        }
                        else if(strcmp(typeArr[tmp_id], "float32") == 0) {
                            fprintf(file, "ldc 1.0\n");
                            fprintf(file, "fadd\n");
                            fprintf(file, "fstore %d\n", tmp_id);
                        }
                      }
    | ident DEC       {
                        printf("DEC\n");
                        if(strcmp(typeArr[tmp_id], "int32") == 0) {
                            fprintf(file, "ldc 1\n");
                            fprintf(file, "isub\n");
                            fprintf(file, "istore %d\n", tmp_id);
                        }
                        else if(strcmp(typeArr[tmp_id], "float32") == 0) {
                            fprintf(file, "ldc 1.0\n");
                            fprintf(file, "fsub\n");
                            fprintf(file, "fstore %d\n", tmp_id);
                        }
                      }
    | ID '+' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        strcpy(ty1, typeArr[lookup_symbol($1, scope)]);
                        strcpy(ty2, typeArr[lookup_symbol($3, scope)]);
                        if( strcmp(ty1,ty2) != 0 ) {
                            printf("error:%d: invalid operation: ADD (mismatched types %s and %s)\n", yylineno+1, ty1, ty2);
                        }
                        printf("ADD\n"); 
                      }
    | ID '-' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        strcpy(ty1, typeArr[lookup_symbol($1, scope)]);
                        strcpy(ty2, typeArr[lookup_symbol($3, scope)]);
                        if( strcmp(ty1,ty2) != 0 ) {
                            printf("error:%d: invalid operation: SUB (mismatched types %s and %s)\n", yylineno+1, ty1, ty2);
                        }
                        printf("SUB\n"); 
                      }
    | ID '*' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        strcpy(ty1, typeArr[lookup_symbol($1, scope)]);
                        strcpy(ty2, typeArr[lookup_symbol($3, scope)]);
                        if( strcmp(ty1,ty2) != 0 ) {
                            printf("error:%d: invalid operation: MUL (mismatched types %s and %s)\n", yylineno+1, ty1, ty2);
                        }
                        printf("MUL\n"); 
                      }
    | ID '/' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        strcpy(ty1, typeArr[lookup_symbol($1, scope)]);
                        strcpy(ty2, typeArr[lookup_symbol($3, scope)]);
                        if( strcmp(ty1,ty2) != 0 ) {
                            printf("error:%d: invalid operation: QUO (mismatched types %s and %s)\n", yylineno+1, ty1, ty2);
                        }
                        printf("QUO\n"); 
                      }
    | ID '%' ID       { 
                        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope));
                        printf("IDENT (name=%s, address=%d)\n", $3, lookup_symbol($3, scope));
                        strcpy(ty1, typeArr[lookup_symbol($1, scope)]);
                        strcpy(ty2, typeArr[lookup_symbol($3, scope)]);
                        if( strcmp("float32",ty2) == 0 ) {
                            printf("error:%d: invalid operation: (operator REM not defined on float32)\n", yylineno+1);
                        }
                        printf("REM\n"); 
                      }
;

print
    : PRINTLN { printflag = 0; } '(' expr ')' {
        if(printflag == 0) {
            printf("PRINTLN int32\n");
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/println(I)V\n");
        }
        else if(printflag == 1) {
            printf("PRINTLN bool\n");

            fprintf(file, "ifne label%d\nldc \"false\"\ngoto label%d\n", label, label+1);
            fprintf(file, "label%d:\nldc \"true\"\n", label);

            fprintf(file, "label%d:\n", label+1);
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
            label = label + 2;
        }
        else if(printflag == 2) {
            printf("PRINTLN float32\n");
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/println(F)V\n");
        }
        else {
            printf("PRINTLN string\n");

            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/println(Ljava/lang/String;)V\n");
        }
    }
    | PRINT { printflag = 0; } '(' expr ')' {
        if(printflag == 0) {
            printf("PRINT int32\n");
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/print(I)V\n");
        }
        else if(printflag == 1) {
            printf("PRINT bool\n");

            fprintf(file, "ifne label%d\nldc \"false\"\ngoto label%d\n", label, label+1);
            fprintf(file, "label%d:\nldc \"true\"\n", label);

            fprintf(file, "label%d:\n", label+1);
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
            label = label + 2;
        }
        else if(printflag == 2)  {
            printf("PRINT float32\n");
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/print(F)V\n");
        }
        else {
            printf("PRINT string\n");
            fprintf(file, "getstatic java/lang/System/out Ljava/io/PrintStream;\n");
            fprintf(file, "swap\ninvokevirtual java/io/PrintStream/print(Ljava/lang/String;)V\n");
        }
    }
;

expr
    : expr '+' preexpr  {
        printf("ADD\n");
        if(printflag == 0) {
            fprintf(file, "iadd\n");
        }
        else if(printflag == 2) {
            fprintf(file, "fadd\n");
        }
    }
    | expr '-' preexpr  {
        printf("SUB\n");
        if(printflag == 0) {
            fprintf(file, "isub\n");
        }
        else if(printflag == 2) {
            fprintf(file, "fsub\n");
        }
    }
    | expr '%' preexpr  {
        printf("REM\n");
        if(printflag == 0) {
            fprintf(file, "irem\n");
        }
        else if(printflag == 2) {
            fprintf(file, "frem\n");
        }
    }
    | preexpr
    | term
    | expr compare expr     { printflag = 1; }
    | andor expr
    | '(' expr ')'
    | bool                  { printflag = 1; }
    | '"' STRING_LIT '"'    { 
        printf("STRING_LIT %s\n", $2); 
        printflag = 3; 
        fprintf(file, "ldc \"%s\"\n", $2);
    }
    | 
;

preexpr
    : preexpr '*' preexpr  {
        printf("MUL\n");
        if(printflag == 0) {
            fprintf(file, "imul\n");
        }
        else if(printflag == 2) {
            fprintf(file, "fmul\n");
        }
    }
    | preexpr '/' preexpr  {
        printf("QUO\n");
        if(printflag == 0) {
            fprintf(file, "idiv\n");
        }
        else if(printflag == 2) {
            fprintf(file, "fdiv\n");
        }
    }
    | '(' expr ')'
    | term
;

andor
    : LAND expr     { 
        printf("LAND\n"); 
        fprintf(file, "iand\n");
    }
    | LOR expr      { 
        printf("LOR\n"); 
        fprintf(file, "ior\n");
    }
;

bool
    : '!' bool { 
        printf("NOT\n"); 
        fprintf(file, "iconst_1\nixor\n");
    }  expr 
    | TRUE          { 
        printf("TRUE\n"); 
        fprintf(file, "iconst_1\n");
    }
    | FALSE         { 
        printf("FALSE\n"); 
        fprintf(file, "iconst_0\n");
    }
;

compare
    : '>' expr      {
        printf("GTR\n");
        if(printflag == 0) {
            fprintf(file, "isub\n");
            fprintf(file, "ifgt label%d\niconst_0\ngoto label%d\n", label, label+1);
            fprintf(file, "label%d:\niconst_1\nlabel%d:\n", label, label+1);
            if(infor == 1) {
                fprintf(file, "ifeq for%d%d\n", scope*2+1, forcount);
            }
        }
        else if(printflag == 2) {
            fprintf(file, "fcmpl\n");
            fprintf(file, "ifgt label%d\niconst_0\ngoto label%d\n", label, label+1);
            fprintf(file, "label%d:\niconst_1\nlabel%d:\n", label, label+1);
        }
        label = label + 2;
    }
    | '<' expr      { 
        printf("LSS\n"); 
        fprintf(file, "isub\n");
        fprintf(file, "iflt label%d\n", label);
        if(infor == 1)
            fprintf(file, "goto for%d%d\n", scope*2+1, forcount);
        else 
            fprintf(file, "ldc 0\n");
        fprintf(file, "goto label%d\nlabel%d:\n", label+1, label);
        if(infor == 0)
            fprintf(file, "ldc 1\n");
        fprintf(file, "label%d:\n", label+1);
        label = label + 2;
        }
    | GEQ expr      { printf("GEQ\n"); }
    | LEQ expr      {
        printf("LEQ\n"); 
        if(printflag == 0) {
            fprintf(file, "isub\nifle label%d\nldc 0\n", label);
            fprintf(file, "goto label%d\nlabel%d:\nldc 1\n", label+1, label);
            fprintf(file, "label%d:\n", label+1);
            label = label + 2;
        }
        else if(printflag == 2) {
            fprintf(file, "fsub\nifle label%d\nldc 0\n", label);
            fprintf(file, "goto label%d\nlabel%d:\nldc 1\n", label+1, label);
            fprintf(file, "label%d:\n", label+1);
            label = label + 2;
        }
        if(infor == 1) {
            fprintf(file, "ifeq for%d%d\n", scope*2+1, forcount);
        }
    }
    | EQL expr      { 
        printf("EQL\n"); 
        if(printflag == 0) {
            fprintf(file, "isub\n");
        }
        else if(printflag == 2)
            fprintf(file, "fsub\n");
        fprintf(file, "ifeq label%d\niconst_1\ngoto label%d\n", label, label+1);
        fprintf(file, "label%d:\niconst_0\nlabel%d:\n", label, label+1);
        label = label + 2;
    }
    | NEQ expr      { 
        printf("NEQ\n"); 
        if(printflag == 0) {
            fprintf(file, "isub\n");
        }
        else if(printflag == 2)
            fprintf(file, "fsub\n");
        fprintf(file, "ifne label%d\niconst_1\ngoto label%d\n", label, label+1);
        fprintf(file, "label%d:\niconst_0\nlabel%d:\n", label, label+1);
        label = label + 2;
        }
;

term
    : INT_LIT               {
        printf("INT_LIT %d\n", $1);
        fprintf(file, "ldc %d\n", $1);
        printflag = 0;
    }
    | FLOAT_LIT             { 
        printf("FLOAT_LIT %f\n", $1); 
        printflag = 2;
        fprintf(file, "ldc %f\n", $1);
    }
    | SIGN_INT_LIT          { 
                                printf("INT_LIT %d\n", abs($1)); 
                                fprintf(file, "ldc %d\n", abs($1));
                                if( abs($1) == $1) {
                                    printf("POS\n");
                                }
                                else {
                                    printf("NEG\n");
                                    fprintf(file, "ineg\n");
                                }
                            }
    | SIGN_FLOAT_LIT        { printf("FLOAT_LIT %f\n", fabs($1)); 
                                fprintf(file, "ldc %f\n", fabs($1));
                                if( abs($1) == $1) {
                                    printf("POS\n");
                                }
                                else {
                                    printf("NEG\n");
                                    fprintf(file, "fneg\n");
                                }
                            }
    | ID { 
        printf("IDENT (name=%s, address=%d)\n", $1, lookup_symbol($1, scope)); 
        fprintf(file, "aload %d\n", lookup_symbol($1, scope));
    } '[' expr ']' 
            {   
                if( strcmp(elementType[lookup_symbol($1, scope)],"float32") == 0 ) {
                    printflag = 2;
                    fprintf(file, "faload\n");
                }
                else if( strcmp(elementType[lookup_symbol($1, scope)],"string") == 0 )
                    printflag = 3; 
                else if(strcmp(elementType[lookup_symbol($1, scope)],"int32") == 0) 
                    fprintf(file, "iaload\n");
            }
    | ID    {   
                tmp_scope = -1;
                for(i=0; i<=scope; i++) {
                    if( lookup_symbol($1, i) != -1) tmp_scope = lookup_symbol($1, i);
                }

                if( tmp_scope == -1 ) {
                    printf("error:%d: undefined: %s\n", yylineno+1, $1);
                }
                else {
                    printf("IDENT (name=%s, address=%d)\n", $1, tmp_scope); 
                    if( strcmp(typeArr[tmp_scope],"float32") == 0 ) {
                        printflag = 2;
                        fprintf(file, "fload %d\n", tmp_scope);
                    }
                    else if( strcmp(typeArr[tmp_scope],"string") == 0 ) {
                        printflag = 3;
                        fprintf(file, "aload %d\n", tmp_scope);
                    }
                    else if( strcmp(typeArr[tmp_scope],"bool") == 0 ) {
                        printflag = 1;
                        fprintf(file, "iload %d\n", tmp_scope);
                    }
                    else {
                        fprintf(file, "iload %d\n", tmp_scope);
                    }
                }
            }
    | INT '(' ident ')'         { 
        printf("F to I\n"); 
        type1 = 0;
        fprintf(file, "f2i\n");
        printflag = 0;
    }
    | INT '(' FLOAT_LIT ')'     { 
        printf("FLOAT_LIT %f\nF to I\n",$3); 
        fprintf(file, "ldc %f\n", $3);
        fprintf(file, "f2i\n");
        printflag = 0;
    }
    | FLOAT '(' ident ')'       { 
        printf("I to F\n"); 
        fprintf(file, "i2f\n");
        printflag = 2;
    }
    | FLOAT '(' INT_LIT ')'     { 
        printf("INT_LIT %d\nI to F\n",$3); 
        type1 = 0;
        fprintf(file, "ldc %d\n", $3);
        fprintf(file, "i2f\n");
        printflag = 2;
    }
    | INT '(' ID '[' INT_LIT ']' ')' {
        fprintf(file, "aload %d\n", lookup_symbol($3, scope));
        fprintf(file, "ldc %d\n", $5);
        fprintf(file, "faload\n");
        fprintf(file, "f2i\n");
        printflag = 0;
    }
    | INT '(' expr ')' {
        fprintf(file, "f2i\n");
        printflag = 0;
    }
;

%%

/* C code section */
int main(int argc, char *argv[])
{
    if (argc == 2) {
        yyin = fopen(argv[1], "r");
    } else {
        yyin = stdin;
    }

    file = fopen("hw3.j", "wb");
    fprintf(file, ".source hw3.j\n");
    fprintf(file, ".class public Main\n");
    fprintf(file, ".super java/lang/Object\n");
    fprintf(file, ".method public static main([Ljava/lang/String;)V\n");
    fprintf(file, ".limit stack 100\n");
    fprintf(file, ".limit locals 100\n");

    yylineno = 0;
    yyparse();

	printf("Total lines: %d\n", yylineno);
    fclose(yyin);
    fprintf(file, "return\n.end method\n");
    fclose(file);
    if(error == 1)
        remove("hw3.j");
    return 0;
}

static void create_symbol() {
    /* initialize the symbol table */
    for(int i=0; i<50; i++) {
        indexArr[i] = 0;
        lineno[i] = 0;
        scopeArr[i] = -1;
        name[i] = NULL;
        typeArr[i] = NULL;
        elementType[i] = NULL;
    }
    for(int i=0; i<5; i++) {
        symNum[i] = 0;
    }
}

static void insert_symbol(int level, char *id, char *type, int linenum, char *element) {
    for(int i=0; i<varNum; i++) {
        if(strcmp(name[i],id) == 0 && scopeArr[i] == level) {
            printf("error:%d: %s redeclared in this block. previous declaration at line %d\n", linenum, id, lineno[i]);
            return;
        }
    }
    
    printf("> Insert {%s} into symbol table (scope level: %d)\n", id, level);
    
    int i = varNum;
    indexArr[i] = symNum[level];
    name[i] = id;
    typeArr[i] = type;
    lineno[i] = linenum;
    elementType[i] = element;
    scopeArr[i] = level;

    symNum[level]++;
    varNum++;
}

static int lookup_symbol(char *id, int level) {
    for(int i=0; i<varNum; i++) {
        if( strcmp(id,name[i]) == 0 && level == scopeArr[i] ) {
            return i;
        }
    }
    return -1;
}

static void dump_symbol(int level) {
    printf("> Dump symbol table (scope level: %d)\n", level);
    printf("%-10s%-10s%-10s%-10s%-10s%s\n",
           "Index", "Name", "Type", "Address", "Lineno", "Element type");
    for(int i=0; i<varNum; i++) {
        if(scopeArr[i] == level) {
            printf("%-10d%-10s%-10s%-10d%-10d%s\n",
            indexArr[i], name[i], typeArr[i], i, lineno[i], elementType[i]);

            scopeArr[i] = -1;
            strcpy(name[i], "");
        }
    }

    symNum[level] = 0;
}
