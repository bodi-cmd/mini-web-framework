%{

#include <stdio.h>
#include "string.h"
#include <stdlib.h>

int yylex();
void yyerror(char *s);

typedef enum { assignationType, varDecType, funcDecType, whileType,ifType,forType, delayType} stmtEnum;

typedef struct elm{
    int type;
    char* id;
    char* classes;
    char* action;
    char* text;
    struct elm *child;
    struct elm *parent;
    struct elm *neigh_down;
    struct elm *neigh_up;
    struct exp *if_expr;
} element;

typedef struct exp{
    char type;
    char *var_name;
    int int_value;
    struct exp *left_expr;
    struct exp *right_expr;
} expression;

typedef struct _assignation{
    stmtEnum type;
    char* varname;
    struct exp *expression;
}assignation;

typedef struct _delay{
    stmtEnum type;
    struct exp *expression;
}delay;

typedef struct _varDeclarationStruct{
    stmtEnum type;
    char* varname;
    struct exp *expression;
}varDeclarationStruct;

typedef struct _funcDeclarationStruct{
    stmtEnum type;
    char* funcname;
    struct _stmt_node *statements;
}funcDeclarationStruct;

typedef struct _whileDeclaration{
    stmtEnum type;
    struct exp *expression;
    struct _stmt_node *statements;
}whileDeclaration;

typedef struct _ifDeclaration{
    stmtEnum type;
    struct exp *expression;
    struct _stmt_node *statements;
}ifDeclaration;

typedef union _statement{
    stmtEnum type;
    struct _assignation assignation;
    struct _varDeclarationStruct varDeclaration;
    struct _funcDeclarationStruct funcDeclaration;
    struct _whileDeclaration whileDeclaration;
    struct _ifDeclaration ifDeclaration;
    struct _delay delayDeclaration;
}statement;

typedef struct _stmt_node{
    union _statement stmt;
    struct _stmt_node *next;
}stmt_node;

element *generateElement(int type, char *id, char *classes,expression *if_cond, char *action, element *child, char* text);
element *addListToElement(element *existing_element, element *list_head);
expression *generateExpression(char type, expression* left_expr,expression* right_expr);
expression *generateConstant(char *var_name,int int_value);
stmt_node* generateFunction(char* funcname, stmt_node *statements);
stmt_node* generateVar(char* varname, expression* expression);
stmt_node* generateAssignation(char* varname, expression* expression);
stmt_node *addStatementToList(stmt_node *node, stmt_node *head);
void printCodeList(stmt_node *node, int indentation);
char *expressionToString(expression *exp, int size);
void computeRenderingConditions();
void computeVariableDeclaringRendering();
void render(element* html_root, stmt_node *code_root);
stmt_node* generateWhile_If(stmtEnum type,expression* expression, stmt_node *statements);
stmt_node* generateDelay(expression* expression);


void printpre(element *node, int indentation);

%}

%union { 
        char* varname;
        char* value;
        char* string;
        int integer;
        char* funcname;
        struct elm *element_pointer;
        struct _cond *cond_pointer;
        struct exp *expr_pointer;
        struct _stmt_node *statement_pointer;
        }

%token BODY DIV H1 SPAN CLASS DECLARE BUTTON ID CODE_START CODE_END IF ACTION WHILE FOR DELAY
%token <varname> VARIABLE BINDING
%token <value> VALUE
%token <string> STRING
%token <integer> INTEGER
%token <funcname> FUNCNAME


%type <element_pointer> html_element html_list html
%type <value> class_node id_node action_node
%type <expr_pointer> expr if_node
%type <statement_pointer> stmt stmt_list func_declaration var_declaration code_section if_stmt while_stmt delay_stmt
%type page


%%
page : html code_section { render($1,$2); }

code_section : CODE_START stmt_list CODE_END {printf("<!--A parsat ok codul-->\n"); $$ = $2;}

html : '<' BODY '>' html_list '<' '/' BODY '>' {printf("<!--A parsat ok html-ul-->\n"); $$ = $4;}

html_element : '<' H1 class_node id_node if_node action_node '>' html_list '<' '/' H1 '>' {$$ = generateElement(H1, $4, $3,$5,$6, $8, NULL);}
             | '<' DIV class_node id_node if_node action_node '>' html_list '<' '/' DIV '>' {$$ = generateElement(DIV, $4, $3,$5,$6, $8, NULL);}
             | '<' SPAN class_node id_node if_node action_node '>' html_list '<' '/' SPAN '>' {$$ = generateElement(SPAN, $4, $3,$5,$6, $8, NULL);}
             | '<' BUTTON class_node id_node if_node action_node '>' html_list '<' '/' BUTTON '>' {$$ = generateElement(BUTTON, $4, $3,$5,$6, $8, NULL);}
             | STRING {$$ = generateElement(STRING, NULL, NULL,NULL, NULL, NULL, $1);};
             | BINDING {$$ = generateElement(BINDING, NULL, NULL,NULL, NULL, NULL, $1+1);}

html_list : html_list html_element {$$ = addListToElement($2, $1);}
          | {$$ = NULL;}
          ;

class_node : CLASS VALUE {$$ = $2+1;}
           | {$$ = NULL;}
           ;

action_node : ACTION VALUE {$$ = $2+1;}
            | {$$ = NULL;}
            ;

id_node : ID VALUE {$$ = $2+1;}
        | {$$ = NULL;}
        ;

if_node : IF '=' '[' expr ']' {$$ = $4;}
        | {$$ = NULL;}
        ;

var_declaration : DECLARE VARIABLE '=' expr {$$ = generateVar($2,$4);}
                | DECLARE VARIABLE {$$ = generateVar($2,NULL);}

func_declaration : FUNCNAME '{' stmt_list '}' {$$ = generateFunction($1, $3);}

while_stmt : WHILE '(' expr ')' '{' stmt_list '}' {$$ = generateWhile_If(whileType, $3, $6);}

if_stmt : IF '(' expr ')' '{' stmt_list '}' {$$ = generateWhile_If(ifType, $3, $6);}

delay_stmt : DELAY '(' expr ')' {$$ = generateDelay($3);}

stmt_list : stmt_list stmt {$$ = addStatementToList($2, $1);}
          | {$$ = NULL;}

stmt : VARIABLE '=' expr {$$ = generateAssignation($1, $3);}
     | var_declaration {$$ = $1;}
     | func_declaration {$$ = $1;}
     | while_stmt {$$ = $1;}
     | if_stmt {$$ = $1;}
     | delay_stmt {$$ = $1;}

expr  : INTEGER               { $$ = generateConstant(NULL, $1); }
      | VARIABLE              { $$ = generateConstant($1, 0);}
      | expr '+' expr         { $$ = generateExpression('+', $1, $3);}
      | expr '-' expr         { $$ = generateExpression('-', $1, $3);}
      | expr '*' expr         { $$ = generateExpression('*', $1, $3);}
      | expr '/' expr         { $$ = generateExpression('/', $1, $3); }
      | expr '<' expr         { $$ = generateExpression('<', $1, $3); }
      | expr '>' expr         { $$ = generateExpression('>', $1, $3); }
      | expr '=''=' expr      { $$ = generateExpression('e', $1, $4); }
      | expr '<''=' expr      { $$ = generateExpression('l', $1, $4); }
      | expr '>''=' expr      { $$ = generateExpression('g', $1, $4); }
      ;

%%

int conditionCount = 0;
expression *conditions[100];

int varCounts = 0;
stmt_node *variables[100];

void main(){
    yyparse();
}


void yyerror(char *s)
{
    printf("\n%s\n",s);
}


stmt_node *addStatementToList(stmt_node *node, stmt_node *head){
    if(head == NULL){
        return node;
    }
    stmt_node *tail = head;
    while(tail->next){
        tail = tail->next;
    };
    tail->next = node;
    return head;
}

char *getTabs(int count){
    char *tabs = (char*) calloc(50,1);
    strcpy(tabs," ");
    for(int i=0;i<count;i++){
        strcat(tabs,"\t");
    }
    return tabs;
}

stmt_node* generateAssignation(char* varname, expression* expression){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = assignationType;
    p->stmt.assignation.varname = varname;
    p->stmt.assignation.expression = expression;
    p->next = NULL;
    return p;
}

stmt_node* generateVar(char* varname, expression* expression){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = varDecType;
    p->stmt.varDeclaration.varname = varname;
    p->stmt.varDeclaration.expression = expression;
    p->next = NULL;

    variables[varCounts++] = p;
    return p;
}

stmt_node* generateFunction(char* funcname, stmt_node *statements){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = funcDecType;
    p->stmt.funcDeclaration.funcname = funcname;
    p->stmt.funcDeclaration.statements = statements;
    p->next = NULL;
    return p;
}

stmt_node* generateWhile_If(stmtEnum type,expression* expression, stmt_node *statements){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = type;
    p->stmt.whileDeclaration.expression = expression;
    p->stmt.whileDeclaration.statements = statements;
    p->next = NULL;
    return p;
}

stmt_node* generateDelay(expression* expression){
    stmt_node *p = (stmt_node*)malloc(sizeof(stmt_node));
    p->stmt.type = delayType;
    p->stmt.delayDeclaration.expression = expression;
    p->next = NULL;
    return p;
}

expression *generateConstant(char *var_name,int int_value){
    expression *p = (expression*)malloc(sizeof(expression));

    p->type = var_name != NULL ? 'v' : 'i';
    p->int_value = int_value;
    p->var_name = var_name;
    p->left_expr=NULL;
    p->right_expr =NULL;

    return p;
}

expression *generateExpression(char type, expression* left_expr,expression* right_expr){
    expression *p = (expression*)malloc(sizeof(expression));
    p->type= type;
    p->left_expr=left_expr;
    p->right_expr = right_expr;

    return p;
}

element *addListToElement(element *existing_element, element *list_head){
    if(list_head == NULL){
        return existing_element;
    }
    element *tail = list_head;
    while(tail->neigh_down){
        tail = tail->neigh_down;
    };
    existing_element->neigh_up = tail;
    tail->neigh_down = existing_element;
    return list_head;
}


element *generateElement(int type, char *id, char *classes,expression *if_cond, char *action, element *child, char* text){
    element *p = (element*)malloc(sizeof(element));
    p->type= type;
    p->id=id;
    p->classes = classes;
    p->action = action;
    p->child = child;
    p->neigh_down = NULL;
    p->neigh_up = NULL;
    p->text = text;
    p->if_expr = if_cond;

    if(child != NULL){
        child->parent = p;
    }
    return p;
}

char *expressionToString(expression *exp, int size){
    char* expstr = (char*) calloc(size,1);

    if(exp->type == 'i'){
        sprintf(expstr, "%d", exp->int_value);
        return expstr;
    }
    else if(exp->type == 'v'){
        sprintf(expstr, "getVar('%s')", exp->var_name);
        return expstr;
    }
    else if(exp->type == 'e'){
        sprintf(expstr, "%s == %s", expressionToString(exp->left_expr, size/2), expressionToString(exp->right_expr, size/2));
        return expstr;
    }
    else if(exp->type == 'l'){
        sprintf(expstr, "%s <= %s", expressionToString(exp->left_expr, size/2), expressionToString(exp->right_expr, size/2));
        return expstr;
    }
    else if(exp->type == 'g'){
        sprintf(expstr, "%s >= %s", expressionToString(exp->left_expr, size/2), expressionToString(exp->right_expr, size/2));
        return expstr;
    }
    else{
        sprintf(expstr, "%s %c %s", expressionToString(exp->left_expr, size/2),exp->type, expressionToString(exp->right_expr, size/2));
        return expstr;
    }
    return expstr;
}

void computeVariableDeclaringRendering(){

    char *render = (char*) calloc(5000,1);

    sprintf(render,"const variables = {\n");

    for(int i=0;i<varCounts;i++){
        
            /* p->stmt.type = varDecType;
    p->stmt.varDeclaration.varname = varname;
    p->stmt.varDeclaration.expression = expression;
    p->next = NULL; */

        varDeclarationStruct varNode = variables[i]->stmt.varDeclaration;

        char *json = (char*) calloc(350,1);
        sprintf(json, 
        "'%s' : {\n"
        "    value: %s,\n"
        "    elements: document.querySelectorAll('.%s-binding')\n"
        "},\n"
        ,varNode.varname, expressionToString(varNode.expression,200), varNode.varname);
        strcat(render,json);
    }
    strcat(render,"}\n");
    printf("%s",render);
}

void computeRenderingConditions(){

    char *renderingConditions = (char*) calloc(5000,1);

    sprintf(renderingConditions,"const conditions = [\n");

    for(int i=0;i<conditionCount;i++){
        char *condstr = expressionToString(conditions[i],200);
        char *json = (char*) calloc(350,1);
        sprintf(json, 
        "{\n"
        "   condition: () => %s,\n"
        "   element: document.querySelector(\".cond-with-id%d\")\n"
        "},\n"
        ,condstr,i);
        strcat(renderingConditions,json);
    }
    strcat(renderingConditions,"]\n");
    printf("%s",renderingConditions);
}

void printCodeList(stmt_node *node, int indentation){
    if(node != NULL){
        char *tabs = getTabs(indentation);
        if(node->stmt.type == varDecType){
            //printf("var declaration\n");
        }
        else if(node->stmt.type == funcDecType){
            printf("%sconst %s = async () => {\n",tabs,node->stmt.funcDeclaration.funcname);
            printCodeList(node->stmt.funcDeclaration.statements,indentation+1);
            printf("%s}\n",tabs);
        }
        else if(node->stmt.type == whileType){
            printf("%swhile(%s){\n",tabs,expressionToString(node->stmt.whileDeclaration.expression,200));
            printCodeList(node->stmt.whileDeclaration.statements,indentation+1);
            printf("%s}\n",tabs);
        }
        else if(node->stmt.type == ifType){
            printf("%sif(%s){\n",tabs,expressionToString(node->stmt.ifDeclaration.expression,200));
            printCodeList(node->stmt.ifDeclaration.statements,indentation+1);
            printf("%s}\n",tabs);
        }
        else if(node->stmt.type == assignationType){
            printf("%supdateVar('%s',%s)\n",tabs,node->stmt.assignation.varname, expressionToString(node->stmt.assignation.expression,200));
        }
        else if(node->stmt.type == delayType){
            printf("%sawait delay(%s)\n",tabs,expressionToString(node->stmt.delayDeclaration.expression,200));
        }
        printCodeList(node->next, indentation);
    }
}

void printpre(element *node, int indentation){
    if(node != NULL){
        char *tabs = getTabs(indentation);
        int hasClasses = node->classes != NULL;
        int hasAction = node->action != NULL;
        int hasId = node->id != NULL;
        int hasCondition = node->if_expr != NULL;


        char *action_s = (char*)calloc(50,1);
        char *class_s = (char*)calloc(100,1);
        char *id_s = (char*)calloc(50,1);

        if(hasCondition){
            conditions[conditionCount] = node->if_expr;
            char *all_classes = (char*) calloc(120,1);
            if(hasClasses){
                sscanf(node->classes,"\"%[^\"]",all_classes);
            }
            sprintf(all_classes, "%s cond-with-id%d",all_classes,conditionCount);
            node->classes = all_classes;
            hasClasses = 1;
            conditionCount++;
        }
        if(hasClasses){
            sscanf(node->classes,"\"%[^\"]",node->classes);
            sprintf(class_s, " class=\"%s\"",node->classes);
        }
        if(hasId){
            sscanf(node->id,"\"%[^\"]",node->id);
            sprintf(id_s, " id=\"%s\"",node->id);
        }

        if(hasAction){
            sscanf(node->action,"\"%[^\"]",node->action);
            sprintf(action_s, " onclick=\"%s()\"",node->action);
        }

        if(node->type == H1){
            printf("%s<h1%s%s%s>\n",tabs,hasClasses ? class_s : "",hasId ? id_s : "", hasAction ? action_s : "");
            printpre(node->child,indentation+1);
            printf("%s</h1>\n",tabs);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == DIV){
            printf("%s<div%s%s%s>\n",tabs,hasClasses ? class_s : "",hasId ? id_s : "", hasAction ? action_s : "");
            printpre(node->child,indentation+1);
            printf("%s</div>\n",tabs);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == BUTTON){
            printf("%s<button%s%s%s>\n",tabs,hasClasses ? class_s : "",hasId ? id_s : "", hasAction ? action_s : "");
            printpre(node->child,indentation+1);
            printf("%s</button>\n",tabs);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == SPAN){
            printf("%s<span%s%s%s>\n",tabs,hasClasses ? class_s : "",hasId ? id_s : "", hasAction ? action_s : "");
            printpre(node->child,indentation+1);
            printf("%s</span>\n",tabs);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == BINDING){
            printf("%s<span class=\"%s-binding\"></span>\n",tabs,node->text);
            printpre(node->neigh_down,indentation);
        }
        else if(node->type == STRING){
            char *s = (char*)calloc(100,1);
            sscanf(node->text,"<text>%[^<]",s);
            printf("%s%s\n",tabs,s);
            printpre(node->neigh_down,indentation);
        }
    }
}

void render(element* html_root, stmt_node *code_root){

    printf("<!DOCTYPE html>\n"
            "<html lang=\"en\">\n"
            "<head>"
            "    <meta charset=\"UTF-8\">\n"
            "    <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n"
            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
            "    <title>Framework example</title>\n"
            "</head>\n"
            "<body>\n\n");

    printpre(html_root,0);
    printf("</body>\n\n<script>\n\n");

    computeRenderingConditions();
    computeVariableDeclaringRendering();

    printf("\nconst updateUI = (varName, newValue) => {\n"
           "    variables[varName].elements.forEach(element=>element.innerHTML = newValue);\n"
           "    conditions.forEach((cond, i)=>{\n"
           "        if(cond.condition()){\n"
           "            cond.element.style.display = '';\n"
           "        }\n"
           "        else{\n"
           "            cond.element.style.display = 'none';\n"
           "        }\n"
           "    });\n"
           "}\n"
           "const delay = (delayInms) => {\n"
           "     return new Promise(resolve => setTimeout(resolve, delayInms))\n"
           "     }\n"
           "const updateVar = (varName, value) => {\n"
           "    variables[varName].value = value;\n"
           "    updateUI(varName, value);\n"
           "}\n"
           "const getVar = (varName) => {\n"
           "    return variables[varName].value;\n"
           "}\n\n");

    printCodeList(code_root,0); 
    printf("\n\n</script>\n</html>\n");
}

     