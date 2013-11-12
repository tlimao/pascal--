/*
 * main.c
 *
 *  Created on: 14/08/2013
 *      Author: Thiago
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tokens.h"
#include "conio.h"
#include "type_check.h"

extern int yyparse(void);

extern int yydebug;

int main(int argc, char** argv)
{
	system("cls");

	int i;
	int sh_token = 0;
	char file[32];

	yydebug = 0;

	if ( argc == 1 )
	{
		printf("HELP:\nCPascal-- [-d] [-t] [filename]\n[-d]: debug mode\n[-t]: tokenizer mode\n[file]: File Name\n");
		return 0;
	}

	for ( i = 1 ; i < argc ; i++ )
	{
		if ( strcmp("-d", argv[i]) == 0 )
			yydebug = 1;

		else if ( strcmp("-t", argv[i]) == 0 )
			sh_token = 1;

		else
		{
			strcpy(file, argv[i]);
			FILE* fp = fopen(file,"r");

			if ( fp == NULL )
			{
				printf("HELP:\nCPascal-- [-d] [-t] [filename]\n[-d]: debug mode\n[-t]: tokenizer mode\n[file]: File Name\n");
				return 0;
			}
		}
	}

	buildBuffer();
	token* la_token = factoryToken();

	FILE* fp = fopen(file,"r");

	setBufferSource(fp);

	if ( sh_token )
	{
		while ( hasNext() )
		{
			la_token = nextToken();
			printf("\n");
			printToken(la_token);
			system("pause");
		}

		yyBuffer->idx = 0;
	}

	if( !yyparse() )
	{
		puts("\n************************************");
		puts("Parser Completo.");
		puts("************************************");
	}

	else
	{
		puts("\n************************************");
		puts("ERRO!!!!!!");
		puts("************************************");
	}

	clearBuffer();

    return 0;
}
