/*
 * wml_codegen.h
 *
 *  Created on: 16/11/2013
 *      Author: Thiago
 */

#ifndef WML_CODEGEN_H
#define WML_CODEGEN_H

#include <stdio.h>
#include "code_generator.h"
#define LINE_SIZE 99
#define NUM_OPERATORS 15

/** Operadores da linguagem */
static char* wml_operators[] = {"ADD", "SUB", "MUL", "DIV", "IDIV", "REM",   "AND", "OR", "NOT", "EQ", "NE", "LE", "GE", "LT", "GT", "MOD"};
static int   tokenToIndex[]  = {   15,    16,    17,    18,     19,     0,      24,   25,    26,   42,   43,   45,   47,   44,   46,    20};

/** Dado um token de uma operação em Pascal-- retorna a operação respectiva em wml */
char* wmlOperators(int pOperation);

/* Funções de gerção de código */

/** Inicializa o gerador de código e referênica todas as funções de geração de código */
void initWmlCodeGen(void);

/** Escreve o código final do programa no arquivo de código *. asm */
void wml_build_program(int pId, struct codeblock* pProgram);

/** Construi um bloco de programa apartir de seus subcomponentes */
struct codeblock* wml_build_block_body(struct codeblock* pBlk1, struct codeblock* pBlk2, struct codeblock* pBlk3, struct codeblock* pBlk4);

/** Declaração de constante */
struct codeblock* wml_constant_declare(struct symbol* pSymbol);

/** Declaração de variable */
struct codeblock* wml_variable_declare(struct paramList* pList);

/** Constrói um procedure */
struct codeblock* wml_build_procedure(struct symbol* pSymbol);

/** Declaração de procedimento */
void wml_procedure_declare(struct symbol* pSymbol);

/** Assignment statement */
struct codeblock* wml_build_assignment(struct symbol* pSymbol, struct expression pExpression);

/** Chamada a procedimento sem parâmetros */
struct codeblock* wml_call_procedure_void(struct symbol* pSymbol);

/** Chamada a procedimento com parâmetros */
struct codeblock* wml_call_procedure(struct symbol* pSymbol, struct codeblock* pBlk);

/** If statement */
struct codeblock* wml_if_statement(struct expression pExpression, struct codeblock* pIfBlk);

/** If Else statement */
struct codeblock* wml_if_else_statement(struct expression pExpression, struct codeblock* pIfBlk, struct codeblock* pElseBlk);

/** While statement */
struct codeblock* wml_while_statement(struct expression pExpression, struct codeblock* pBlk);

/** Expressões relacionais */
struct codeblock* wml_build_relational_expression(struct expression pExp1, struct expression pExp2, int pOperator);

/** Operação entre expressões */
struct codeblock* wml_build_sign_expression(struct expression pExp1, struct expression pExp2, int pOperator);

/** Modificador de sinal */
struct codeblock* wml_build_single_sign_expression(struct expression pExp1, int pOperator);

/** Expression */
struct codeblock* wml_build_expression(struct expression pExp1, struct expression pExp2);

/** Not Expression */
struct codeblock* wml_build_not_expression(struct expression pExpression);

/** Uso de constante inteira */
struct codeblock* wml_use_int_const(int pInt);

/** Uso de constante real */
struct codeblock* wml_use_real_const(float pReal);

/** Uso de constante booleana */
struct codeblock* wml_use_boolean_const(int pBoolean);

/** Uso de uma variável */
struct codeblock* wml_get_variable_access(struct symbol* pSymbol);

#endif /* WML_CODEGEN_H */
