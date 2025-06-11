; Programa: Calcular o quadrado de um n�mero usando soma de �mpares
; Entrada: DADO armazenado em MEMORIA (endere�ada por H e L)
; Sa�da: Resultado (quadrado) armazenado em DE

ORG 2000H       ; In�cio do programa na mem�ria

; Inicializa��o
LXI H, MEMORIA  ; Carregar endere�o do dado
MOV A, M        ; Carregar o n�mero (DADO) no acumulador
MOV B, A        ; Copiar o n�mero para B (contador)
MVI D, 00H      ; Inicializar parte alta do resultado em D
MVI E, 00H      ; Inicializar parte baixa do resultado em E
MVI C, 01H      ; Primeiro n�mero �mpar (1)

; Loop para calcular o quadrado
SQUARE_LOOP:
MOV A, C        ; Carregar o pr�ximo n�mero �mpar em A
ADD E           ; Somar n�mero �mpar � parte baixa
MOV E, A        ; Atualizar parte baixa do resultado
JNC SKIP_INC    ; Se n�o houver carry, pular incremento
INR D           ; Incrementar parte alta do resultado

SKIP_INC:
INR C           ; Incrementar n�mero �mpar (C += 2)
INR C
DCR B           ; Decrementar contador
JNZ SQUARE_LOOP ; Repetir enquanto B != 0

HLT             ; Parar o programa

; Dados na mem�ria
ORG 2050H
MEMORIA: DB 05H ; N�mero para calcular o quadrado (exemplo: 5)
