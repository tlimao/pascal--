-- Pascalmm Ver. 1.0

EXTERN FUNCTION MAIN 0 0 
FUNCVARS 5
CONST INT             332
CONST INT              32
EXTERN FUNCTION mdc1 1 2
FUNCVARS 5
LOAD_VAR_S 1
STORE_VAR_S 6
LOAD_VAR_S 0
STORE_VAR_S 5
LABEL $0
LOAD_VAR_S 2
CONST INT 0
LOAD_CONST_S 0
NE
TJUMP_FW_W $1
LOAD_VAR_S 6
LOAD_VAR_S 5
IDIV
STORE_VAR_S 4
LOAD_VAR_S 6
LOAD_VAR_S 4
LOAD_VAR_S 5
MUL
SUB
STORE_VAR_S 2
LOAD_VAR_S 5
STORE_VAR_S 6
LOAD_VAR_S 2
STORE_VAR_S 5
JUMP_BW_W $0
LABEL $1
EXTERN FUNCTION mdc2 2 2
FUNCVARS 5
LOAD_VAR_S 6
LOAD_VAR_S 5
IDIV
STORE_VAR_S 4
LOAD_VAR_S 6
LOAD_VAR_S 4
LOAD_VAR_S 5
MUL
SUB
STORE_VAR_S 2
LOAD_VAR_S 2
CONST INT 0
LOAD_CONST_S 0
NE
TJUMP_FW_W $2
LOAD_VAR_S 5
LOAD_VAR_S 2
CALL_S 2
LABEL $2
LOAD_CONST_S 0
LOAD_CONST_S 1
CALL_S 1
LOAD_CONST_S 0
LOAD_CONST_S 1
CALL_S 2
LOAD_CONST_S 0
STORE_VAR_S 4
LOAD_CONST_S 1
STORE_VAR_S 3
LABEL $3
LOAD_VAR_S 0
CONST INT 0
LOAD_CONST_S 2
NE
TJUMP_FW_W $4
LOAD_VAR_S 4
LOAD_VAR_S 3
IDIV
STORE_VAR_S 2
LOAD_VAR_S 4
LOAD_VAR_S 2
LOAD_VAR_S 3
MUL
SUB
STORE_VAR_S 0
LOAD_VAR_S 3
STORE_VAR_S 4
LOAD_VAR_S 0
STORE_VAR_S 3
JUMP_BW_W $3
LABEL $4

-- end