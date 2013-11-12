/*
 * tokens.c
 *
 *  Created on: 16/08/2013
 *      Author: Thiago
 */
#include "tokens.h"

/** Retorna uma inst�ncia de token */
token* factoryToken()
{
	token* new_token = (token*) malloc(sizeof(token));

	strcpy(new_token->tk_name,"");
	new_token->tk_int  = -1;
	new_token->tk_real = -1;

	return new_token;
}

/** Incrementa  tk2_count */
int incTk2Count()
{
	return tk2_count++;
}

/** Imprime a lista de tokens com tokens secund�rios */
void printToken2List()
{
	token2List* lToken;
	for ( lToken = tk2_list ; lToken != NULL ; lToken = lToken->tk_prox )
	{
		printToken(lToken->tk);
	}
}

/** Adiciona o novo id na lista de token identificadores */
void addIdToken(token* pToken)
{
	token2List* lToken;

	if ( tk2_list == NULL )
	{
		token2List* new_tk = (token2List*) malloc(sizeof(token2List));
		new_tk->tk = pToken;
		pToken->tk_idx = incTk2Count();
		new_tk->tk_prox = NULL;
		tk2_list = new_tk;
	}

	else
	{
		for ( lToken = tk2_list ; lToken != NULL ; lToken = lToken->tk_prox )
		{
			if ( strcmp(lToken->tk->tk_name, pToken->tk_name) == 0 )
			{
				pToken->tk_idx = lToken->tk->tk_idx;
				break;
			}
		}

		if ( lToken == NULL )
		{
			token2List* new_tk = (token2List*) malloc(sizeof(token2List));
			new_tk->tk = pToken;
			pToken->tk_idx = incTk2Count();
			new_tk->tk_prox = tk2_list;

			tk2_list = new_tk;
		}
	}
}

/** Imprime o Token */
void printToken(token* pToken)
{
	if ( pToken->tk_1 == 2 )
		printf("%s \n Token 1: %i \n Token 2: %i\n", pToken->tk_name, pToken->tk_1, pToken->tk_int);

	else if ( pToken->tk_1 == 3 )
		printf("%s \n Token 1: %i \n Token 2: %f\n", pToken->tk_name, pToken->tk_1, pToken->tk_real);

	else if ( pToken->tk_1 == 4 )
	{
		if ( pToken->tk_bool == 1 )
			printf("%s \n Token 1: %i \n Token 2: true\n", pToken->tk_name, pToken->tk_1);
		else
			printf("%s \n Token 1: %i \n Token 2: false\n", pToken->tk_name, pToken->tk_1);
	}

	else if ( pToken->tk_1 == 1 )
	{
		printf("%s \n Token 1: %i \n Token 2: %i\n", pToken->tk_name, pToken->tk_1, pToken->tk_idx);
	}

	else
		printf("%s \n Token 1: %i\n", pToken->tk_name, pToken->tk_1);

}

/** Busca um token baseado em seu id de token secund�rio na lista token2List */
token* getToken(int pId)
{
	token2List* lToken;

	for ( lToken = tk2_list ; lToken != NULL ; lToken = lToken->tk_prox )
	{
		if ( lToken->tk->tk_idx == pId )
		{
			return lToken->tk;
			break;
		}
	}

	return NULL;
}

/** Verifica se o char � um digito */
int isDigit(char pChar)
{
	return ( pChar > 47 && pChar < 58 ) ? 1 : 0;
}

/** Verifica se o char � um caractere */
int isAlpha(char pChar)
{
	return ( pChar > 96 && pChar < 123 ) ? 1 : 0;
}

/** Verifica se o char � um underline */
int isUnderline(char pChar)
{
	return ( pChar == '_' ) ? 1 : 0;
}

/** Verifica se o char � um separador "espa�o" ou "tab" */
int isSeparator(char pChar)
{
	return ( pChar == ' ' || pChar == '\t' || pChar == '\n' ) ? 1 : 0;
}

/** Verifica se o char � uma marca��o de fim de arquivo */
int isEOF(char pChar)
{
	return ( pChar == EOF ) ? 1 : 0;
}

/** Verifica se ochar � um operador + - * / */
int isOperator(char pChar)
{
	if ( pChar == '+' || pChar == '-' || pChar == '*' || pChar == '/' )
		return 1;
	else
		return 0;
}

/** Verifica se o token � uma palavra reservada */
void classifyToken(token* pToken)
{
	if ( strcmp(pToken->tk_name, "true") == 0 || strcmp(pToken->tk_name, "false") == 0 )
	{
		pToken->tk_1 = T_BOOLEAN_CONST;
		pToken->tk_bool = (strcmp(pToken->tk_name, "true") == 0 ) ? 1 : 0;
		strcpy(pToken->tk_name,"boolean const");
	}

	else if ( strcmp(pToken->tk_name, "program") == 0 )
		pToken->tk_1 = T_PROGRAM;

	else if ( strcmp(pToken->tk_name, "procedure") == 0 )
		pToken->tk_1 = T_PROCEDURE;

	else if ( strcmp(pToken->tk_name, "begin") == 0 )
		pToken->tk_1 = T_BEGIN;

	else if ( strcmp(pToken->tk_name, "end") == 0 )
		pToken->tk_1 = T_END;

	else if ( strcmp(pToken->tk_name, "if") == 0 )
		pToken->tk_1 = T_IF;

	else if ( strcmp(pToken->tk_name, "then") == 0 )
		pToken->tk_1 = T_THEN;

	else if ( strcmp(pToken->tk_name, "else") == 0 )
		pToken->tk_1 = T_ELSE;

	else if ( strcmp(pToken->tk_name, "while") == 0 )
		pToken->tk_1 = T_WHILE;

	else if ( strcmp(pToken->tk_name, "do") == 0 )
		pToken->tk_1 = T_DO;

	else if ( strcmp(pToken->tk_name, "div") == 0 )
		pToken->tk_1 = T_DIV;

	else if ( strcmp(pToken->tk_name, "mod") == 0 )
		pToken->tk_1 = T_MOD;

	else if ( strcmp(pToken->tk_name, "and") == 0 )
		pToken->tk_1 = T_AND;

	else if ( strcmp(pToken->tk_name, "or") == 0 )
		pToken->tk_1 = T_OR;

	else if ( strcmp(pToken->tk_name, "not") == 0 )
		pToken->tk_1 = T_NOT;

	else if ( strcmp(pToken->tk_name, "var") == 0 )
		pToken->tk_1 = T_VAR;

	else if ( strcmp(pToken->tk_name, "integer") == 0 )
		pToken->tk_1 = T_INTEGER;

	else if ( strcmp(pToken->tk_name, "real") == 0 )
		pToken->tk_1 = T_REAL;

	else if ( strcmp(pToken->tk_name, "boolean") == 0 )
		pToken->tk_1 = T_BOOLEAN;

	else if ( strcmp(pToken->tk_name, "const") == 0 )
		pToken->tk_1 = T_CONST;

	else if ( strcmp(pToken->tk_name, "until") == 0 )
		pToken->tk_1 = T_UNTIL;

	else
	{
		pToken->tk_1 = T_ID;
	}
}

/** Fun��o que retorna os tokens identificados nos dados fornecidos */
token* nextToken()
{
	token* lToken = factoryToken();

	// Ignora os espa�os e tabula��es
	skipSeparators();

	char* c = nextChar();

	// Fim de arquivo
	if ( c == EOF )
	{
		strcpy(lToken->tk_name, "EOF");
		lToken->tk_1 = T_EOF;
		return lToken;
	}

	// Alfanum�ricos
	else if ( isAlpha(c) || isUnderline(c) )
	{
		while ( ( isAlpha(c) || isUnderline(c) || isDigit(c) ) && !isEOF(c) )
		{
			strcat(lToken->tk_name, &c);

			char next = getChar();

			if ( isAlpha(next) || isUnderline(next) || isDigit(next) )
				c = nextChar();

			else
				break;
		}

		classifyToken(lToken);

		return lToken;
	}

	// Ponto, Inteiros e Reais
	else if ( isDigit(c) || c == '.' )
	{
		// Reconhece Ponto
		if ( !isDigit(getChar()) && !isDigit(lookPreviewChar()) )
		{
			strcpy(lToken->tk_name, "Period");
			lToken->tk_1 = T_PERIOD;
			return lToken;
		}

		// N�meros Inteiros e Reais
		else
		{
			return isNumber();
		}
	}

	// Comet�rios
	else if ( c == '{' )
	{
		while ( c != '}' && c != EOF )
		{
			c = nextChar();
		}

		if ( c == '}' )
		{
			// Salta Coment�rio
			return nextToken();
		}

		else
		{
			strcpy(lToken->tk_name, "Token Inv�lido");
			lToken->tk_1 = T_INVALID;
			return lToken;
		}
	}

	// Parenteses e Coment�rio
	else if ( c == '(' )
	{
		char* aux = lookNextChar();

		// Coment�rio
		if ( aux == '*' )
		{
			goFront();
			c = nextChar();
			aux = lookNextChar();

			while ( ( c != '*' || aux != ')' ) && aux != EOF )
			{
				c = nextChar();
				aux = getChar();
			}

			if ( c == '*' && aux == ')' )
			{
				yyBuffer->idx++;
				// Salta Coment�rio
				return nextToken();
			}

			else
			{
				strcpy(lToken->tk_name, "Token Inv�lido");
				lToken->tk_1 = T_INVALID;

				return lToken;
			}
		}

		// Abre parenteses
		else
		{
			strcpy(lToken->tk_name, "Left Bracket");
			lToken->tk_1 = T_LBRACKET;

			return lToken;
		}
	}

	// Fecha parenteses
	else if ( c == ')' )
	{
		strcpy(lToken->tk_name, "Right Bracket");
		lToken->tk_1 = T_RBRACKET;
		return lToken;
	}

	// Igual
	if ( c == '=' )
	{
		strcpy(lToken->tk_name, "Equal");
		lToken->tk_1 = T_EQ;
		return lToken;
	}

	// Menor e Menor ou Igual
	if ( c == '<' )
	{
		if ( lookNextChar() == '=' )
		{
			c = nextChar();
			strcpy(lToken->tk_name, "Less Equal");
			lToken->tk_1 = T_LEQ;
		}

		else if ( lookNextChar() == '>' )
		{
			c = nextChar();
			strcpy(lToken->tk_name, "Diff");
			lToken->tk_1 = T_DIF;
		}

		else
		{
			strcpy(lToken->tk_name, "Less Then");
			lToken->tk_1 = T_LT;
		}

		return lToken;
	}

	// Maior e Maior ou Igual
	if ( c == '>' )
	{
		if ( lookNextChar() == '=' )
		{
			c = nextChar();
			strcpy(lToken->tk_name, "Greater Equal");
			lToken->tk_1 = T_GEQ;
		}

		else
		{
			strcpy(lToken->tk_name, "Greater Then");
			lToken->tk_1 = T_GT;
		}

		return lToken;
	}

	// Assign
	if ( c == ':' )
	{
		if ( lookNextChar() == '=' )
		{
			c = nextChar();
			strcpy(lToken->tk_name, "Assign");
			lToken->tk_1 = T_ASSIGN;
		}

		else
		{
			strcpy(lToken->tk_name, "Colon");
			lToken->tk_1 = T_COLON;
		}

		return lToken;
	}

	// Ponto e v�rgula
	if ( c == ';' )
	{
		strcpy(lToken->tk_name, "Semicolon");
		lToken->tk_1 = T_SEMICOLON;
		return lToken;
	}

	// V�rgula
	if ( c == ',' )
	{
		strcpy(lToken->tk_name, "Comma");
		lToken->tk_1 = T_COMMA;
		return lToken;
	}

	// Soma
	else if ( c == '+' )
	{
		if ( lookNextChar() == '=' )
		{
			c = nextChar();
			strcpy(lToken->tk_name, "Plus Equal");
			lToken->tk_1 = T_PLUS_EQ;
		}

		else
		{
			strcpy(lToken->tk_name, "Plus");
			lToken->tk_1 = T_PLUS;
		}

		return lToken;
	}

	// Subtra��o
	else if ( c == '-' )
	{
		if ( lookNextChar() == '=' )
		{
			c = nextChar();
			strcpy(lToken->tk_name, "Minus Equal");
			lToken->tk_1 = T_MINUS_EQ;
		}

		else
		{
			strcpy(lToken->tk_name, "Minus");
			lToken->tk_1 = T_MINUS;
		}

		return lToken;
	}

	// Produto
	else if ( c == '*' )
	{
		if ( lookNextChar() == '=' )
		{
			c = nextChar();
			strcpy(lToken->tk_name, "Times Equal");
			lToken->tk_1 = T_TIMES_EQ;
		}

		else
		{
			strcpy(lToken->tk_name, "Times");
			lToken->tk_1 = T_TIMES;
		}

		return lToken;
	}

	// Divis�o
	else if ( c == '/' )
	{
		if ( lookNextChar() == '=' )
		{
			c = nextChar();
			strcpy(lToken->tk_name, "Divide Equal");
			lToken->tk_1 = T_TIMES_EQ;
		}

		else
		{
			strcpy(lToken->tk_name, "Divide");
			lToken->tk_1 = T_TIMES;
		}

		return lToken;
	}

	// Tokens inv�lidos
	else
	{
		strcpy(lToken->tk_name, "Token Inv�lido");
		lToken->tk_1 = T_INVALID;
		return lToken;
	}
}

/** Verifica se o token � um n�mero int const ou real const */
token* isNumber()
{
	token* lToken = factoryToken();
	char c = lookPreviewChar();
	float v = 0;
	int exp1 = 0, exp2 = 0;
	int is_num = 0;
	int is_exp = 1;
	int is_real = 0;
	int signal = 1;

	while ( ( isDigit(c) || c == '.' ) && !isEOF(c) )
	{
		// Flag indicando que � um ponto flutuante
		if ( c == '.' )
		{
			is_real = 1;
		}

		else
		{
			v = v*10 + (int) c - (int) '0';
			// Em caso de ser ponto flutuante, o expoente � incrementado
			exp1 += ( is_real ) ? 1 : 0;
			is_num = 1;
		}

		c = nextChar();
	}

	if ( c == 'e' )
	{
		c = nextChar();

		if ( c == '-' )
		{
			signal = 0;
			c = nextChar();
		}

		else if ( c == '+' )
		{
			signal = 1;
			c = nextChar();
		}

		if ( isDigit(c) && !isEOF(c) )
		{
			while ( isDigit(c) && !isEOF(c) )
			{
				exp2 = exp2*10 + (int) c - (int) '0';

				if ( isDigit(lookNextChar()) )
					c = nextChar();
				else
					break;
			}

			exp2 = ( signal == 0 ) ? -exp2 : exp2;
		}

		else
			is_exp = 0;
	}

	if ( isOperator(c) || c == ';' || c == ','  )
	{
		goBack();
	}

	// Caso o pr�ximo char do buffer seja um alfanum�rico � identificado um erro
	if ( !isAlpha(c) && is_exp && is_num )
	{
		if ( !is_real )
		{
			strcpy(lToken->tk_name, "Int Const");
			lToken->tk_1 = T_INT_CONST;
			lToken->tk_int = v*powf(10, exp2);
		}

		else
		{
			strcpy(lToken->tk_name, "Real Const");
			lToken->tk_1 = T_REAL_CONST;
			lToken->tk_real = ( v / powf(10,exp1) )*powf(10, exp2);
		}
	}

	else
	{
		while ( !isSeparator(c) && lookNextChar() != ';' )
		{
			c = nextChar();
		}

		strcpy(lToken->tk_name, "Token Inv�lido");
		lToken->tk_1 = T_INVALID;
	}

	return lToken;
}
