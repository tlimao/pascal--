/*
 * bison_adaptee.h
 *
 *  Created on: 06/09/2013
 *      Author: Thiago
 */

#ifndef BISON_ADAPTEE_H
#define BISON_ADAPTEE_H

#include "parser_bison.tab.h"
#include "tokens.h"

extern int yytype;
extern YYSTYPE yylval;

/** Fun��o que ir� chamar a nextToken */
int yylex(void);

/** Fun��o que imprime a linha onde ocorreu o erro */
int yyerror(char* a);

#endif /* BISON_ADAPTEE_H */
