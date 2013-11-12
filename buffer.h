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

/** Buffer OO para armazenar cada linha da fonte de dados evitando carregar toda fonte de dados de uma s� vez */
typedef struct buffer
{
    char* chars;
    int   size;
    int   idx;
}buffer;

/** Buffer global utilizado em nosso compilador */
buffer* yyBuffer;

/** Devolve uma inst�ncia de buffer */
void buildBuffer();

/** informa a origem dos dados aquivo ou inputstream */
void setBufferSource(FILE* pSrc);

/** Limpa o buffer */
void clearBuffer();

/** Imprime os Caracteres que est�o no buffer */
void printBuffer();

/** Retorna o char para o qual o buffer est� apontando atualmente */
char getChar();

/** Retorna o char para o qual o buffer est� apontando atualmente e avan�a o ponteiro para o pr�ximo char */
char nextChar();

/** Retorna o pr�ximo char do buffer */
char lookNextChar();

/** Retorna o �ltimo char lido do buffer */
char lookPreviewChar();

/** Avan�a uma posi��o do buffer */
void goFront();

/** Retorna uma posi��o do buffer */
void goBack();

/** Verifica se ainda h� algum char no buffer */
int hasNext();

/** Calcula em que linha do arquivo o buufer est� */
int getLine();

/** Retorna o pr�ximo char do buffer */
char lookNextChar();

/** Retorna o �ltimo char lido do buffer */
char lookPreviewChar();

/** Avan�a uma posi��o do buffer */
void goFront();

/** Retorna uma posi��o do buffer */
void goBack();

/** Verifica se ainda h� algum char no buffer */
int hasNext();

#endif

