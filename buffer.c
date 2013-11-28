/*
 * buffer.c
 *
 *  Created on: 14/08/2013
 *      Author: Thiago
 */

#include "buffer.h"

/** Devolve ua referência do buffer global do compilador */
void buildBuffer()
{
	yyBuffer = (buffer*) malloc(sizeof(buffer));

	yyBuffer->chars = (char*) malloc(BUFFER_MAX_LENGHT);
	yyBuffer->idx = 0;
	yyBuffer->size = 0;
}

/** Preenche o buffer com o arquivo */
void setBufferSource(FILE* pSrc)
{
	char c;

	while (( c = fgetc(pSrc)) != EOF )
	{
		yyBuffer->chars[yyBuffer->size++] = tolower(c);
	}

	if ( feof(pSrc) && yyBuffer->size > 0 )
	{
		yyBuffer->chars[yyBuffer->size++] = c;
	}

	else if ( feof(pSrc) && yyBuffer->size == 0 )
	{
		yyBuffer->chars[yyBuffer->size++] = c;
	}

	fclose(pSrc);
}

/** Limpa o buffer */
void clearBuffer()
{
    free(yyBuffer->chars);
    yyBuffer->idx = 0;
    yyBuffer->size = 0;
}

/** Imprime os Caracteres que estão no buffer */
void printBuffer()
{
	int i;

	for ( i = 0 ; i < yyBuffer->size ; i++ )
		printf("%c", yyBuffer->chars[i]);
}

/** Pula espa�os e tabulações e quebras de linha até a ocorrência do primeiro caractere */
void skipSeparators()
{
	char c = getChar();

	while ( c == ' ' || c == '\t' || c == '\n' )
	{
		yyBuffer->idx++;
		c = getChar();
	}
}

/** Retorna o char para o qual o buffer está apontando atualmente */
char getChar()
{
	return yyBuffer->chars[yyBuffer->idx];
}

/** Retorna o char para o qual o buffer está apontando atualmente e avança o ponteiro para o próximo char */
char nextChar()
{
	char c = yyBuffer->chars[yyBuffer->idx];

	if ( yyBuffer->idx + 1 < yyBuffer->size )
		yyBuffer->idx++;

	return c;
}

/** Retorna o próximo char do buffer */
char lookNextChar()
{
	return yyBuffer->chars[yyBuffer->idx];
}

/** Retorna o último char lido do buffer */
char lookPreviewChar()
{
	return yyBuffer->chars[yyBuffer->idx - 1];
}

/** Avan�a uma posição do buffer */
void goFront()
{
	yyBuffer->idx++;
}

/** Retorna uma posição do buffer */
void goBack()
{
	yyBuffer->idx--;
}

/** Verifica se ainda há algum char no buffer */
int hasNext()
{
	return ( yyBuffer->idx + 1 < yyBuffer->size ) ? 1 : 0;
}

/** Calcula em que linha do arquivo o buufer está */
int getLine()
{
	int i, l = 1;

	for ( i = 0 ; i < yyBuffer->idx ; i++ )
	{
		if ( yyBuffer->chars[i] == '\n' )
			l++;

	}

	return l;
}
