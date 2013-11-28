%{

#include "lexer.h"
#include "scope_structure.h"

extern int yylex(void);
extern int yyerror(char*);

%}
%code requires 
{
#include "type_check.h"
#include "wml_codegen.h"
}

%union 
{
	char   tk_name[32];
	int    tk_1;
	int    tk_id;
	int    tk_int;
	int    tk_bool;
	float  tk_real;
	struct symbol* record;
	struct expression expr;
	struct codeblock* code_fragment;
}

%token T_EOF                  0
%token T_ID                   1
%token T_INT_CONST            2
%token T_REAL_CONST           3
%token T_BOOLEAN_CONST        4
%token T_PROGRAM              5
%token T_PROCEDURE            6
%token T_BEGIN                7
%token T_END                  8
%token T_IF                   9
%token T_THEN                 10
%token T_ELSE                 11
%token T_WHILE                12
%token T_DO                   13
%token T_ASSIGN               14
%token T_PLUS                 15
%token T_MINUS                16
%token T_TIMES                17
%token T_DIVIDE               18
%token T_DIV                  19
%token T_MOD                  20
%token T_PLUS_EQ              21
%token T_MINUS_EQ             22
%token T_TIMES_EQ             23
%token T_AND                  24
%token T_OR                   25
%token T_NOT                  26
%token T_DIVIDE_EQ            27
%token T_VAR                  28
%token T_INTEGER              29
%token T_REAL                 30
%token T_BOOLEAN              31
%token T_COLON                32
%token T_SEMICOLON            33
%token T_COMMA                34
%token T_PERIOD               35
%token T_DOUBLE_PERIOD        36
%token T_LBRACKET             37
%token T_RBRACKET             38
%token T_CONST                39
%token T_REPEAT               40
%token T_UNTIL                41
%token T_EQ                   42
%token T_DIF                  43
%token T_LT                   44
%token T_LEQ                  45
%token T_GT                   46
%token T_GEQ                  47
%token T_INVALID             255

%no-lines

%right T_THEN T_ELSE

%type<expr> star_adding_operator_term star_multiplying_operator_factor factor expression simple_expression actual_parameter term constant
%type<record> formal_parameter_list opt_brc_formal_parameter_list_brc variable_group star_comma_id parameter_definition star_smc_parameter_definition opt_brc_actual_parameter_list_brc actual_parameter_list star_comma_actual_parameter variable_access procedure_block 
%type<tk_id> T_ID type adding_operator relational_operator multiplying_operator sign_operator
%type<tk_int> T_INT_CONST 
%type<tk_bool> T_BOOLEAN_CONST
%type<tk_real> T_REAL_CONST
%type<code_fragment> input block_body opt_constant_definition_part opt_variable_definition_part star_procedure_definition constant_definition_part variable_definition_part procedure_definition plus_constant_definition constant_definition plus_variable_definition variable_definition assignment_statement procedure_statement if_statement while_statement compound_statement star_comma_statement statement 
%%

input: T_PROGRAM T_ID T_SEMICOLON force_initialization block_body T_PERIOD
{
	codegen.build_program($2, $5);
	finalizeCodeFile();
	clearTypeTables();
	clearScope();
};

force_initialization: 
{ 
    createTypeTable();
    initSymTab();
    initCodeFile();
    initWmlCodeGen();
};

block_body: opt_constant_definition_part opt_variable_definition_part star_procedure_definition compound_statement
{
	$$ = codegen.build_block_body($1, $2, $3, $4);
};

opt_constant_definition_part:
{
	$$ = codeBlockFactory(0);
}
                            | constant_definition_part
{
	$$ = $1;
};

opt_variable_definition_part:
{
	$$ = codeBlockFactory(0);
} 
                            | variable_definition_part
{
	$$ = $1;
};

star_procedure_definition:
{
	$$ = codeBlockFactory(0);
}
                         | procedure_definition star_procedure_definition
{
	$$ = codeBlockCat($1, $2);
};

constant_definition_part: T_CONST plus_constant_definition
{
	$$ = $2;
};

plus_constant_definition: constant_definition
{
	$$ = $1;
}
                        | constant_definition plus_constant_definition
{
	$$ = codeBlockCat($1, $2);
};

constant_definition: T_ID T_EQ T_INT_CONST T_SEMICOLON 
{   
	YYSTYPE c;
	
	c.tk_int = $3;
	
	symbol* lSymbol = constDeclare($1, c, T_INT_CONST);
	
    if ( lSymbol == NULL ) 
    {
        printf("\nERROR : Redefinição do símbolo '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR; 
    }
    
    $$ = codegen.constant_declare(lSymbol);
} 
                   | T_ID T_EQ T_REAL_CONST T_SEMICOLON 
{   
	YYSTYPE c;
	
	c.tk_real = $3;
	
	symbol* lSymbol = constDeclare($1, c, T_REAL_CONST);
	
    if ( lSymbol == NULL )
    {
        printf("\nERROR : Redefinição do símbolo '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;  
    }
    
    $$ = codegen.constant_declare(lSymbol);
} 
                   | T_ID T_EQ T_BOOLEAN_CONST T_SEMICOLON 
{   
	YYSTYPE c;
	
	c.tk_bool = $3;
	
	symbol* lSymbol = constDeclare($1, c, T_BOOLEAN_CONST);
	
    if ( lSymbol == NULL ) 
    {
        printf("\nERROR : Redefinição do símbolo '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;  
    }
    
    $$ = codegen.constant_declare(lSymbol);
}
;

variable_definition_part: T_VAR plus_variable_definition
{
	$$ = $2;
};

plus_variable_definition: variable_definition
{
	$$ = $1;
}
                        | variable_definition plus_variable_definition
{
	$$ = codeBlockCat($1, $2);
};

variable_definition: variable_group T_SEMICOLON
{
    $$ = codegen.variable_declare($1->param_list);
    
	symbol* lSymbol = $1->param_list->parameter;
	
	while ( lSymbol != NULL )
	{
		lSymbol->spec = VAR;

		insertLocal(lSymbol);
		
		lSymbol = lSymbol->next_symbol;
	}
    
    free($1->param_list);
    
    free($1);
};

variable_group: T_ID star_comma_id T_COLON type
{
    $$ = $2;
    
    if ( ( searchParam2($$->param_list, $1) == 0 ) )
    {
        symbol* lSymbol = symbolFactory();
        
        lSymbol->spec = PARAM;
        
        lSymbol->id = $1;
        
        paramListPushBack($$->param_list, lSymbol);
        
        setParamType($$->param_list, $4);
    }
    
    else
    {
        printf("\nERROR : Múltipla definição do símbolo '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;
    }
};

star_comma_id: 
{
    $$ = symbolFactory();
    
    $$->param_list = paramListFactory();
}
             | T_COMMA T_ID star_comma_id
{
    $$ = $3;
    
    if ( ( searchParam2($$->param_list, $2) == 0 ) )
    {
        symbol* lSymbol = symbolFactory();
        
        lSymbol->spec = PARAM;
        
        lSymbol->id = $2;
        
        paramListPushBack($$->param_list, lSymbol);
    }
    
    else
    {
        printf("\nERROR : Múltipla definição do símbolo '%s' [Line %d]\n", getToken($2), getLine());
        YYERROR;
    }
};

type: T_INTEGER { $$ = T_INTEGER; }
    | T_REAL    { $$ = T_REAL;    }
    | T_BOOLEAN { $$ = T_BOOLEAN; };

procedure_definition: procedure_block block_body T_SEMICOLON 
{
	$1->code_fragment = $2;
	
	$$ = codegen.build_procedure($1);
	
    clearScope();
};

procedure_block: T_PROCEDURE T_ID opt_brc_formal_parameter_list_brc T_SEMICOLON 
{
	$$ = procDeclare($2);
	
	if ( $$ == NULL )
	{
		printf("\nERROR : Múltipla definição do procedimento '%s' [Line %d]", getToken($2)->tk_name, getLine());
		YYERROR;
	}
	
	newScope();
	
	codegen.procedure_declare($$);
	
	$$->param_list = $3->param_list;
	
	globalSearch2($2)->param_list = $3->param_list;
	
	symbol* lSymbol = $$->param_list->parameter;

	while ( lSymbol != NULL )
	{	
		insertParam(lSymbol);
		
        lSymbol = lSymbol->next_symbol;
	}
};

opt_brc_formal_parameter_list_brc: 
{
    $$ = symbolFactory();
    
	$$->param_list = paramListFactory();
}
                                 | T_LBRACKET formal_parameter_list T_RBRACKET
{
    $$ = symbolFactory();
    
	$$->param_list = $2->param_list;
	
	free($2);
};

formal_parameter_list: parameter_definition star_smc_parameter_definition
{
    $$ = symbolFactory();
    
    $$->spec = PARAMLIST;
    
    $2->param_list = invertParamList($2->param_list);
    
    symbol* lSymbol = $2->param_list->parameter;

	int r = 1;
	
	while ( lSymbol != NULL  )
    {
    	if ( searchParam2($1->param_list, lSymbol->id) != 0 )
    	{
    		r = 0;
    		
    		printf("\nERROR : Definição de parâmetros com mesmo identificador '%s' [Line %d]\n", getToken(lSymbol->id), getLine());
    		
    		break;
    	}
    	
    	paramListPushFront($1->param_list, lSymbol);
    	
    	lSymbol = lSymbol->next_symbol;	
    }
    
    $$->param_list = $1->param_list;
    
    free($2->param_list);
	
	if ( r == 0 )
	{
		YYERROR;
	}
};

star_smc_parameter_definition:
{
    $$ = symbolFactory();
    
    $$->spec = PARAMLIST;
    
    $$->param_list = paramListFactory();
} 
                             | T_SEMICOLON parameter_definition star_smc_parameter_definition
{
    $$ = symbolFactory();
    
    $$->spec = PARAMLIST;
    
    symbol* lSymbol = $3->param_list->parameter;

	int r = 1;
	
	while( lSymbol != NULL )
    {
    	if ( searchParam2($2->param_list, lSymbol->id) != 0 )
    	{
    		r = 0;
    		
    		break;
    	}
    	
    	paramListPushBack($2->param_list, lSymbol);
    	
    	lSymbol = lSymbol->next_symbol;
    }
    
    $$->param_list = $2->param_list;
	
	if ( r == 0 )
	{
		printf("\nERROR : Definição de parâmetros com mesmo identificador [Line %d]\n", getLine());
	}
	
	free($3->param_list);
	
	if ( r == 0 )
	{
		YYERROR;
	}
};

parameter_definition: variable_group
{
	$$ = $1;
};

statement:
{
	$$ = codeBlockFactory(0);
}
         | procedure_statement
{
	$$ = $1;
}
         | if_statement
{
	$$ = $1;
}
         | while_statement
{
	$$ = $1;
}
         | compound_statement
{
	$$ = $1;
}
         | assignment_statement
{
	$$ = $1;
};

assignment_statement: variable_access T_ASSIGN expression
{
	if ( ( $1->spec != VAR ) && ( $1->spec != PARAM ) )
	{
		printf("\nERROR : Definição para um símbolo que não é variável ou parâmetro '%s' [Line %d]\n", getToken($1->id), getLine());
        YYERROR;
	}

	if ( checkCompatibility($1->type, $3.type) == 0 )
	{
		printf("\nERROR : Tipos imcompatíveis '%s' [Line %d]\n", getToken($1->id), getLine());
        YYERROR;
	}

	$$ = codegen.build_assignment($1, $3);
};

procedure_statement: T_ID opt_brc_actual_parameter_list_brc
{
	symbol* procSymbol = globalSearch2($1);
	
    if ( procSymbol == NULL || procSymbol->spec != PROCEDURE )
    {
        printf("\nERROR : Procedimento não declarado '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;
    }

    if ( procSymbol->param_list->length == 0 )
    {
        if ( $2->param_list->length != 0 )
        {
            printf("\nERROR : O Procedimento '%s' não tem parâmetros, mas está sendo passado com parâmetros [Line %d]\n", getToken($1), getLine());
            YYERROR;
        }
        
        $$ = codegen.call_procedure_void(procSymbol);
    }
    
    else
    {
        if ( $2->param_list->length == 0 )
        {
            printf("\nERROR : O Procedimento '%s' não tem parâmetros, mas está sendo passado com parâmetros [Line %d]\n", getToken($1), getLine());
            YYERROR;
        }
        
        if ( $2->param_list->length != procSymbol->param_list->length )
        {
            printf("\nERROR : A chamada ao procedimento '%s' não está com o número de parâmetros correto, são esperados '%d', mas foram passados '%d' [Line %d]\n", getToken($1), procSymbol->param_list->length, $2->param_list->length, getLine());
            YYERROR;
        }
        
        symbol* aux = compareParamList($2->param_list, procSymbol->param_list);
        int diff = compareParamList2($2->param_list, procSymbol->param_list);
        
    	if ( aux != NULL )
    	{
    		printf("\nERROR : O tipo da expressão não é compatível com o %d%c parâmetro do procedimento [Line %d]\n", diff, (char) 248, getLine());
    		YYERROR;
    	}

    	mergeParamList(procSymbol->param_list, $2->param_list);
    	
    	$$ = codegen.call_procedure(procSymbol, $2->code_fragment);
    }
};

opt_brc_actual_parameter_list_brc:
{
    $$ = symbolFactory();
    $$->id = -1;
    $$->spec = PARAMLIST;
    $$->next_symbol = NULL;
    $$->param_list = paramListFactory();
    $$->code_fragment = codeBlockFactory(0);
}
                                 | T_LBRACKET actual_parameter_list T_RBRACKET
{
    $$ = symbolFactory();
    $$->id = -1;
    $$->spec = PARAMLIST;
    $$->next_symbol = NULL;
    $$->param_list = $2->param_list;
    $$->code_fragment = $2->code_fragment;
};

actual_parameter_list: actual_parameter star_comma_actual_parameter
{
    $$ = $2;
    symbol* lSymbol = symbolFactory();
    lSymbol->spec = PARAM;
    lSymbol->type = $1.type;
    paramListPushBack($$->param_list, lSymbol);
    $$->code_fragment = codeBlockCat($1.code_fragment, $2->code_fragment);
};

star_comma_actual_parameter: 
{
    $$ = symbolFactory();
    $$->spec = PARAMLIST;
    $$->param_list = paramListFactory();
    $$->code_fragment = codeBlockFactory(0);
}
                           | T_COMMA actual_parameter star_comma_actual_parameter
{
    $$ = $3;
    symbol* lSymbol = symbolFactory();
    lSymbol->spec = PARAM;
    lSymbol->type = $2.type;
    paramListPushBack($$->param_list, lSymbol);
    $$->code_fragment = codeBlockCat($2.code_fragment, $3->code_fragment);
};

actual_parameter: expression
{
	$$ = $1;
};

if_statement: T_IF expression T_THEN statement T_ELSE statement
{
	if ( $2.type != T_BOOLEAN )
	{
		printf("\nERROR : A expressão não é do tipo booleano [Line %d]\n", getLine());
		YYERROR;
	}
	
	$$ = codegen.if_else_statement($2, $4, $6);
}
            | T_IF expression T_THEN statement
{
	if ( $2.type != T_BOOLEAN )
	{
		printf("\nERROR : A expressão não é do tipo booleano [Line %d]\n", getLine());
		YYERROR;
	}
	
	$$ = codegen.if_statement($2, $4);
};

while_statement: T_WHILE expression T_DO statement
{
	if ( $2.type != T_BOOLEAN )
	{
		printf("\nERROR : A expressão não é do tipo booleano [Line %d]\n", getLine());
		YYERROR;
	}
	
	$$ = codegen.while_statement($2, $4);
};

compound_statement: T_BEGIN statement star_comma_statement T_END
{
	$$ = codeBlockCat($2, $3);
};

star_comma_statement:
{
	$$ = codeBlockFactory(0);
}
                    | T_SEMICOLON statement star_comma_statement
{
	$$ = codeBlockCat($2, $3);
};

expression: simple_expression relational_operator simple_expression
{
	$$.type = getExpressionReturnType($1.type, $3.type, $2);
	
	if ( $$.type == T_INVALID )
	{
		printf("\nERROR : Operandos inválidos [Line %d]\n", getLine());
		YYERROR;
	}
	
	$$.code_fragment = codegen.build_relational_expression($1, $3, $2);
}
		 | simple_expression
{
	$$ = $1;
};

relational_operator: T_LT  { $$ = T_LT;  }
                   | T_EQ  { $$ = T_EQ;  }
                   | T_GT  { $$ = T_GT;  }
                   | T_LEQ { $$ = T_LEQ; }
                   | T_DIF { $$ = T_DIF; }
                   | T_GEQ { $$ = T_GEQ; }
;

simple_expression: sign_operator term star_adding_operator_term
{
	if ( ( $3.operation != T_INVALID ) && ( $3.operation != T_INVALID ) )
	{
		$$.type = getExpressionReturnType($2.type, $3.type, $3.operation);
		
		if ( $$.type == T_INVALID )
		{
			printf("\nERROR : Operandos inválidos [Line %d]\n", getLine());
			YYERROR;
		}
		
		$$.code_fragment = codegen.build_sign_expression($2, $3, $1);
	}
	
	else
	{
		$$.type = $2.type;
		$$.code_fragment = codegen.build_single_sign_expression($2, $1);
	}
}
                 | term star_adding_operator_term
{
	if ( ( $2.operation != T_INVALID ) && ( $2.operation != T_INVALID ) )
	{
		$$.type = getExpressionReturnType($1.type, $2.type, $2.operation);
		
		if ( $$.type == T_INVALID )
		{
			printf("\nERROR : Operandos inválidos [Line %d]\n", getLine());
			YYERROR;
		}
		
		$$.code_fragment = codegen.build_expression($1, $2);
	}
	
	else
	{
		$$ = $1;
	}
};

sign_operator: T_PLUS  { $$ = T_PLUS;  }
             | T_MINUS { $$ = T_MINUS; }
;

star_adding_operator_term:
{
	$$.operation = T_INVALID;
	$$.type = T_INVALID;
}
                         | adding_operator term star_adding_operator_term
{
	if ( ( $3.operation != T_INVALID ) && ( $3.type != T_INVALID ) )
	{
		$$.operation = $1;
		$$.type = getExpressionReturnType($2.type, $3.type, $3.operation);
		
		if ( $$.type == T_INVALID )
		{
			printf("\nERROR : Operandos inválidos [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		$$ = $2;
		$$.operation = $1;
	}
};

adding_operator: T_PLUS  { $$ = T_PLUS;  }
               | T_MINUS { $$ = T_MINUS; }
               | T_OR    { $$ = T_OR;    }
;

term: factor star_multiplying_operator_factor
{
	if ( ( $2.operation != T_INVALID ) && ( $2.type != T_INVALID ) )
	{
		$$.type = getExpressionReturnType($1.type, $2.type, $2.operation);
		
		if ( $$.type == T_INVALID )
		{
			printf("\nERROR : Operandos inválidos [Line %d]\n", getLine());
			YYERROR;
		}
		
		$$.code_fragment = codegen.build_expression($1, $2);
	}
	
	else
	{
		$$ = $1;
	}
};

star_multiplying_operator_factor:
{		
	$$.operation = T_INVALID;
	$$.type = T_INVALID;
}
                                | multiplying_operator factor star_multiplying_operator_factor
{
	$$.operation = $1;
	
	if ( ( $3.operation != T_INVALID ) && ( $3.type != T_INVALID ) )
	{
		$$.type = getExpressionReturnType($2.type, $3.type, $3.operation);
		
		if ( $$.type == T_INVALID )
		{
			printf("\nERROR : Operandos inválidos em [Line %d]\n", getLine());
			YYERROR;
		}
		
		$$.code_fragment = codegen.build_expression($2, $3);
	}
	
	else
	{
		$$ = $2;
		$$.operation = $1;
	}
};

multiplying_operator: T_TIMES  { $$ = T_TIMES;  } 
                    | T_DIV    { $$ = T_DIV;    }
                    | T_MOD    { $$ = T_MOD;    }
                    | T_AND    { $$ = T_AND;    }
                    | T_DIVIDE { $$ = T_DIVIDE; }
;

factor: constant
{
	$$ = $1;
}
      | T_LBRACKET expression T_RBRACKET
{
	$$ = $2;
}
      | T_NOT factor
{
	$$.type = getExpressionReturnType(T_INVALID, $2.type , T_NOT);

	if ( $$.type == T_INVALID )
	{
		printf("\nERROR : Operação inválida [Line %d]\n", getLine());
		YYERROR;
	}
	
	$$.code_fragment = codegen.build_not_expression($2);
};

variable_access: T_ID
{
	$$ = globalSearch2($1);
	
    if ( $$ == NULL )
    {
        printf("\nERROR : Uso de variável não declarada '%s', [Line %d] ", getToken($1), getLine());
        YYERROR;
    }
};

constant: T_INT_CONST     
{
	$$.type = T_INTEGER;
	$$.code_fragment = codegen.use_int_const($1);
}
        | T_REAL_CONST    
{
	$$.type = T_REAL;
	$$.code_fragment = codegen.use_real_const($1);
}
        | T_BOOLEAN_CONST
{
	$$.type = T_BOOLEAN;
	$$.code_fragment = codegen.use_boolean_const($1);
}
        | variable_access
{
	$$.type = $1->type;
	
	$$.code_fragment = codegen.get_variable_access($1);
};
%%