/*
 * buffer.h
 *
 *  Created on: 14/08/2013
 *      Author: Thiago
 */

#ifndef BUFFER_H
#define BUFFER_H

#define BUFFER_MAX_LENGHT 999999

#include <stdio.h>
#include <ctype.h>

/** Buffer OO para armazenar cada linha da fonte de dados evitando carregar toda fonte de dados de uma só vez */
typedef struct buffer
{
    char* chars;
    int   size;
    int   idx;
}buffer;

/** Buffer global utilizado em nosso compilador */
buffer* yyBuffer;

/** Devolve uma instância de buffer */
void buildBuffer();

/** informa a origem dos dados aquivo ou inputstream */
void setBufferSource(FILE* pSrc);

/** Limpa o buffer */
void clearBuffer();

/** Imprime os Caracteres que estão no buffer */
void printBuffer();

/** Retorna o char para o qual o buffer está apontando atualmente */
char getChar();

/** Retorna o char para o qual o buffer está apontando atualmente e avança o ponteiro para o próximo char */
char nextChar();

/** Retorna o próximo char do buffer */
char lookNextChar();

/** Retorna o último char lido do buffer */
char lookPreviewChar();

/** Avança uma posição do buffer */
void goFront();

/** Retorna uma posição do buffer */
void goBack();

/** Verifica se ainda há algum char no buffer */
int hasNext();

/** Calcula em que linha do arquivo o buufer está */
int getLine();

/** Retorna o próximo char do buffer */
char lookNextChar();

/** Retorna o último char lido do buffer */
char lookPreviewChar();

/** Avança uma posição do buffer */
void goFront();

/** Retorna uma posição do buffer */
void goBack();

/** Verifica se ainda há algum char no buffer */
int hasNext();

#endif

