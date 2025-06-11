; Programa: Calcular o fatorial de um n�mero
; Entrada: N�mero armazenado em MEMORIA
; Sa�da: Fatorial armazenado em DE (16 bits)

ORG 2000H       ; In�cio do programa na mem�ria

; Inicializa��o
LXI H, MEMORIA  ; Carregar endere�o do dado
MOV A, M        ; Carregar o n�mero (n) no acumulador
MOV B, A        ; Copiar o n�mero para o contador (B)
MVI D, 00H      ; Inicializar parte alta do resultado em D
MVI E, 01H      ; Inicializar parte baixa do resultado em E (1, pois 1 � o neutro multiplicativo)

; Loop para calcular o fatorial
FACTORIAL_LOOP:
MOV A, B        ; Carregar o contador (n)
CALL MULTIPLY   ; Multiplicar DE por A
DCR B           ; Decrementar o contador (n -= 1)
JNZ FACTORIAL_LOOP ; Repetir enquanto n != 0

HLT             ; Parar o programa

; Sub-rotina: Multiplica��o
; Entrada: DE = n�mero acumulado, A = multiplicador
; Sa�da: DE = produto (16 bits)
MULTIPLY:
MOV C, E        ; Copiar parte baixa do acumulador para C
MOV E, 00H      ; Zerar parte baixa do acumulador temporariamente
MOV H, D        ; Copiar parte alta do acumulador para H
MOV L, 00H      ; Zerar parte baixa do multiplicador
ADD C           ; Somar multiplicador � parte baixa
MOV E, A        ; Atualizar parte baixa com resultado
JNC NO_CARRY    ; Se n�o houver carry, pular
INR D           ; Incrementar parte alta se houver carry

NO_CARRY:
RET             ; Retornar ao programa principal

; Dados na mem�ria
ORG 2050H
MEMORIA: DB 05H ; N�mero para calcular o fatorial (exemplo: 5)
