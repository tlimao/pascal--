/*
 * type_check.h
 *
 *  Created on: 25/10/2013
 *      Author: Thiago
 */

#ifndef TYPE_CHECK_H
#define TYPE_CHECK_H

typedef enum { PLUS, MINUS, TIMES, DIVIDE, DIV, MOD, NOT, AND, OR, EQ, LT, LE, GT, GE, DIFF } operatorion;

static int** hashOperators;

typedef enum { BOOLEAN, INTEGER, REAL} typeidx;

static int** hashTypes;

static int** typeCompatibility;

typedef struct expression
{
	int operation;
	int type;
}expression;

static int*** typeTableCheck;

static int** typeCompatibleTable;

/** Cria a tabela com todas as opera��es e suas possibilidades de opera��es
  * Opera��es: + - * / mod div not and or = <> < <= > >=
  *
  * Id�ia: Matriz tridimensional (i,j,k), em que cada dimens�o i representa
  * uma opera��o (operation) e as dimens�es j e k representam os tipos. Por
  * exemplo, numa dimens�o i ter�amos:
  *
  * operation| boolean | integer | real
  *  boolean |	  -    |    -    |  -
  *  integer |    -    |    -    |  -
  *  	real |    -	   |    -    |  -
  *
  * Rela��o Opera��o - Dimens�o i adotada ( Tal como no enum operation )
  *  + :  0
  *  - :  1
  *  * :  2
  *  / :  3
  * div:  4
  * mod:  5
  * not:  6
  * and:  7
  *  or:  8
  *  = :  9
  *  < : 10
  * <= : 11
  *  > : 12
  * >= : 13
  * <> : 14
  */
void createTypeTable();

/** Desaloca mem�ria das tabelas de checagem de tipo */
void clearTypeTables();

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
int getExpressionReturnType(int pType1, int pType2, int pOperation);

/** Verify if types are compatibles */
int isCompatibility(int pType1, int pType2);

#endif /* TYPE_CHECK_H */
