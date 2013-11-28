/*
 * scope_structure.c
 *
 *  Created on: 19/10/2013
 *      Author: Thiago
 */
#include "scope_structure.h"
#include <stdio.h>

/** Retorna uma instância de symbol */
symbol* symbolFactory()
{
	symbol* new_symbol = (symbol*) malloc(sizeof(symbol));

	new_symbol->next_symbol = NULL;
	new_symbol->param_list = NULL;
	new_symbol->code_fragment = codeBlockFactory(0);

	return new_symbol;
}

/** Impressão formatada de um símbolo */
void printSymbol(symbol* pSymbol)
{
	if ( pSymbol->spec == PARAM )
	{
		printf("\n		<p>|name: %s, id: %d, spec: %d, type: %d|", getToken(pSymbol->id)->tk_name, pSymbol->id, pSymbol->spec, pSymbol->type);
		printf("\nvalue: %d\n", pSymbol->value.tk_int);
		printf("<p>");
	}

	else
	{
		printf("\n	<s>|name: %s, id: %d, spec: %d, type: %d|", getToken(pSymbol->id)->tk_name, pSymbol->id, pSymbol->spec, pSymbol->type);
	}

	if ( pSymbol->param_list != NULL )
	{
		if ( pSymbol->param_list->length != 0 )
			printParamList(pSymbol->param_list);
	}
}

/** Cria uma lista de parâmetros */
paramList* paramListFactory()
{
	paramList* new_list = (paramList*) malloc(sizeof(paramList));

	new_list->parameter = NULL;
	new_list->length = 0;

	return new_list;
}

/** Adiciona um símbolo no início da lista de parâmetros
 * <p> pList - Lista que receberá o parâmetro
 * <p> pSymbol - Símbolo que será inserido
 **/
void paramListPushBack(paramList* pList, symbol* pSymbol)
{
	symbol* lSymbol = symbolFactory();

	memcpy(lSymbol, pSymbol, sizeof(symbol));

	if ( pList->parameter == NULL )
	{
		lSymbol->next_symbol = NULL;

		pList->parameter = lSymbol;
	}

	else
	{
		symbol* lAux = pList->parameter;

		while ( lAux->next_symbol != NULL )
		{
			lAux = lAux->next_symbol;
		}

		lAux->next_symbol = lSymbol;

		lSymbol->next_symbol = NULL;
	}

	pList->length++;
}

/** Adiciona um símbolo no fim da lista de parâmetros
 * <p> pList - Lista que receberá o parâmetro
 * <p> pSymbol - Símbolo que será inserido
 **/
void paramListPushFront(paramList* pList, symbol* pSymbol)
{
	symbol* lSymbol = symbolFactory();

	memcpy(lSymbol, pSymbol, sizeof(symbol));

	if ( pList->parameter == NULL )
	{
		lSymbol->next_symbol = NULL;

		pList->parameter = lSymbol;
	}

	else
	{
		lSymbol->next_symbol = pList->parameter;

		pList->parameter = lSymbol;
	}

	pList->length++;
}

paramList* invertParamList(paramList* pList)
{
	paramList* invertedParamList = paramListFactory();

	symbol* aux = pList->parameter;

	while ( aux != NULL )
	{
		paramListPushFront(invertedParamList, aux);

		aux = aux->next_symbol;
	}

	return invertedParamList;
}

/** Compara duas listas de parâmetros nos queistos Id e tipo
 * <p> pList1 - Base para comparação
 * <p> pList2 - Lista a ser comparada
 * <r> NULL - listas iguais
 * <r> symbol* - primeiro símbolo cujo id e/ou tipo sejam diferentes entre as listas
 **/
symbol* compareParamList(paramList* pList1, paramList* pList2)
{
	symbol* aux1;
	symbol* aux2;

	if ( pList1 != NULL && pList2 != NULL )
	{
		aux1 = pList1->parameter;
		aux2 = pList2->parameter;

		while ( ( aux1 != NULL ) || ( aux2 != NULL ) )
		{
			if ( checkCompatibility(aux1->type, aux2->type) == 0 )
			{
				return aux2;
				break;
			}

			aux1 = aux1->next_symbol;
			aux2 = aux2->next_symbol;
		}
	}

	return NULL;
}

/** Compara duas listas de parâmetros retornando a posição onde ocorrer diferença de tipos
 * <p> pList1 - Base para comparação
 * <p> pList2 - Lista a ser comparada
 * <r> 0 - listas iguais
 * <r> i ( i > 0) - posição do primeiro símbolo cujo id e/ou tipo sejam diferentes entre as listas
 **/
int compareParamList2(paramList* pList1, paramList* pList2)
{
	int diff = 0;

	symbol* aux1;
	symbol* aux2;

	if ( pList1 != NULL && pList2 != NULL )
	{
		aux1 = pList1->parameter;
		aux2 = pList2->parameter;

		while ( ( aux1 != NULL ) || ( aux2 != NULL ) )
		{
			if ( aux1->type != aux2->type )
			{
				return pList1->length - diff;
				break;
			}

			aux1 = aux1->next_symbol;
			aux2 = aux2->next_symbol;
			diff++;
		}
	}

	return 0;
}

/** Faz um merge de duas listas de parâmetros
  * <p> pList1 - Lista que receberá os valores
  * <p> pList2 - Lista de onde buscaremos os valores para dar o merge
  **/
void mergeParamList(paramList* pList1, paramList* pList2)
{
	symbol* aux1;
	symbol* aux2;

	if ( pList1 != NULL && pList2 != NULL )
	{
		aux1 = pList1->parameter;
		aux2 = pList2->parameter;

		aux1->value = aux2->value;

		while ( ( aux1 != NULL ) || ( aux2 != NULL ) )
		{
			aux1 = aux1->next_symbol;
			aux2 = aux2->next_symbol;
		}
	}
}

/** Compara duas listas de parâmetros
 * <p> pList1 - Lista
 * <p> pSymbol - Símbolo que será buscado na lista de parâmetros
 * <r> 0 - não existe
 * <r> 1 - existe
 **/
int searchParam(paramList* pList, symbol* pSymbol)
{
	if ( pList->parameter == NULL )
	{
		return 0;
	}

	else
	{
		symbol* aux;

		aux = pList->parameter;

		while ( aux->next_symbol != NULL )
		{
			if ( aux->id == pSymbol->id )
			{
				return 1;
			}
		}

		return 0;
	}
}

int searchParam2(paramList* pList, int pId)
{
	if ( pList->parameter == NULL )
	{
		return 0;
	}

	else
	{
		symbol* aux;

		aux = pList->parameter;

		while ( aux != NULL )
		{
			if ( aux->id == pId )
			{
				return 1;
			}

			aux = aux->next_symbol;
		}

		return 0;
	}
}

/** Busca um símbolo numa lista de parâmetros
 * <p> pList1 - Lista
 * <p> pSymbol - Símbolo que será buscado na lista de parâmetros
 * <r> symbol* se encontrar;
 * <r> NULL se não encontrar
 **/
symbol* getParam(paramList* pList, symbol* pSymbol)
{
	if ( pList->parameter == NULL )
	{
		return NULL;
	}

	else
	{
		symbol* aux;

		aux = pList->parameter;

		while ( aux->next_symbol != NULL )
		{
			if ( aux->id == pSymbol->id )
			{
				return aux;
			}
		}

		return NULL;
	}
}

/** Busca pelo Id um símbolo numa lista de parâmetros */
symbol* getParam2(paramList* pList, int pId)
{
	if ( pList->parameter == NULL )
	{
		return NULL;
	}

	else
	{
		symbol* aux;

		aux = pList->parameter;

		while ( aux->next_symbol != NULL )
		{
			if ( aux->id == pId )
			{
				return aux;
			}
		}

		return NULL;
	}
}

/** Imprime uma lista de parâmetros
  * <p> pList - Lista que será impressa
  * */
void printParamList(paramList* pList)
{
	if ( pList->length != 0 )
	{
		symbol* lSymbol = pList->parameter;

		printf("\n		ParamList Start");

		while ( lSymbol != NULL )
		{
			printSymbol(lSymbol);

			lSymbol = lSymbol->next_symbol;
		}
		printf("\n		ParamList End\n\n");
	}
}

/** Ajusta o Tipo dos parâmetros de uma lista de parâmetros
  * <p> pList - Lista de parâmetros
  * <p> pType - Tipo dos parâmetros
  * */
void setParamType(paramList* pList, int pType)
{
	if ( pList != NULL )
	{
		symbol* aux;

		aux = pList->parameter;

		while ( aux != NULL )
		{
			aux->type = pType;
			aux = aux->next_symbol;
		}
	}
}

/** Desaloca uma Lista de parâmetros */
void releaseParamList(paramList* pList)
{
	symbol* aux1;
	symbol* aux2;

	aux1 = pList->parameter;

	while ( aux1 != NULL )
	{
		aux2 = aux1->next_symbol;

		free(aux1);

		aux1 = aux2;
	}

	free(pList);
}

/** Função que cria a tabela símbolos */
void initSymTab()
{
	top_scope = (scope*) malloc(sizeof(scope));

	top_scope->id = scope_count++;
	top_scope->first = NULL;
	top_scope->down = NULL;
	top_scope->num_consts = 0;
	top_scope->num_vars = 0;
	top_scope->num_params = 0;
}

/** Função que imprime a tabela de símbolos */
void printSymTab()
{
	scope* scope;

	if ( top_scope != NULL )
	{
		scope = top_scope;
		printf("\n-----------------< TABELA DE SIMBOLOS >---------------------\n");

		while ( scope != NULL )
		{
			printf("\n[%d]\n ", scope->id);

			symbol* symbol = scope->first;

			while ( symbol != NULL )
			{
				printSymbol(symbol);

				symbol = symbol->next_symbol;

				if ( symbol != NULL )
				{
					printf("->");
				}
			}

			scope = scope->down;
		}

		printf("\n-------------------------< FIM >----------------------------\n");
	}

	else
	{
		printf("\nEmpty Symbol Tabel!!\n");
	}
}

/** Função que cria um novo bloco de escopo na tabela de símbolos */
void newScope()
{
	//printSymTab();

	scope* new_scope = (scope*) malloc(sizeof(scope));

	new_scope->id = scope_count++;
	new_scope->first = NULL;
	new_scope->down = top_scope;
	new_scope->num_consts = 0;
	new_scope->num_vars = 0;
	new_scope->num_params = 0;

	top_scope = new_scope;

	//printSymTab();
}

/** Função que finaliza um bloco de escopo da tabela de símbolos */
void clearScope()
{
	//printSymTab();

	symbol* aux1;
	symbol* aux2;

	aux1 = top_scope->first;

	while ( aux1 != NULL )
	{
		aux2 = aux1->next_symbol;

		if ( aux1->param_list != NULL )
		{
			releaseParamList(aux1->param_list);
		}

		free(aux1);

		aux1 = aux2;
	}

	top_scope = top_scope->down;

	scope_count--;

	// Deveria liberar memória :p

	//printSymTab();
}

/** Função que realiza uma busca no escopo local da tabela de símbolos
 *  <r> 0 - não encontrou;
 *  <r> 1 - encontrou.
 **/
int localSearch(int pId)
{
	int count = 0;

	symbol* aux;

	aux = top_scope->first;

	while ( aux != NULL )
	{
		if ( aux->id == pId )
		{
			count = 1;
			break;
		}

		aux = aux->next_symbol;
	}

	return count;
}

/** Função que realiza uma busca at� o escopo global da tabela de símbolos
*  <r> 0 - não encontrou;
*  <r> 1 - encontrou.
**/
int globalSearch(int pId)
{
	int count = 0;

	scope*  aux1;
	symbol* aux2;

	aux1 = top_scope;

	while ( aux1 != NULL )
	{
		aux2 = aux1->first;

		while ( aux2 != NULL )
		{
			if ( aux2->id == pId )
			{
				count = 1;
				break;
			}

			aux2 = aux2->next_symbol;
		}

		aux1 = aux1->down;
	}

	return count;
}

/** Função que realiza uma busca até o escopo global da tabela de símbolos
*  <r> symbol* - símbolo encontrado correspondente ao pId passado;
*  <r> NULL - encontrou.
**/
symbol* globalSearch2(int pId)
{
	int count = 0;

	scope*  aux1 = NULL;
	symbol* aux2 = NULL;

	aux1 = top_scope;

	while ( aux1 != NULL )
	{
		aux2 = aux1->first;

		while ( aux2 != NULL )
		{
			if ( aux2->id == pId )
			{
				count = 1;
				break;
			}

			aux2 = aux2->next_symbol;
		}

		if ( count == 0 )
			aux1 = aux1->down;

		else
			break;
	}

	return aux2;
}

/** Função que insere um elemento no escopo local da tabela de símbolos */
void insertLocal(symbol* pSymbol)
{
	symbol* lSymbol = symbolFactory();

	memcpy(lSymbol, pSymbol, sizeof(symbol));

	if ( top_scope->first == NULL )
	{
		lSymbol->next_symbol = NULL;

		top_scope->first = lSymbol;
	}

	else
	{
		symbol* aux = top_scope->first;

		while ( aux->next_symbol != NULL )
		{
			aux = aux->next_symbol;
		}

		lSymbol->next_symbol = NULL;

		aux->next_symbol = lSymbol;
	}
}

/** Insere um parâmetro no escopo local */
void insertParam(symbol* pSymbol)
{
	pSymbol->stack_num = top_scope->num_params++;

	insertLocal(pSymbol);
}

/** Declaração de Variáveis - VAR */
symbol* varDeclare(int pId, int pType)
{
	if ( localSearch(pId) != 0 )
	{
		return NULL;
	}

	symbol* s = symbolFactory();

	s->id = pId;
	s->param_list = NULL;
	s->spec = VAR;
	s->type = pType;

	insertLocal(s);

	return s;
}

/** Declaração de Constantes - ( INT | REAL | BOOLEAN )_CONST */
symbol* constDeclare(int pId, YYSTYPE pValue, int pType)
{
	if ( localSearch(pId) != 0 )
	{
		return NULL;
	}

	symbol* lSymbol = symbolFactory();

	lSymbol->id = pId;
	lSymbol->value = pValue;
	lSymbol->param_list = NULL;
	lSymbol->spec = CONST;
	lSymbol->stack_num = top_scope->num_consts++;

	if ( pType == T_INT_CONST )
	{
		lSymbol->type = T_INTEGER;
	}

	else if ( pType == T_REAL_CONST )
	{
		lSymbol->type = T_REAL;
	}

	else if ( pType == T_BOOLEAN_CONST )
	{
		lSymbol->type = T_BOOLEAN;
	}

	insertLocal(lSymbol);

	return lSymbol;
}

/** Declaração de Procedimento - PROCEDURE */
symbol* procDeclare(int pId)
{

	if ( localSearch(pId) != 0 )
	{
		return NULL;
	}

	symbol* lSymbol = symbolFactory();

	lSymbol->id = pId;
	lSymbol->param_list = paramListFactory();
	lSymbol->spec = PROCEDURE;
	lSymbol->type = T_INVALID;
	lSymbol->next_symbol = NULL;
	lSymbol->stack_num = procedure_count++;

	insertLocal(lSymbol);

	return lSymbol;
}
