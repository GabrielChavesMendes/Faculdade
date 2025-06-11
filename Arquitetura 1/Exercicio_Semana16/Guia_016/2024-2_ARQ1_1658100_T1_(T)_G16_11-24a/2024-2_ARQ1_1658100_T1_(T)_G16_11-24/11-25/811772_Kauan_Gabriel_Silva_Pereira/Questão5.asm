; Programa: Convers�o de BCD para Hexadecimal
; Entrada: Valor BCD armazenado em MEMORIA (endere�ada por H e L)
; Sa�da: Resultado em Hexadecimal no acumulador (A)

ORG 2000H       ; In�cio do programa na mem�ria

; Inicializa��o
LXI H, MEMORIA  ; Carregar endere�o do valor BCD
MOV A, M        ; Carregar o valor BCD no acumulador

; Separar os d�gitos alto (HI) e baixo (LOW)
MOV B, A        ; Copiar valor BCD para B
ANI F0H         ; Isolar os 4 bits mais significativos (HI)
RRC             ; Deslocar bits para a direita
RRC
RRC
RRC             ; Agora, HI est� nos 4 bits menos significativos
MOV C, A        ; Armazenar HI em C

MOV A, B        ; Restaurar valor BCD
ANI 0FH         ; Isolar os 4 bits menos significativos (LOW)

; Multiplicar HI por 10 e somar LOW
MVI D, 0AH      ; Carregar o valor 10 em D
CALL MULTIPLY   ; Chamar sub-rotina de multiplica��o (HI * 10)

ADD A, C        ; Somar resultado de HI*10 com LOW

HLT             ; Parar o programa

; Sub-rotina: Multiplica��o
; Entrada: A = n�mero, D = multiplicador
; Sa�da: A = produto
MULTIPLY:
MVI B, 00H      ; Inicializar resultado (B = 0)
MULT_LOOP:
ADD A           ; Adicionar o valor original
DCR D           ; Decrementar o multiplicador
JNZ MULT_LOOP   ; Repetir at� multiplicador = 0
MOV A, B        ; Transferir resultado para A
RET             ; Retornar para o programa principal

; Dados na mem�ria
ORG 2050H
MEMORIA: DB 24H ; Valor BCD de entrada
