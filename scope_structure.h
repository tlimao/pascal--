/*
 * scope_structure.h
 *
 *  Created on: 19/10/2013
 *      Author: Thiago
 */

#ifndef SCOPE_STRUCTURE_H
#define SCOPE_STRUCTURE_H

#include <stdio.h>
#include "gramatica.tab.h"
#include "tokens.h"

/** Espécies de símbolos (symbol) possíveis */
typedef enum { CONST, VAR, PROCEDURE, PARAM, PARAMLIST } especie;

/** Estrutura de símbolos que comp�em a tabela de símbolos */
typedef struct symbol
{
	especie    		  spec;			 // Espécie do Token
	size_t     		  id; 			 // Token Secundário
	int 	   		  type;			 // T_BOOLEAN | T_INTEGER | T_REAL
	YYSTYPE			  value;
	struct paramList* param_list;	 // Lista de parâmetros
	struct symbol*    next_symbol;	 // Ref. para próximo símbolo no escopo
	struct codeblock* code_fragment; // Fragmento de código
	int 			  stack_num;
}symbol;

/** Retorna uma instância de symbol */
symbol* symbolFactory();

/** Impressão formatada de um símbolo */
void printSymbol(symbol* pSymbol);

/** Lista será utilizada para guardar lista de parâmetros de procedimentos ( PROCEDURE ) */
typedef struct paramList
{
	int length;
	struct symbol* parameter;
}paramList;

/** Cria uma lista de parâmetros */
paramList* paramListFactory();

/** Adiciona um símbolo no início da lista de parâmetros
 * <p> pList - Lista que receberá o parâmetro
 * <p> pSymbol - Símbolo que será inserido
 **/
void paramListPushBack(paramList* pList, symbol* pSymbol);

/** Adiciona um símbolo no fim da lista de parâmetros
 * <p> pList - Lista que receberá o parâmetro
 * <p> pSymbol - Símbolo que será inserido
 **/
void paramListPushFront(paramList* pList, symbol* pSymbol);

/** Compara duas listas de parâmetros nos queistos Id e tipo
 * <p> pList1 - Base para comparação
 * <p> pList2 - Lista a ser comparada
 * <r> NULL - listas iguais
 * <r> symbol* - primeiro símbolo cujo id e/ou tipo sejam diferentes entre as listas
 **/
symbol* compareParamList(paramList* pList1, paramList* pList2);

/** Compara duas listas de parâmetros retornando a posição onde ocorrer diferençaa de tipos
 * <p> pList1 - Base para comparação
 * <p> pList2 - Lista a ser comparada
 * <r> 0 - listas iguais
 * <r> i ( i > 0) - posição do primeiro s�mbolo cujo id e/ou tipo sejam diferentes entre as listas
 **/
int compareParamList2(paramList* pList1, paramList* pList2);

/** Compara duas listas de parâmetros
 * <p> pList1 - Lista
 * <p> pSymbol - Símbolo que será buscado na lista de parâmetros
 * <r> 0 - não existe
 * <r> 1 - existe
 **/
int searchParam(paramList* pList, symbol* pSymbol);

/** Compara duas listas de parâmetros
 * <p> pList1 - Lista
 * <p> pId - Id (Token 2) que será buscado
 * <r> 0 - não encontrou
 * <r> 1 - encontrou
 **/
int searchParam2(paramList* pList, int pId);

/** Imprime uma lista de parâmetros
  * <p> pList - Lista que será impressa
  **/
void printParamList(paramList* pList);

/** Ajusta o Tipo dos parâmetros de uma lista de parâmetros
  * <p> pList - Lista de parâmetros
  * <p> pType - Tipo dos parâmetros
  **/
void setParamType(paramList* pList, int pType);

/** Desaloca uma Lista de parâmetros */
void releaseParamList(paramList* pList);

/** Estrutura de entrada em cada Escopo
 *
 *   ________
 *  |________| : scope struct
 *    ______
 *    \_____\  : symbol
 *
 *  A tabela de símbolos fica:
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
	int           id;         // Identificador do escopo
	int			  num_vars;   // Nº Variáveis do escopo
	int 		  num_consts; // Nº de Constantes do escopo
	int 		  num_params; // Nº de parâmetros - usado somente com procedures
	symbol* 	  first;	  // Ref. para o primeiro símbolo do escopo
	struct scope* down;		  // Ref. para escopo inferior
}scope;

static int scope_count = 0;

scope* top_scope;

/** Função que cria a tabela símbolos */
void initSymTab();

/** Função que imprime a tabela de símbolos */
void printSymTab();

/** Função que cria um novo bloco de escopo na tabela de símbolos */
void newScope();

/** Função que finaliza um bloco de escopo da tabela de símbolos */
void clearScope();

/** Função que realiza uma busca no escopo local da tabela de símbolos
 *  <r> 0 - não encontrou;
 *  <r> 1 - encontrou.
 **/
int localSearch(int pId);

/** Função que realiza uma busca até o escopo global da tabela de símbolos
*  <r> 0 - não encontrou;
*  <r> 1 - encontrou.
**/
int globalSearch(int pId);

/** Função que realiza uma busca até o escopo global da tabela de símbolos
*  <r> symbol* - símbolo encontrado correspondente ao pId passado;
*  <r> NULL - encontrou.
**/
symbol* globalSearch2(int pId);

/** Função que insere um elemento no escopo local da tabela de símbolos */
void insertLocal(symbol* pSymbol);

/** Insere um parâmetro no escopo local */
void insertParam(symbol* pSymbol);

/** Declaração de Variáveis - VAR */
symbol* varDeclare(int pId, int pType);

/** Declaração de Constantes - ( INT | REAL | BOOLEAN )_CONST */
symbol* constDeclare(int pId, YYSTYPE pValue, int pType);

/** Declaração de Procedimento - PROCEDURE */
symbol* procDeclare(int pId);

#endif /* SCOPE_STRUCTURE_H */
