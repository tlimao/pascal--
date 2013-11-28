/*
 * code_generator.h
 *
 *  Created on: 15/11/2013
 *      Author: Thiago
 */

#ifndef CODE_GENERATOR_H
#define CODE_GENERATOR_H

#include <stdio.h>
#include "scope_structure.h"
#include "string.h"

/** Estrutura para armazenar blocos de código até que sejam colocados no arquivo de código */
typedef struct codeblock
{
	char* code;
}codeblock;

/** Strutura de Label para pilha */
typedef struct label
{
	int label_id;
}label;

/** Nó para pilha de labels */
typedef struct labelNoh
{
	label* label;
	struct labelNoh* next_label;
}labelNoh;

static labelNoh* stack_label = NULL;

typedef struct codegenerator
{
	void (*build_program) (int pId, codeblock* pProgram);
	struct codeblock* (*build_block_body) (codeblock* pBlk1, codeblock* pBlk2, codeblock* pBlk3, codeblock* pBlk4);
	struct codeblock* (*constant_declare) (struct symbol* pSymbol);
	struct codeblock* (*variable_declare) (struct paramList* pList);
	void (*procedure_declare) (struct symbol* pSymbol);
	struct codeblock* (*build_procedure) (struct symbol* pSymbol);
	struct codeblock* (*build_assignment) (struct symbol* pSymbol, struct expression pExpression);
	struct codeblock* (*call_procedure_void) (struct symbol* pSymbol);
	struct codeblock* (*call_procedure) (struct symbol* pSymbol, struct codeblock* pBlk);
	struct codeblock* (*if_statement) (struct expression pExpression, struct codeblock* pBlk);
	struct codeblock* (*if_else_statement) (struct expression pExpression, struct codeblock* pIfBlk, struct codeblock* pElseBlk);
	struct codeblock* (*while_statement) (struct expression pExpression, struct codeblock* pBlk);
	struct codeblock* (*build_relational_expression) (struct expression pExp1, struct expression pExp2, int pOperator);
	struct codeblock* (*build_sign_expression) (struct expression pExp1, struct expression pExp2, int pOperator);
	struct codeblock* (*build_single_sign_expression) (struct expression pExp1, int pOperator);
	struct codeblock* (*build_expression) (struct expression pExp1, struct expression pExp2);
	struct codeblock* (*build_not_expression) (struct expression pExpression);
	struct codeblock* (*use_int_const) (int pInt);
	struct codeblock* (*use_real_const) (float pReal);
	struct codeblock* (*use_boolean_const) (int pBoolean);
	struct codeblock* (*get_variable_access) (struct symbol* pSymbol);
}codegenerator;

/** Gerador de código */
codegenerator codegen;

/** Referência para o arquivo onde o código gerado será salvo */
FILE* asm_file;

/**  Contador para Procedimentos */
static int procedure_count = 1;

/** Contador de Labels */
static int label_count;

/** Retorna uma instância de bloco de código de tamanho pSize */
codeblock* codeBlockFactory(int pSize);

/** Imprime o bloco de código */
void printCodeBlock(codeblock* pBlock);

/** Retorna uma instância de label */
label* labelFactory();

/** Retorna uma instância de nó para pilha de labels */
labelNoh* labelNohFactory();

/** Coloca uma nova label na pilha de labels */
void pushLabel(label* pLabel);

/** Libera última label retornando-a */
label* popLabel();

/** Concatena dois blocos de código
 * <p> pBlock1 e pBlock2 - blocos de código que serão concatenados
 * <r> rBlock - bloco resultante da concatenação
 **/
codeblock* codeBlockCat(codeblock* pBlock1, codeblock* pBlock2);

/** Converte uma string num codeBlock */
codeblock* stringToCodeBlock(char* pString);

/** Converte um codeBlock num string */
char* codeBlockToString(codeblock* pCodeBlock);

/** Inicializa o arquivo que irá armazenar o código gerado */
void initCodeFile(void);

/** Finaliza a geração de código fechando o arquivo onde está o código gerado */
void finalizeCodeFile(void);

#endif /* CODE_GENERATOR_H */
