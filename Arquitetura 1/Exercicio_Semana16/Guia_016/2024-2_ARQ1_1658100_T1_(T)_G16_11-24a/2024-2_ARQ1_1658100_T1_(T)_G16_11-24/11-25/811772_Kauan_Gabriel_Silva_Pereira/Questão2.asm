; Programa: Divis�o usando subtra��es sucessivas
; Dividendo: DADO01 (em 8 bits)
; Divisor: DADO02 (em 8 bits)
; Resultado: Quociente armazenado em C, Resto armazenado em A

ORG 2000H       ; In�cio do programa na mem�ria

; Definir os dados
LXI H, DADOS    ; Carregar endere�o dos dados
MOV A, M        ; Carregar DADO01 no acumulador (Dividendo)
INX H           ; Incrementar endere�o para pr�ximo dado
MOV B, M        ; Carregar DADO02 em B (Divisor)

; Inicializar quociente como 0
MVI C, 00H      ; Registrador C armazena o quociente

; Loop de subtra��es sucessivas
DIV_LOOP:
CMP B           ; Comparar Dividendo com o Divisor
JC END_LOOP     ; Se Dividendo < Divisor, sair do loop
SUB B           ; Subtrair Divisor do Dividendo
INR C           ; Incrementar o Quociente
JMP DIV_LOOP    ; Repetir o loop

END_LOOP:
; Registrador A cont�m o resto da divis�o
; Registrador C cont�m o quociente
HLT             ; Parar o programa

; Dados na mem�ria
ORG 2050H
DADOS: DB 0FH, 03H ; Exemplo: DADO01 = 15 (0Fh), DADO02 = 3 (03h)
