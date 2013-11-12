/*
 * bison_adaptee.c
 *
 *  Created on: 06/09/2013
 *      Author: Thiago
 */
#include "bison_adaptee.h"

/** Função que irá chamar a nextToken */
int yylex(void)
{
	if( yyBuffer->chars == NULL )
		return T_INVALID;

	token* lToken = nextToken();

	// Fim de Arquivo
	if( lToken->tk_1 == T_EOF )
	{
		return 0;
	}

	// Token para Identificadores
	if( lToken->tk_1 == T_ID )
	{
		addIdToken(lToken);

		strcpy( yylval.tk_name, lToken->tk_name );
		yylval.tk_1 = lToken->tk_1;
		yylval.tk_idx = lToken->tk_idx;
	}

	// Token Int Const
	else if( lToken->tk_1 == T_INT_CONST )
	{
		strcpy( yylval.tk_name, lToken->tk_name );
		yylval.tk_1 = lToken->tk_1;
		yylval.tk_int = lToken->tk_int;
	}

	// Token Real Const
	else if( lToken->tk_1 == T_REAL_CONST )
	{
		strcpy( yylval.tk_name, lToken->tk_name );
		yylval.tk_1 = lToken->tk_1;
		yylval.tk_real = lToken->tk_real;
	}

	// Token Boolean Const
	else if( lToken->tk_1 == T_BOOLEAN_CONST )
	{
		strcpy( yylval.tk_name, lToken->tk_name );
		yylval.tk_1 = lToken->tk_1;

		// True
		if( lToken->tk_bool == 1 )
		{
			yylval.tk_bool = 1;
		}

		// False
		else
		{
			yylval.tk_bool = 0;
		}
	}

	// Demais Tokens
	else
	{
		strcpy( yylval.tk_name, lToken->tk_name );
		yylval.tk_1 = lToken->tk_1;
	}

	return lToken->tk_1;
}


/** Função que imprime a linha onde ocorreu o erro */
int yyerror(char* a)
{
	printf("Erro na linha %i\n", getLine());
	return 0;
}

