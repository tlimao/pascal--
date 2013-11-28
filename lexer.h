/*
 * bison_adaptee.h
 *
 *  Created on: 06/09/2013
 *      Author: Thiago
 */

#ifndef BISON_ADAPTEE_H
#define BISON_ADAPTEE_H

#include "tokens.h"

/** Função que irá chamar a nextToken */
int yylex(void);

/** Função que imprime a linha onde ocorreu o erro */
int yyerror(char* a);

#endif /* BISON_ADAPTEE_H */
