/*
 * code_generator.c
 *
 *  Created on: 15/11/2013
 *      Author: Thiago
 */
#include "code_generator.h"
#include "malloc.h"
#include "strings.h"

/** Retorna uma instância de bloco de código de tamanho pSize */
codeblock* codeBlockFactory(int pSize)
{
	codeblock* fragment = (codeblock*) malloc(sizeof(codeblock));

	fragment->code = (char*) malloc(pSize*sizeof(char*));

	strcpy(fragment->code, "");

	return fragment;
}

/** Imprime o bloco de código */
void printCodeBlock(codeblock* pBlock)
{
	printf("%s\n", pBlock->code);
}

/** Retorna uma instância de label */
label* labelFactory()
{
	label* new_label = (label*) malloc(sizeof(label));

	new_label->label_id = label_count++;

	return new_label;
}

/** Retorna uma instância de nó para pilha de labels */
labelNoh* labelNohFactory()
{
	labelNoh* new_noh = (labelNoh*) malloc(sizeof(labelNoh));

	return new_noh;
}

/** Coloca uma nova label na pilha de labels */
void pushLabel(label* pLabel)
{
	if ( stack_label == NULL )
	{
		stack_label = labelNohFactory();

		stack_label->label = pLabel;

		stack_label->next_label = NULL;
	}

	else
	{
		labelNoh* new_label_no = labelNohFactory();

		new_label_no->label = pLabel;

		new_label_no->next_label = stack_label;

		stack_label = new_label_no;
	}
}

/** Libera última label retornando-a */
label* popLabel()
{
	if ( stack_label != NULL )
	{
		label* label = stack_label->label;

		stack_label = stack_label->next_label;

		return label;
	}

	else
	{
		return NULL;
	}
}

/** Concatena dois blocos de código
 * <p> pBlock1 e pBlock2 - blocos de código que serão concatenados
 * <r> rBlock - bloco resultante da concatenação
 **/
codeblock* codeBlockCat(codeblock* pBlock1, codeblock* pBlock2)
{
	int size = strlen(pBlock1->code) + strlen(pBlock2->code);

	codeblock* fragment = codeBlockFactory(size);

	strcpy(fragment->code, pBlock1->code);

	strcat(fragment->code, pBlock2->code);

	return fragment;
}

/** Converte uma string num codeBlock */
codeblock* stringToCodeBlock(char* pString)
{
	codeblock* block = codeBlockFactory(strlen(pString));

	strcpy(block->code, pString);

	return block;
}

/** Converte um codeBlock num string */
char* codeBlockToString(codeblock* pCodeBlock)
{
	char* string = (char*) malloc(strlen(pCodeBlock->code));

	strcpy(string, pCodeBlock->code);

	return string;
}

/** Inicializa o arquivo que irá armazenar o código gerado */
void initCodeFile(void)
{
	asm_file = fopen("code.asm","w");

	fprintf(asm_file, "%s", "-- Pascalmm Ver. 1.0\n\n");
}

/** Finaliza a geração de código fechando o arquivo onde está o código gerado */
void finalizeCodeFile(void)
{
	fprintf(asm_file, "%s", "\n-- end");

	fclose(asm_file);

	printf("Codigo gerado com sucesso! [code.asm]\n");
}
