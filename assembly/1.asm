DATA SEGMENT
ARRAY DB 12,12,14,-12,-14,23
DATA ENDS
CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
MOV AX,DATA
MOV DS,AX
MOV BX,OFFSET ARRAY
MOV SI,0
MOV CX,7
MOV DX,0
AGAIN:
    MOV AL,[BX+SI]
    TEST AL,80H
    JZ NEXT
    INC DX
        NEXT: INC SI
LOOP AGAIN
CODE ENDS
END START