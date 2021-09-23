STACKS  SEGMENT   STACK       
        DW        128 DUP(?)  
STACKS  ENDS
DATAS  SEGMENT               
MESSAGE  DB        'hello world', '$'
DATAS  ENDS
CODES  SEGMENT              
        ASSUME    CS:CODES,DS:DATAS
START:  MOV       AX,DATAS    
        MOV       DS,AX
        LEA       DX, MESSAGE
        MOV       AH, 9
        INT       21H
        MOV       AX,4C00H    
        INT       21H
CODES  ENDS
        END       START