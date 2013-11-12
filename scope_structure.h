/*
 * scope_structure.h
 *
 *  Created on: 19/10/2013
 *      Author: Thiago
 */

#ifndef SCOPE_STRUCTURE_H
#define SCOPE_STRUCTURE_H

#include <stdio.h>
#include "parser_bison.tab.h"
#include "tokens.h"

/* ################################### Symbol Definition ################################### */
/** Esp�cies de simbolos (symbol) poss�veis */
typedef enum { CONST, VAR, PROCEDURE, PARAM, PARAMLIST } especie;

/** Estrutura de s�mbolos que comp�em a tabela de s�mbolos */
typedef struct symbol
{
	especie    		  spec;			// Esp�cie do Token
	size_t     		  id; 			// Token Secund�rio
	int 	   		  type;			// T_BOOLEAN | T_INTEGER | T_REAL
	struct paramList* param_list;	// Lista de par�metros
	struct symbol*    next_symbol;	// Ref. para pr�ximo simbolo no escopo
}symbol;

/** Retorna uma inst�ncia de symbol */
symbol* symbolFactory();

/** Impress�o formatada de um s�mbolo */
void printSymbol(symbol* pSymbol);

/* ################################### Parameters List Definition ################################### */
/** Lista ser� utilizada para guardar lista de par�metros de procedimentos ( PROCEDURE ) */
typedef struct paramList
{
	int length;
	struct symbol* parameter;
}paramList;

/** Cria uma lista de par�metros */
paramList* paramListFactory();

/** Adiciona um s�mbolo no in�cio da lista de par�metros
 * <p> pList - Lista que receber� o par�metro
 * <p> pSymbol - S�mbolo que ser� inserido
 **/
void paramListPushBack(paramList* pList, symbol* pSymbol);

/** Adiciona um s�mbolo no fim da lista de par�metros
 * <p> pList - Lista que receber� o par�metro
 * <p> pSymbol - S�mbolo que ser� inserido
 **/
void paramListPushFront(paramList* pList, symbol* pSymbol);

/** Compara duas listas de par�metros nos queistos Id e tipo
 * <p> pList1 - Base para compara��o
 * <p> pList2 - Lista a ser comparada
 * <r> NULL - listas iguais
 * <r> symbol* - primeiro s�mbolo cujo id e/ou tipo sejam diferentes entre as listas
 **/
symbol* compareParamList(paramList* pList1, paramList* pList2);

/** Compara duas listas de par�metros retornando a posi��o onde ocorrer diferen�a de tipos
 * <p> pList1 - Base para compara��o
 * <p> pList2 - Lista a ser comparada
 * <r> 0 - listas iguais
 * <r> i ( i > 0) - posi��o do primeiro s�mbolo cujo id e/ou tipo sejam diferentes entre as listas
 **/
int compareParamList2(paramList* pList1, paramList* pList2);

/** Compara duas listas de par�metros
 * <p> pList1 - Lista
 * <p> pSymbol - S�mbolo que ser� buscado na lista de par�metros
 * <r> 0 - n�o existe
 * <r> 1 - existe
 **/
int searchParam(paramList* pList, symbol* pSymbol);

/** Compara duas listas de par�metros
 * <p> pList1 - Lista
 * <p> pId - Id (Token 2) que ser� buscado
 * <r> 0 - n�o encontrou
 * <r> 1 - encontrou
 **/
int searchParam2(paramList* pList, int pId);

/** Imprime uma lista de par�metros
  * <p> pList - Lista que ser� impressa
  **/
void printParamList(paramList* pList);

/** Ajusta o Tipo dos par�metros de uma lista de par�metros
  * <p> pList - Lista de par�metros
  * <p> pType - Tipo dos par�metros
  **/
void setParamType(paramList* pList, int pType);

/** Desaloca uma Lista de par�metros */
void releaseParamList(paramList* pList);

/* ################################### SymTab Definition ################################### */
/** Estrutura de entrada em cada Escopo
 *
 *   ________
 *  |________| : scope struct
 *    ______
 *    \_____\  : symbol
 *
 *  A tabela de simbolos fica:
 *   ________   ______
 *  |________|->\_____\ -> NULL
 *   ___|____    ______     ______    ______
 *  |________|-> \_____\ -> \_____\-> \_____\ -> NULL
 *      |
 *     NULL
 *
 * */
typedef struct scope
{
	int           id;       // Identificador do escopo
	symbol* 	  first;	// Ref. para o primeiro s�mbolo do escopo
	struct scope* down;		// Ref. para escopo inferior
}scope;

static int scope_count = 0;

scope* top_scope;

/** Fun��o que cria a tabela s�mbolos */
void initSymTab();

/** Fun��o que imprime a tabela de s�mbolos */
void printSymTab();

/** Fun��o que cria um novo bloco de escopo na tabela de s�mbolos */
void newScope();

/** Fun��o que finaliza um bloco de escopo da tabela de s�mbolos */
void clearScope();

/** Fun��o que realiza uma busca no escopo local da tabela de s�mbolos
 *  <r> 0 - n�o encontrou;
 *  <r> 1 - encontrou.
 **/
int localSearch(int pId);

/** Fun��o que realiza uma busca at� o escopo global da tabela de s�mbolos
*  <r> 0 - n�o encontrou;
*  <r> 1 - encontrou.
**/
int globalSearch(int pId);

/** Fun��o que realiza uma busca at� o escopo global da tabela de s�mbolos
*  <r> symbol* - n�o symbolo encontrado correspondente ao pId passado;
*  <r> NULL - encontrou.
**/
symbol* globalSearch2(int pId);

/** Fun��o que insere um elemento no escopo local da tabela de s�mbolos */
void insertLocal(symbol* pSymbol);

/** Declara��o de Vari�veis - VAR */
symbol* varDeclare(int pId, int pType);

/** Declara��o de Constantes - ( INT | REAL | BOOLEAN )_CONST */
symbol* constDeclare(int pId, YYSTYPE pValue, int pType);

/** Declara��o de Procedimento - PROCEDURE */
symbol* procDeclare(int pId);

#endif /* SCOPE_STRUCTURE_H */
