; Programa: C�lculo do resto usando subtra��es sucessivas
; Dividendo: DADO01 (em 8 bits)
; Divisor: DADO02 (em 8 bits)
; Resultado: Resto armazenado em A

ORG 2000H       ; In�cio do programa na mem�ria

; Definir os dados
LXI H, DADOS    ; Carregar endere�o dos dados
MOV A, M        ; Carregar DADO01 no acumulador (Dividendo)
INX H           ; Incrementar endere�o para pr�ximo dado
MOV B, M        ; Carregar DADO02 em B (Divisor)

; Loop de subtra��es sucessivas
MOD_LOOP:
CMP B           ; Comparar Dividendo com o Divisor
JC END_LOOP     ; Se Dividendo < Divisor, sair do loop
SUB B           ; Subtrair Divisor do Dividendo
JMP MOD_LOOP    ; Repetir o loop

END_LOOP:
; Registrador A cont�m o resto da divis�o
HLT             ; Parar o programa

; Dados na mem�ria
ORG 2050H
DADOS: DB 0FH, 04H ; Exemplo: DADO01 = 15 (0Fh), DADO02 = 4 (04h)
