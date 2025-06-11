; Programa: Encontrar o maior valor de um arranjo
; Arranjo: Come�a em DADOS
; Tamanho do arranjo: TAM (definido na mem�ria)
; Resultado: Maior valor armazenado no acumulador (A)

ORG 2000H       ; In�cio do programa na mem�ria

; Inicializa��o
LXI H, DADOS    ; Carregar endere�o inicial do arranjo
MVI C, TAM      ; Carregar tamanho do arranjo no registrador C
MOV A, M        ; Carregar o primeiro elemento no acumulador (maior valor inicial)
INX H           ; Apontar para o pr�ximo elemento do arranjo
DCR C           ; Reduzir contador (j� usamos o primeiro elemento)

; Loop para encontrar o maior valor
FIND_MAX:
MOV B, M        ; Carregar pr�ximo elemento do arranjo em B
CMP B           ; Comparar com o maior valor atual (A)
JC NEXT         ; Se A >= B, continuar
MOV A, B        ; Atualizar o maior valor para o valor atual

NEXT:
INX H           ; Avan�ar para o pr�ximo elemento
DCR C           ; Reduzir contador
JNZ FIND_MAX    ; Repetir enquanto o contador n�o for 0

HLT             ; Parar o programa

; Dados na mem�ria
ORG 2050H
TAM: DB 05H        ; Tamanho do arranjo (5 elementos)
DADOS: DB 0FH, 1AH, 0CH, 1FH, 02H ; Arranjo de dados
