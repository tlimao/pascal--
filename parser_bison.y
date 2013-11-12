%{

#include "bison_adaptee.h"
#include "scope_structure.h"

extern int yylex(void);
extern int yyerror(char*);

%}
%code requires 
{
#include "type_check.h"
}

%union 
{
	char  tk_name[32];
	int   tk_1;
	int   tk_idx;
	int   tk_int;
	int   tk_bool;
	float tk_real;
	struct symbol* record;
	struct expression expr;
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

%type<expr> star_adding_operator_term star_multiplying_operator_factor opt_relational_operator_simple_expression
%type<record> init_procedure formal_parameter_list opt_brc_formal_parameter_list_brc procedure_block variable_group star_comma_id parameter_definition star_smc_parameter_definition opt_brc_actual_parameter_list_brc actual_parameter_list star_comma_actual_parameter
%type<tk_idx> T_ID variable_access type factor expression term adding_operator constant simple_expression relational_operator multiplying_operator actual_parameter
%type<tk_int> T_INT_CONST 
%type<tk_bool>T_BOOLEAN_CONST
%type<tk_real> T_REAL_CONST

%%
input: T_PROGRAM T_ID T_SEMICOLON force_initialization block_body T_PERIOD
{
	printf("FIM\n");
	//clearTypeTables();
};

force_initialization: 
{ 
    createTypeTable();
    initSymTab();
};

block_body: opt_constant_definition_part opt_variable_definition_part star_procedure_definition compound_statement
;

opt_constant_definition_part: 
                            | constant_definition_part
;

opt_variable_definition_part: 
                            | variable_definition_part  
;

star_procedure_definition:
                         | procedure_definition star_procedure_definition
;

constant_definition_part: T_CONST plus_constant_definition
;

plus_constant_definition: constant_definition 
                        | constant_definition plus_constant_definition
;

constant_definition: T_ID T_EQ T_INT_CONST T_SEMICOLON 
{
    YYSTYPE t;
    
    t.tk_int = $3;
    
    if ( constDeclare($1, t, T_INT_CONST) == NULL ) 
    {
        printf("ERROR 1: Redefinition of symbol '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR; 
    }
} 
                   | T_ID T_EQ T_REAL_CONST T_SEMICOLON 
{
    YYSTYPE t;
    
    t.tk_real = $3;
    
    if ( constDeclare($1, t, T_REAL_CONST) == NULL ) 
    {
        printf("ERROR 2: Redefinition of symbol '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;  
    }
} 
                   | T_ID T_EQ T_BOOLEAN_CONST T_SEMICOLON 
{
    YYSTYPE t;
    
    t.tk_bool = $3;
    
    if ( constDeclare($1, t, T_BOOLEAN_CONST) == NULL ) 
    {
        printf("ERROR 3: Redefinition of symbol '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;  
    }
};

variable_definition_part: T_VAR plus_variable_definition
;

plus_variable_definition: variable_definition 
                        | variable_definition plus_variable_definition
;

variable_definition: variable_group T_SEMICOLON
{
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
    
    if ( ( searchParam2($$->param_list, $1) == 0 ) && ( localSearch($1) == 0 ) )
    {
        symbol* lSymbol = (symbol*) malloc(sizeof(symbol));
        
        lSymbol->spec = PARAM;
        
        lSymbol->id = $1;
        
        lSymbol->param_list = NULL;
        
        paramListPushBack($$->param_list, lSymbol);
        
        setParamType($$->param_list, $4);
    }
    
    else
    {
        printf("ERROR 4: Multiple definition of symbol '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;
    }
};

star_comma_id: 
{
    $$ = (symbol*) malloc(sizeof(symbol));
    
    $$->param_list = paramListFactory();
}
             | T_COMMA T_ID star_comma_id
{
    $$ = $3;
    
    if ( ( searchParam2($$->param_list, $2) == 0 ) && ( localSearch($2) == 0 ) )
    {
        symbol* lSymbol = (symbol*) malloc(sizeof(symbol));
        
        lSymbol->spec = PARAM;
        
        lSymbol->id = $2;
        
        lSymbol->param_list = NULL;
        
        paramListPushBack($$->param_list, lSymbol);
    }
    
    else
    {
        printf("ERROR 5: Multiple definition of symbol '%s' [Line %d]\n", getToken($2), getLine());
        YYERROR;
    }
};

type: T_INTEGER 
{
    $$ = T_INTEGER; 
}
    | T_REAL 
{
    $$ = T_REAL; 
}
    | T_BOOLEAN 
{
    $$ = T_BOOLEAN; 
};

procedure_definition: procedure_block block_body T_SEMICOLON 
{
    clearScope();
    printSymTab();
};

procedure_block: init_procedure opt_brc_formal_parameter_list_brc T_SEMICOLON 
{
	$$ = globalSearch2($1->id);
	
	symbol* lSymbol = $2->param_list->parameter;

	$$->param_list = $2->param_list;
	
	$$->param_list->length = $2->param_list->length;

	while ( lSymbol != NULL )
	{	
		insertLocal(lSymbol);
		
        lSymbol = lSymbol->next_symbol;
	}
	
	free($1);
};

init_procedure: T_PROCEDURE T_ID
{
	$$ = procDeclare($2);
	
	if ( $$ == NULL )
	{
		printf("Multiple redefinition of Procedure '%s' [Line %d]", getToken($2)->tk_name, getLine());
		YYERROR;
	}
	
	newScope();
};

opt_brc_formal_parameter_list_brc: 
{
    $$ = (symbol*) malloc(sizeof(symbol));
    
	$$->param_list = paramListFactory();
}
                                 | T_LBRACKET formal_parameter_list T_RBRACKET
{
    $$ = (symbol*) malloc(sizeof(symbol));
    
	$$->param_list = $2->param_list;
	
	free($2);
};

formal_parameter_list: parameter_definition star_smc_parameter_definition
{
    $$ = (symbol*) malloc(sizeof(symbol));
    
    $$->id = -1;
    
    $$->spec = PARAMLIST;
    
    $$->type = 0;
    
    $2->param_list = invertParamList($2->param_list);
    
    symbol* lSymbol = $2->param_list->parameter;

	int r = 1;
	
	while( lSymbol != NULL  )
    {
    	if ( searchParam2($1->param_list, lSymbol->id) != 0 )
    	{
    		r = 0;
    		
    		printf("ERROR 6: Definition of multiple parameters with the same identifier '%s' [Line %d]\n", getToken(lSymbol->id), getLine());
    		
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
    $$ = (symbol*) malloc(sizeof(symbol));
    
    $$->id = -1;
    
    $$->spec = PARAMLIST;
    
    $$->type = 0; 
    
    $$->param_list = paramListFactory();
} 
                             | T_SEMICOLON parameter_definition star_smc_parameter_definition
{
    $$ = (symbol*) malloc(sizeof(symbol));
    
    $$->id = -1;
    
    $$->spec = PARAMLIST;
    
    $$->type = 0;
    
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
		printf("ERROR 7: Definition of multiple parameters with the same identifier [Line %d]\n", getLine());
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
         | procedure_statement
         | if_statement
         | while_statement
         | compound_statement
         | assignment_statement
;

assignment_statement: variable_access T_ASSIGN expression
{
	symbol* lSymbol = globalSearch2($1);
	
	if ( ( lSymbol->spec != VAR ) && ( lSymbol->spec != PARAM ) )
	{
		printf("\nERROR: Assignment to non-lvalue '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;
	}
	
	if ( checkCompatibility(lSymbol->type, $3) == 0 )
	{
		printf("\nERROR: Cannot coerce expression into variable '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;
	}
};

procedure_statement: T_ID opt_brc_actual_parameter_list_brc
{
	symbol* procSymbol = globalSearch2($1);
	
	printf("CALL: %s, nP: %d\n", getToken($1)->tk_name, procSymbol->param_list->length);
	
	printParamList(procSymbol->param_list);
	
    if ( procSymbol == NULL || procSymbol->spec != PROCEDURE )
    {
        printf("\nERROR 8: Undefined procedure '%s' [Line %d]\n", getToken($1), getLine());
        YYERROR;
    }

    if ( procSymbol->param_list->length == 0 )
    {
        if ( $2->param_list->length != 0 )
        {
            printf("\nERROR 9: Procedure '%s' has void signature, but is being passed parameters [Line %d]\n", getToken($1), getLine());
            YYERROR;
        }
    }
    
    else
    {
        if ( $2->param_list->length == 0 )
        {
            printf("\nERROR 10: Procedure '%s' does not have void signature, but is being passed no parameters [Line %d]\n", getToken($1), getLine());
            YYERROR;
        }
        
        if ( $2->param_list->length != procSymbol->param_list->length )
        {
            printf("\nERROR 11: Procedure call for '%s' is not passing the right amount of parameters, expected '%d', got '%d' [Line %d]\n", getToken($1), procSymbol->param_list->length, $2->param_list->length, getLine());
            YYERROR;
        }
        
        symbol* aux = compareParamList($2->param_list, procSymbol->param_list);
        int diff = compareParamList2($2->param_list, procSymbol->param_list);
        
    	if ( aux != NULL )
    	{
    		//printf("ERROR 12: Cannot coerce expression into parameter '%s' [Line %d]\n", getToken(aux->id), getLine());
    		printf("ERROR 12: Cannot coerce expression into %d%c parameter [Line %d]\n", diff, (char) 248, getLine());
    		YYERROR;
    	}
    }
};

opt_brc_actual_parameter_list_brc:
{
    $$ = (symbol*) malloc(sizeof(symbol));
    $$->id = -1;
    $$->spec = PARAMLIST;
    $$->next_symbol = NULL;
    $$->param_list = paramListFactory();  
}
                                 | T_LBRACKET actual_parameter_list T_RBRACKET
{
    $$ = (symbol*) malloc(sizeof(symbol));
    $$->id = -1;
    $$->spec = PARAMLIST;
    $$->next_symbol = NULL;
    $$->param_list = $2->param_list;
};

actual_parameter_list: actual_parameter star_comma_actual_parameter
{
    $$ = $2;
    symbol* lSymbol = (symbol*) malloc(sizeof(symbol));
    lSymbol->id = -1;
    lSymbol->spec = PARAM;
    lSymbol->type = $1;
    lSymbol->next_symbol = NULL;
    lSymbol->param_list = NULL;
    paramListPushBack($$->param_list, lSymbol);
};

star_comma_actual_parameter: 
{
    $$ = (symbol*) malloc(sizeof(symbol));
    $$->id = -1;
    $$->spec = PARAMLIST;
    $$->next_symbol = NULL;
    $$->param_list = paramListFactory();
}
                           | T_COMMA actual_parameter star_comma_actual_parameter
{
    $$ = $3;
    symbol* lSymbol = (symbol*) malloc(sizeof(symbol));
    lSymbol->id = -1;
    lSymbol->spec = PARAM;
    lSymbol->type = $2;
    lSymbol->next_symbol = NULL;
    lSymbol->param_list = NULL;
    paramListPushBack($$->param_list, lSymbol);
};

actual_parameter: expression { $$ = $1; }
;

if_statement: T_IF expression T_THEN statement
{
	if ( $2 != T_BOOLEAN )
	{
		printf("ERROR: Expression does not have boolean type [Line %d]\n", getLine());
		YYERROR;
	}
}
            | T_IF expression T_THEN statement T_ELSE statement
{
	if ( $2 != T_BOOLEAN )
	{
		printf("ERROR: Expression does not have boolean type [Line %d]\n", getLine());
		YYERROR;
	}
};

while_statement: T_WHILE expression T_DO statement
{
	if ( $2 != T_BOOLEAN )
	{
		printf("ERROR: Expression does not have boolean type [Line %d]\n", getLine());
		YYERROR;
	}
};

compound_statement: T_BEGIN statement star_comma_statement T_END
;

star_comma_statement:
                    | T_SEMICOLON statement star_comma_statement
;

expression: simple_expression opt_relational_operator_simple_expression
{
	if ( $2.operation != T_INVALID )
	{
		$$ = getExpressionReturnType($1, $2.type, $2.operation);
		
		if ( $$ == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		$$ = $1;
	}
};

opt_relational_operator_simple_expression:
{
	$$.operation = T_INVALID;
	$$.type = T_INVALID;
}
                                         | relational_operator simple_expression
{
	$$.operation = $1;
	$$.type = $2;
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
	if ( ( $3.operation != T_INVALID ) && ( $3.type != T_INVALID ) )
	{
		$$ = getExpressionReturnType($2, $3.type, $3.operation);
		
		if ( $$ == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		$$ = $2;
	}
}
                 | term star_adding_operator_term
{
	if ( ( $2.operation != T_INVALID ) && ( $2.type != T_INVALID ) )
	{
		$$ = getExpressionReturnType($1, $2.type, $2.operation);
		
		if ( $$ == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		$$ = $1;
	}
};

sign_operator: T_PLUS
             | T_MINUS
;

star_adding_operator_term:
{
	$$.operation = T_INVALID;
	$$.type = T_INVALID;
}
                         | adding_operator term star_adding_operator_term
{
	$$.operation = $1;
	
	if ( ( $3.operation != T_INVALID ) && ( $3.type != T_INVALID ) )
	{
		$$.type = getExpressionReturnType($2, $3.type, $3.operation);
		
		if ( $$.type == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		$$.operation = $1;
		$$.type = $2;
	}
};

adding_operator: T_PLUS
{
	$$ = T_PLUS;
}
               | T_MINUS
{
	$$ = T_MINUS;
}
               | T_OR
{
	$$ = T_OR;
};

term: factor star_multiplying_operator_factor
{
	if ( ( $2.operation != T_INVALID ) && ( $2.type != T_INVALID ) )
	{
		$$ = getExpressionReturnType($1, $2.type, $2.operation);
		
		if ( $$ == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
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
		$$.type = getExpressionReturnType($2, $3.type, $3.operation);
		
		if ( $$.type == T_INVALID )
		{
			printf("ERROR: Invalid operands in [Line %d]\n", getLine());
			YYERROR;
		}
	}
	
	else
	{
		$$.type = $2;
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
	$$ = getExpressionReturnType(T_INVALID, $2 , T_NOT);

	if ( $$ == T_INVALID )
	{
		printf("ERROR 34: Invalid Operation in [Line %d]\n", getLine());
		YYERROR;
	}
};

variable_access: T_ID
{
	$$ = $1; 
	
    if ( globalSearch($1) == 0 )
    {
        printf("\nERROR 12: Use of undeclared identifier '%s', [Line %d] ", getToken($1), getLine());
        YYERROR;
    }
};

constant: T_INT_CONST
{
	$$ = T_INTEGER;
}
        | T_REAL_CONST
{
	$$ = T_REAL;
}
        | T_BOOLEAN_CONST
{
	$$ = T_BOOLEAN;
}
        | variable_access
{
	symbol* lSymbol = globalSearch2($1);
	
	$$ = lSymbol->type;
};
%%