/*
 * tokens.h
 *
 *  Created on: 16/08/2013
 *      Author: Thiago
 */

#ifndef TOKENS_H
#define TOKENS_H

/* Utilizado Anteriormente na análise léxica
#define T_EOF                  0
#define T_ID                   1
#define T_INT_CONST            2
#define T_REAL_CONST           3
#define T_BOOLEAN_CONST        4
#define T_PROGRAM              5
#define T_PROCEDURE            6
#define T_BEGIN                7
#define T_END                  8
#define T_IF                   9
#define T_THEN                 10
#define T_ELSE                 11
#define T_WHILE                12
#define T_DO                   13
#define T_ASSIGN               14
#define T_PLUS                 15
#define T_MINUS                16
#define T_TIMES                17
#define T_DIVIDE               18
#define T_DIV                  19
#define T_MOD                  20
#define T_PLUS_EQ              21
#define T_MINUS_EQ             22
#define T_TIMES_EQ             23
#define T_AND                  24
#define T_OR                   25
#define T_NOT                  26
#define T_DIVIDE_EQ            27
#define T_VAR                  28
#define T_INTEGER              29
#define T_REAL                 30
#define T_BOOLEAN              31
#define T_COLON                32
#define T_SEMICOLON            33
#define T_COMMA                34
#define T_PERIOD               35
#define T_DOUBLE_PERIOD        36
#define T_LBRACKET             37
#define T_RBRACKET             38
#define T_CONST                39
#define T_REPEAT               40
#define T_UNTIL                41
#define T_EQ                   42
#define T_DIF                  43
#define T_LT                   44
#define T_LEQ                  45
#define T_GT                   46
#define T_GEQ                  47
#define T_INVALID             255
*/

#include "lexer.h"
#include "gramatica.tab.h"
#include "buffer.h"
#include <math.h>

typedef struct token
{
	char  tk_name[32];							// Nome do Identificador caso seja um Token do tipo id
	int   tk_1;									// Token Primário
	int   tk_id;								// Token Secundário no caso de ser um id
	int   tk_int;								// Token Secundário no caso de ser um intconst
	int   tk_bool;								// Token Secundário no caso de ser um booleano
	float tk_real;								// Token Secundário no caso de ser um realconst
}token;

/** Nó para compor a lista de tokens do tipo T_ID */
typedef struct tokenNoh
{
	token* tk;
	struct tokenNoh* tk_prox;
}tokenNoh;

/** Referência para o primeiro elemento da lista de tokens do tipo T_ID */
static tokenNoh* tk2_list = NULL;

/** Variável que mantém o id para o próximo T_ID que será inserido na lista de tokens do tipo T_ID */
static int tk2_count = 0;

/** Retorna uma instância de token */
token* factoryToken();

/** Incrementa  tk2_count */
int incTk2Count();

/** Adiciona o novo id na lista de token identificadores */
void addIdToken(token* pToken);

/** Imprime a lista de tokens com tokens secundários */
void printTokenList();

/** Imprime o Token */
void printToken(token* pToken);

/** Busca um token baseado em seu id de token secundário na lista token2List */
token* getToken(int pId);

/** Função que retorna os tokens identificados nos dados fornecidos */
token* nextToken();

/** Verifica se o char é um digito */
int isDigit(char pChar);

/** Verifica se o char é um caractere */
int isAlpha(char pChar);

/** Verifica se o char é um underline */
int isUnderline(char pChar);

/** Verifica se o char é um separador "espaço" ou "tab" */
int isSeparator(char pChar);

/** Verifica se o char é um operador + - * / */
int isOperator(char pChar);

/** Verifica se o char é um marcador de fim de arquivo */
int isEOF(char pChar);

/** Verifica se o token é uma palavra reservada */
void classifyToken(token* pToken);

/** Verifica se o token é um int const ou real const */
token* isNumber();

#endif /* TOKENS_H */
