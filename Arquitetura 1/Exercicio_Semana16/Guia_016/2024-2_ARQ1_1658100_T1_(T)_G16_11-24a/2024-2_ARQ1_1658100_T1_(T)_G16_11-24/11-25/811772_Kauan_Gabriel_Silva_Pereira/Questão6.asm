; Programa: Calcular o quadrado de um número usando soma de ímpares
; Entrada: DADO armazenado em MEMORIA (endereçada por H e L)
; Saída: Resultado (quadrado) armazenado em DE

ORG 2000H       ; Início do programa na memória

; Inicialização
LXI H, MEMORIA  ; Carregar endereço do dado
MOV A, M        ; Carregar o número (DADO) no acumulador
MOV B, A        ; Copiar o número para B (contador)
MVI D, 00H      ; Inicializar parte alta do resultado em D
MVI E, 00H      ; Inicializar parte baixa do resultado em E
MVI C, 01H      ; Primeiro número ímpar (1)

; Loop para calcular o quadrado
SQUARE_LOOP:
MOV A, C        ; Carregar o próximo número ímpar em A
ADD E           ; Somar número ímpar à parte baixa
MOV E, A        ; Atualizar parte baixa do resultado
JNC SKIP_INC    ; Se não houver carry, pular incremento
INR D           ; Incrementar parte alta do resultado

SKIP_INC:
INR C           ; Incrementar número ímpar (C += 2)
INR C
DCR B           ; Decrementar contador
JNZ SQUARE_LOOP ; Repetir enquanto B != 0

HLT             ; Parar o programa

; Dados na memória
ORG 2050H
MEMORIA: DB 05H ; Número para calcular o quadrado (exemplo: 5)
