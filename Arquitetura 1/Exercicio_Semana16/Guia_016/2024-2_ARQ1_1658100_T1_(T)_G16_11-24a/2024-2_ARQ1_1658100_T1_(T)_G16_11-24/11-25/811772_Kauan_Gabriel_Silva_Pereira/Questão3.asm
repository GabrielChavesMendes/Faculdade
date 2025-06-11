; Programa: Cálculo do resto usando subtrações sucessivas
; Dividendo: DADO01 (em 8 bits)
; Divisor: DADO02 (em 8 bits)
; Resultado: Resto armazenado em A

ORG 2000H       ; Início do programa na memória

; Definir os dados
LXI H, DADOS    ; Carregar endereço dos dados
MOV A, M        ; Carregar DADO01 no acumulador (Dividendo)
INX H           ; Incrementar endereço para próximo dado
MOV B, M        ; Carregar DADO02 em B (Divisor)

; Loop de subtrações sucessivas
MOD_LOOP:
CMP B           ; Comparar Dividendo com o Divisor
JC END_LOOP     ; Se Dividendo < Divisor, sair do loop
SUB B           ; Subtrair Divisor do Dividendo
JMP MOD_LOOP    ; Repetir o loop

END_LOOP:
; Registrador A contém o resto da divisão
HLT             ; Parar o programa

; Dados na memória
ORG 2050H
DADOS: DB 0FH, 04H ; Exemplo: DADO01 = 15 (0Fh), DADO02 = 4 (04h)
