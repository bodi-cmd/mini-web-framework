%{
#include "y.tab.h"
%}

%%

[()<>\/\[\]=\{\}*+-]        return *yytext;
body                return BODY;
div                 return DIV;
h1                  return H1;
span                return SPAN;
button              return BUTTON;
declare             return DECLARE;
class               return CLASS;
id                  return ID;
if                  return IF;
action              return ACTION;
while               return WHILE;
for                 return FOR;
delay               return DELAY;

CODE_START   return CODE_START;
CODE_END     return CODE_END;

[0-9]+          {
                   yylval.integer = atoi(yytext);
                   return INTEGER;
                }
@[a-z][_a-zA-Z0-9]*         {yylval.varname = strdup(yytext);
                           return BINDING;}
[a-z][_a-zA-Z0-9]*         {yylval.varname = strdup(yytext);
                           return VARIABLE;}
[A-Z][_a-zA-Z0-9]*         {yylval.funcname = strdup(yytext);
                           return FUNCNAME;}

=\"[^\"]*\"               {yylval.value = strdup(yytext);;
                           return VALUE;}
\<text\>[a-zA-Z0-9 \.!:;-_]*\<\/text\>        {yylval.string = strdup(yytext);;
                           return STRING;}
[ \t\n]                    ;

