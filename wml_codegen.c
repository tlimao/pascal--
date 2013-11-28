/*
 * wml_codegen.c
 *
 *  Created on: 16/11/2013
 *      Author: Thiago
 */
#include "wml_codegen.h"
#include "gramatica.tab.h"
#include "scope_structure.h"

/** Dado um token de uma operação em Pascal-- retorna a operação respectiva em wml */
char* wmlOperators(int pOperation)
{
	int i;

	for ( i = 0 ; i < NUM_OPERATORS ; i++ )
	{
		if ( pOperation == tokenToIndex[i] )
			break;
	}

	return wml_operators[i];
}

/** Inicializa o gerador de código e referênica todas as funções de geração de código */
void initWmlCodeGen(void)
{
	/* Linkagem das funções de geração de código do gerador de código com a plataforma wap */
	codegen.build_program 	   			 = &wml_build_program;
	codegen.build_block_body   			 = &wml_build_block_body;
	codegen.constant_declare   			 = &wml_constant_declare;
	codegen.variable_declare   			 = &wml_variable_declare;
	codegen.procedure_declare			 = &wml_procedure_declare;
	codegen.build_procedure				 = &wml_build_procedure;
	codegen.build_assignment    		 = &wml_build_assignment;
	codegen.call_procedure_void 		 = &wml_call_procedure_void;
	codegen.call_procedure      		 = &wml_call_procedure;
	codegen.if_statement				 = &wml_if_statement;
	codegen.if_else_statement   		 = &wml_if_else_statement;
	codegen.while_statement     		 = &wml_while_statement;
	codegen.build_relational_expression  = &wml_build_relational_expression;
	codegen.build_sign_expression 		 = &wml_build_sign_expression;
	codegen.build_single_sign_expression = &wml_build_single_sign_expression;
	codegen.build_expression     		 = &wml_build_expression;
	codegen.build_not_expression 		 = &wml_build_not_expression;
	codegen.use_int_const        		 = &wml_use_int_const;
	codegen.use_real_const       		 = &wml_use_real_const;
	codegen.use_boolean_const    		 = &wml_use_boolean_const;
	codegen.get_variable_access 		 = &wml_get_variable_access;
}

/** Escreve o código final do programa no arquivo de código *. asm */
void wml_build_program(int pId, struct codeblock* pProgram)
{
	codeblock* block = codeBlockFactory(LINE_SIZE);

	sprintf(block->code, "EXTERN FUNCTION MAIN 0 0 \nFUNCVARS %d\n", top_scope->num_vars);

	fprintf(asm_file, "%s", codeBlockCat(block, pProgram)->code);
}

/** Construi um bloco de programa apartir de seus subcomponentes */
struct codeblock* wml_build_block_body(struct codeblock* pBlk1, struct codeblock* pBlk2, struct codeblock* pBlk3, struct codeblock* pBlk4)
{
	return codeBlockCat(codeBlockCat(pBlk1, pBlk2), codeBlockCat(pBlk3, pBlk4));
}

/** Declaração de constante */
struct codeblock* wml_constant_declare(struct symbol* pSymbol)
{
	codeblock* block = codeBlockFactory(LINE_SIZE);

	switch ( pSymbol->type )
	{
		case T_INTEGER:
			sprintf(block->code, "CONST INT %15d\n", pSymbol->value.tk_int);
			break;

		case T_REAL:
			sprintf(block->code, "CONST REAL %14.5f\n", pSymbol->value.tk_real);
			break;

		case T_BOOLEAN:
			sprintf(block->code, "CONST BOOLEAN %11.d\n", pSymbol->value.tk_bool);
			break;
	}

	return block;
}

/** Declaração de variable */
struct codeblock* wml_variable_declare(struct paramList* pList)
{
	symbol* lSymbol = pList->parameter;

	while ( lSymbol != NULL )
	{
		lSymbol->stack_num = top_scope->num_params + top_scope->num_vars++;

		lSymbol = lSymbol->next_symbol;
	}

	return stringToCodeBlock("");
}

/** Constrói um procedure */
struct codeblock* wml_build_procedure(struct symbol* pSymbol)
{
	codeblock* block = codeBlockFactory(LINE_SIZE);

	sprintf(block->code, "EXTERN FUNCTION %s %d %d\nFUNCVARS %d\n", getToken(pSymbol->id)->tk_name
																  , pSymbol->stack_num
																  , pSymbol->param_list->length
																  , top_scope->num_vars);

	return codeBlockCat(block, pSymbol->code_fragment);
}

/** Declaração de procedimento */
void wml_procedure_declare(struct symbol* pSymbol)
{
	symbol* lSymbol = pSymbol->param_list->parameter;

	while ( lSymbol != NULL )
	{
		lSymbol->stack_num = top_scope->num_vars++;

		lSymbol = lSymbol->next_symbol;
	}
}

struct codeblock* wml_build_assignment(struct symbol* pSymbol, struct expression pExpression)
{
	codeblock* block = codeBlockFactory(strlen(pSymbol->code_fragment->code) + LINE_SIZE);

	sprintf(block->code, "%sSTORE_VAR_S %d\n", pExpression.code_fragment->code, pSymbol->stack_num);

	return block;
}

/** Chamada a procedimento sem parâmetros */
struct codeblock* wml_call_procedure_void(struct symbol* pSymbol)
{
	codeblock* block = codeBlockFactory(LINE_SIZE);

	sprintf(block->code, "CALL_S %d\n", pSymbol->stack_num);

	return block;
}

/** Chamada a procedimento com parâmetros */
struct codeblock* wml_call_procedure(struct symbol* pSymbol, struct codeblock* pBlk)
{
	codeblock* block = codeBlockFactory(strlen(pBlk->code) + LINE_SIZE);

	if ( !strcmp(getToken(pSymbol->id)->tk_name, "print") )
	{
		sprintf(block->code, "%sCALL_LIB_S 2 5\n", pBlk->code);
	}

	else
	{
		sprintf(block->code, "%sCALL_S %d\n", pBlk->code, pSymbol->stack_num);
	}

	return block;
}

/** If statement */
struct codeblock* wml_if_statement(struct expression pExpression, struct codeblock* pIfBlk)
{
	codeblock* block = codeBlockFactory( strlen(pIfBlk->code) +
										 strlen(pExpression.code_fragment->code) + LINE_SIZE);

	sprintf(block->code, "%s"
						 "TJUMP_FW_W $%d\n"
						 "%s"
						 "LABEL $%d\n", pExpression.code_fragment->code, label_count, pIfBlk->code, label_count);

	label_count++;

	return block;
}

/** If Else statement */
struct codeblock* wml_if_else_statement(struct expression pExpression, struct codeblock* pIfBlk, struct codeblock* pElseBlk)
{
	codeblock* block = codeBlockFactory( strlen(pIfBlk->code) +
										 strlen(pElseBlk->code) +
										 strlen(pExpression.code_fragment->code) + LINE_SIZE);

	sprintf(block->code, "%s"
						 "TJUMP_FW_W $%d\n"
						 "%s"
						 "JUMP_FW_W $%d\n"
						 "LABEL $%d\n"
						 "%s"
						 "LABEL $%d\n", pExpression.code_fragment->code, label_count, pIfBlk->code, label_count + 1, label_count, pElseBlk->code, label_count + 1);

	label_count += 2;

	return block;
}

/** While statement */
struct codeblock* wml_while_statement(struct expression pExpression, struct codeblock* pBlk)
{
	codeblock* block = codeBlockFactory( strlen(pBlk->code) +
										 strlen(pExpression.code_fragment->code) + LINE_SIZE);

	sprintf(block->code, "LABEL $%d\n"
						 "%s"
						 "TJUMP_FW_W $%d\n"
						 "%s"
						 "JUMP_BW_W $%d\n"
						 "LABEL $%d\n", label_count, pExpression.code_fragment->code, label_count + 1, pBlk->code, label_count, label_count + 1);

	label_count += 2;

	return block;
}

/** Expressões relacionais */
struct codeblock* wml_build_relational_expression(struct expression pExp1, struct expression pExp2, int pOperator)
{
	codeblock* block = codeBlockFactory(strlen(pExp1.code_fragment->code) +
										strlen(pExp2.code_fragment->code) + LINE_SIZE);

	sprintf(block->code, "%s%s%s\n", pExp1.code_fragment->code, pExp2.code_fragment->code, wmlOperators(pOperator));

	return block;
}

/** Operação entre expressões */
struct codeblock* wml_build_sign_expression(struct expression pExp1, struct expression pExp2, int pOperator)
{
	codeblock* block = wml_build_expression(pExp1, pExp2);

	if ( pOperator == T_PLUS )
	{
		return block;
	}

	else
	{
		codeblock* add = codeBlockFactory(strlen(block->code) + LINE_SIZE);

		sprintf(add->code, "%sUMINUS\n", pExp1.code_fragment->code);

		return add;
	}
}

/** Modificador de sinal */
struct codeblock* wml_build_single_sign_expression(struct expression pExp1, int pOperator)
{
	if ( pOperator == T_PLUS )
	{
		return pExp1.code_fragment;
	}

	else
	{
		codeblock* block = codeBlockFactory(strlen(pExp1.code_fragment->code) + LINE_SIZE);

		sprintf(block->code, "%sUMINUS\n", pExp1.code_fragment->code);

		return block;
	}
}

/** Expression */
struct codeblock* wml_build_expression(struct expression pExp1, struct expression pExp2)
{
	codeblock* block = codeBlockFactory(strlen(pExp1.code_fragment->code) +
										strlen(pExp2.code_fragment->code) + LINE_SIZE);

	sprintf(block->code, "%s%s%s\n", pExp1.code_fragment->code, pExp2.code_fragment->code, wmlOperators(pExp2.operation));

	return block;
}

/** Not Expression */
struct codeblock* wml_build_not_expression(struct expression pExpression)
{
	codeblock* block = codeBlockFactory(LINE_SIZE);

	sprintf(block->code, "%sNOT\n", pExpression.code_fragment->code);

	return block;
}

/** Uso de constante inteira */
struct codeblock* wml_use_int_const(int pInt)
{
	codeblock* block = codeBlockFactory(LINE_SIZE);

	sprintf(block->code, "CONST INT %d\n"
						 "LOAD_CONST_S %d\n", pInt, top_scope->num_consts++);

	return block;
}

/** Uso de constante real */
struct codeblock* wml_use_real_const(float pReal)
{
	// Não suportado
	return codeBlockFactory(0);
}

/** Uso de constante booleana */
struct codeblock* wml_use_boolean_const(int pBoolean)
{
	codeblock* block = codeBlockFactory(LINE_SIZE);

	sprintf(block->code, "CONST BOOLEAN %d\n"
						 "LOAD_CONST_S %d\n", pBoolean, top_scope->num_consts++);

	return block;
}

/** Uso de uma variável */
struct codeblock* wml_get_variable_access(struct symbol* pSymbol)
{
	codeblock* block = codeBlockFactory(LINE_SIZE);

	if ( ( pSymbol->spec == VAR ) | ( pSymbol->spec == PARAM ) )
	{
		sprintf(block->code, "LOAD_VAR_S %d\n", pSymbol->stack_num);
	}

	else if ( pSymbol->spec == CONST )
	{
		sprintf(block->code, "LOAD_CONST_S %d\n", pSymbol->stack_num);
	}

	return block;
}
