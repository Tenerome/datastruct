DATA SEGMENT  
    STR1 DB 'HOW DU YOU DO?',0DH,0AH,'$‘
  DATA ENDS
  CODE SEGMENT  
    ASSUME CS:CODE,DS:DATA
    START: MOV AX,DATA
           MOV DS,AX
           MOV DX,OFFSET STR1；字符串首偏移地址放到DX中
           MOV AH,9      
           INT
           MOV AH,4C21H;输出字符串 H
           INT 21H
  CODE ENDS 
    END START