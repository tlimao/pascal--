/*
 * type_check.c
 *
 *  Created on: 25/10/2013
 *      Author: Thiago
 */
#include "type_check.h"

#include "parser_bison.tab.h"

/** Cria a tabela com todas as opera��es e suas possibilidades de opera��es
  * Opera��es: + - * / mod div not and or = <> < <= > >=
  */
void createTypeTable()
{
	int i, j, k;

	// Hash de Operadores

	hashOperators = (int*) malloc(15*sizeof(int));

	for ( i = 0 ; i < 15 ; i++ )
	{
		hashOperators[i] = (int) malloc(2*sizeof(int));
	}

	hashOperators[0][0]  = T_PLUS   ; hashOperators[0][1]  = PLUS;
	hashOperators[1][0]  = T_MINUS  ; hashOperators[1][1]  = MINUS;
	hashOperators[2][0]  = T_TIMES  ; hashOperators[2][1]  = TIMES;
	hashOperators[3][0]  = T_DIVIDE ; hashOperators[3][1]  = DIVIDE;
	hashOperators[4][0]  = T_DIV    ; hashOperators[4][1]  = DIV;
	hashOperators[5][0]  = T_MOD    ; hashOperators[5][1]  = MOD;
	hashOperators[6][0]  = T_NOT    ; hashOperators[6][1]  = NOT;
	hashOperators[7][0]  = T_AND    ; hashOperators[7][1]  = AND;
	hashOperators[8][0]  = T_OR     ; hashOperators[8][1]  = OR;
	hashOperators[9][0]  = T_EQ     ; hashOperators[9][1]  = EQ;
	hashOperators[10][0] = T_LT     ; hashOperators[10][1] = LT;
	hashOperators[11][0] = T_LEQ    ; hashOperators[11][1] = LE;
	hashOperators[12][0] = T_GEQ    ; hashOperators[12][1] = GT;
	hashOperators[13][0] = T_GEQ    ; hashOperators[13][1] = GE;
	hashOperators[14][0] = T_DIF    ; hashOperators[14][1] = DIFF;

	// Hash de tipos

	hashTypes= (int*) malloc(3*sizeof(int));

	for ( i = 0 ; i < 3 ; i++ )
	{
		hashTypes[i] = (int) malloc(2*sizeof(int));
	}

	hashTypes[0][0]  = T_INTEGER ; hashTypes[0][1]  = INTEGER;
	hashTypes[1][0]  = T_REAL    ; hashTypes[1][1]  = REAL;
	hashTypes[2][0]  = T_BOOLEAN ; hashTypes[2][1]  = BOOLEAN;

	// Iniciando a tabela

	typeTableCheck = (int**) malloc(15*sizeof(int));

	for ( i = 0 ; i < 15 ; i++ )
	{
		typeTableCheck[i] = (int*) malloc(3*sizeof(int));

		for ( j = 0 ; j < 3 ; j++ )
		{
			typeTableCheck[i][j] = (int) malloc(3*sizeof(int));

			for ( k = 0 ; k < 3 ; k++ )
			{
				typeTableCheck[i][j][k] = 0;
			}
		}
	}

	typeCompatibleTable = (int*) malloc(3*sizeof(int));

	for ( i = 0 ; i < 3 ; i++ )
	{
		typeCompatibleTable[i] = (int) malloc(3*sizeof(int));
	}

	typeCompatibleTable[INTEGER][INTEGER] = 1;
	typeCompatibleTable[INTEGER][REAL] = 1;
	typeCompatibleTable[INTEGER][BOOLEAN] = 0;

	typeCompatibleTable[REAL][INTEGER] = 1;
	typeCompatibleTable[REAL][REAL] = 1;
	typeCompatibleTable[REAL][BOOLEAN] = 0;

	typeCompatibleTable[BOOLEAN][INTEGER] = 0;
	typeCompatibleTable[BOOLEAN][REAL] = 0;
	typeCompatibleTable[BOOLEAN][BOOLEAN] = 1;

	// Definindo compatibilidade entre tipos para cada opera��o HARD MODE

	// +
	typeTableCheck[PLUS][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[PLUS][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[PLUS][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[PLUS][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[PLUS][INTEGER][INTEGER] = T_INTEGER;
	typeTableCheck[PLUS][INTEGER][REAL]    = T_REAL;

	typeTableCheck[PLUS][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[PLUS][REAL][INTEGER] = T_REAL;
	typeTableCheck[PLUS][REAL][REAL]    = T_REAL;

	// -
	typeTableCheck[MINUS][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[MINUS][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[MINUS][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[MINUS][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[MINUS][INTEGER][INTEGER] = T_INTEGER;
	typeTableCheck[MINUS][INTEGER][REAL]    = T_REAL;

	typeTableCheck[MINUS][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[MINUS][REAL][INTEGER] = T_REAL;
	typeTableCheck[MINUS][REAL][REAL]    = T_REAL;

	// *
	typeTableCheck[TIMES][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[TIMES][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[TIMES][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[TIMES][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[TIMES][INTEGER][INTEGER] = T_INTEGER;
	typeTableCheck[TIMES][INTEGER][REAL]    = T_REAL;

	typeTableCheck[TIMES][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[TIMES][REAL][INTEGER] = T_REAL;
	typeTableCheck[TIMES][REAL][REAL]    = T_REAL;

	// /
	typeTableCheck[DIVIDE][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[DIVIDE][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[DIVIDE][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[DIVIDE][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[DIVIDE][INTEGER][INTEGER] = T_REAL;
	typeTableCheck[DIVIDE][INTEGER][REAL]    = T_REAL;

	typeTableCheck[DIVIDE][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[DIVIDE][REAL][INTEGER] = T_REAL;
	typeTableCheck[DIVIDE][REAL][REAL]    = T_REAL;

	// DIV
	typeTableCheck[DIV][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[DIV][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[DIV][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[DIV][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[DIV][INTEGER][INTEGER] = T_INTEGER;
	typeTableCheck[DIV][INTEGER][REAL]    = T_INTEGER;

	typeTableCheck[DIV][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[DIV][REAL][INTEGER] = T_INTEGER;
	typeTableCheck[DIV][REAL][REAL]    = T_INTEGER;

	// MOD
	typeTableCheck[MOD][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[MOD][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[MOD][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[MOD][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[MOD][INTEGER][INTEGER] = T_INTEGER;
	typeTableCheck[MOD][INTEGER][REAL]    = T_REAL;

	typeTableCheck[MOD][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[MOD][REAL][INTEGER] = T_REAL;
	typeTableCheck[MOD][REAL][REAL]    = T_REAL;

	/* NOT - ATEN��O !!!! com o not n�o faz sentido dois operandos,
	 * assim, a tabela para o not na dimens�o de BOOLEAN ( j = 0), �
	 * Inv�lida (T_INVALID) todas o elementos da matriz, contudo a
	 * linha da matriz j = BOOLEAN (0) representa a opera��o not
	 * aplicada sobre cada tipo, por exemplo:
	 *
	 * not true : typeTableCheck[NOT][0][BOOLEAN] = T_BOOLEAN;
	 * not integer : typeTableCheck[NOT][0][INTEGER] = T_INVALID;
	 * not real : typeTableCheck[NOT][0][REAL] = T_INVALID;
	 */
	typeTableCheck[NOT][0][BOOLEAN] = T_BOOLEAN;
	typeTableCheck[NOT][0][INTEGER] = T_INVALID;
	typeTableCheck[NOT][0][REAL]    = T_INVALID;

	typeTableCheck[NOT][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[NOT][INTEGER][INTEGER] = T_INVALID;
	typeTableCheck[NOT][INTEGER][REAL]    = T_INVALID;

	typeTableCheck[NOT][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[NOT][REAL][INTEGER] = T_INVALID;
	typeTableCheck[NOT][REAL][REAL]    = T_INVALID;

	// AND
	typeTableCheck[AND][BOOLEAN][BOOLEAN] = T_BOOLEAN;
	typeTableCheck[AND][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[AND][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[AND][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[AND][INTEGER][INTEGER] = T_INVALID;
	typeTableCheck[AND][INTEGER][REAL]    = T_INVALID;

	typeTableCheck[AND][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[AND][REAL][INTEGER] = T_INVALID;
	typeTableCheck[AND][REAL][REAL]    = T_INVALID;

	// OR
	typeTableCheck[OR][BOOLEAN][BOOLEAN] = T_BOOLEAN;
	typeTableCheck[OR][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[OR][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[OR][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[OR][INTEGER][INTEGER] = T_INVALID;
	typeTableCheck[OR][INTEGER][REAL]    = T_INVALID;

	typeTableCheck[OR][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[OR][REAL][INTEGER] = T_INVALID;
	typeTableCheck[OR][REAL][REAL]    = T_INVALID;

	// =
	typeTableCheck[EQ][BOOLEAN][BOOLEAN] = T_BOOLEAN;
	typeTableCheck[EQ][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[EQ][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[EQ][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[EQ][INTEGER][INTEGER] = T_BOOLEAN;
	typeTableCheck[EQ][INTEGER][REAL]    = T_BOOLEAN;

	typeTableCheck[EQ][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[EQ][REAL][INTEGER] = T_BOOLEAN;
	typeTableCheck[EQ][REAL][REAL]    = T_BOOLEAN;

	// <
	typeTableCheck[LT][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[LT][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[LT][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[LT][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[LT][INTEGER][INTEGER] = T_BOOLEAN;
	typeTableCheck[LT][INTEGER][REAL]    = T_BOOLEAN;

	typeTableCheck[LT][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[LT][REAL][INTEGER] = T_BOOLEAN;
	typeTableCheck[LT][REAL][REAL]    = T_BOOLEAN;

	// <=
	typeTableCheck[LE][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[LE][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[LE][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[LE][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[LE][INTEGER][INTEGER] = T_BOOLEAN;
	typeTableCheck[LE][INTEGER][REAL]    = T_BOOLEAN;

	typeTableCheck[LE][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[LE][REAL][INTEGER] = T_BOOLEAN;
	typeTableCheck[LE][REAL][REAL]    = T_BOOLEAN;

	// >
	typeTableCheck[GT][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[GT][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[GT][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[GT][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[GT][INTEGER][INTEGER] = T_BOOLEAN;
	typeTableCheck[GT][INTEGER][REAL]    = T_BOOLEAN;

	typeTableCheck[GT][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[GT][REAL][INTEGER] = T_BOOLEAN;
	typeTableCheck[GT][REAL][REAL]    = T_BOOLEAN;

	// >=
	typeTableCheck[GE][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[GE][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[GE][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[GE][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[GE][INTEGER][INTEGER] = T_BOOLEAN;
	typeTableCheck[GE][INTEGER][REAL]    = T_BOOLEAN;

	typeTableCheck[GE][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[GE][REAL][INTEGER] = T_BOOLEAN;
	typeTableCheck[GE][REAL][REAL]    = T_BOOLEAN;

	// <>
	typeTableCheck[DIFF][BOOLEAN][BOOLEAN] = T_INVALID;
	typeTableCheck[DIFF][BOOLEAN][INTEGER] = T_INVALID;
	typeTableCheck[DIFF][BOOLEAN][REAL]    = T_INVALID;

	typeTableCheck[DIFF][INTEGER][BOOLEAN] = T_INVALID;
	typeTableCheck[DIFF][INTEGER][INTEGER] = T_BOOLEAN;
	typeTableCheck[DIFF][INTEGER][REAL]    = T_BOOLEAN;

	typeTableCheck[DIFF][REAL][BOOLEAN] = T_INVALID;
	typeTableCheck[DIFF][REAL][INTEGER] = T_BOOLEAN;
	typeTableCheck[DIFF][REAL][REAL]    = T_BOOLEAN;

	typeCompatibility = (int*) malloc(3*sizeof(int));

	for ( i = 0 ; i < 3 ; i++ )
	{
		typeCompatibility[i] = (int) malloc(3*sizeof(int));
	}

	typeCompatibility[INTEGER][INTEGER] = 1;
	typeCompatibility[INTEGER][REAL] = 1;
	typeCompatibility[INTEGER][BOOLEAN] = 0;
	typeCompatibility[REAL][INTEGER] = 1;
	typeCompatibility[REAL][REAL] = 1;
	typeCompatibility[REAL][BOOLEAN] = 0;
	typeCompatibility[BOOLEAN][INTEGER] = 0;
	typeCompatibility[BOOLEAN][REAL] = 0;
	typeCompatibility[BOOLEAN][BOOLEAN] = 0;
}

/** Desaloca mem�ria das tabelas de checagem de tipo */
void clearTypeTables()
{
	int i, j;

	for ( i = 0 ; i < 15 ; i++ )
	{
		free(hashOperators[i]);
	}

	for ( i = 0 ; i < 15 ; i++ )
	{
		for ( j = 0 ; j < 3 ; j++ )
		{
			free(typeTableCheck[i][j]);
		}

		free(typeTableCheck[i]);
	}

	for ( i = 0 ; i < 3 ; i++ )
	{
		free(typeCompatibleTable[i]);
	}

	for ( i = 0 ; i < 3 ; i++ )
	{
		free(hashTypes[i]);
	}
}

/** Dados dois operandos de tipos pType1 e pType2 e, uma opera��o retorna, verificando na tabela relacional de
  * Tipos - Opera��es o tipo do resultado obtido pela opera��o, caso poss�vel, ou retornando inv�lido caso n�o
  * seja poss�vel.
  *
  * <p> pType1 - tipo do operando 1
  * <p> pType2 - tipo do operando 2
  * <p> pOperation - opera��o
  *
  * <r> T_(INTEGER | REAL | BOOLEAN ) - tipo do reusltado da opera��o caso seja uma opera��o v�lida para os
  * tipos de operandos pType1 e pType2 passados
  * <r> T_INVALID - n�o seja uma opera��o v�lida
 **/
int getExpressionReturnType(int pType1, int pType2, int pOperation)
{
	return typeTableCheck[getOperation(pOperation)][getType(pType1)][getType(pType2)];
}

int checkCompatibility(int pType1, int pType2)
{
	return typeCompatibleTable[getType(pType1)][getType(pType2)];
}

int getType(int pType)
{
	int i, g;

	for ( i = 0 ; i < 3 ; i++ )
	{
		if ( pType == hashTypes[i][0] )
		{
			return hashTypes[i][1];
			break;
		}
	}

	return 0;
}

int getOperation(int pOperation)
{
	int i, g;

	for ( i = 0 ; i < 15 ; i++ )
	{
		if ( pOperation == hashOperators[i][0] )
		{
			return hashOperators[i][1];
		}
	}

	return 0;
}

/** Verify if types are compatibles */
int isCompatibility(int pType1, int pType2)
{
	return typeCompatibility[getType(pType1)][getType(pType2)];
}
