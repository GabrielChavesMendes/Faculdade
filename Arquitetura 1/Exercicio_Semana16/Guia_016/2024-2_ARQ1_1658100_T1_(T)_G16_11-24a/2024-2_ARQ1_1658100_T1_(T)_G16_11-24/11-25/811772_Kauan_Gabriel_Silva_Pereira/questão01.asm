; Programa: Multiplicação usando somas sucessivas
; Multiplicador: DADO01 (em 8 bits)
; Multiplicando: DADO02 (em 8 bits)
; Resultado: armazenado no par de registradores D (MSB) e E 

; Definir os dados
LXI H, DADOS    ; Carregar endereço dos dados
MOV A, M        ; Carregar DADO01 no acumulador (Multiplicador)
INX H           ; Incrementar endereço para próximo dado
MOV B, M        ; Carregar DADO02 em B (Multiplicando)

; Inicializar resultado como 0
MVI D, 00H      ; Parte alta do resultado (MSB)
MVI E, 00H      ; Parte baixa do resultado (LSB)

; Loop de somas sucessivas
MUL_LOOP:
CMP B           ; Comparar DADO02 com 0
JZ END_LOOP     ; Se DADO02 = 0, sair do loop
MOV A, E        ; Carregar parte baixa do resultado em A
ADD M           ; Adicionar DADO01 à parte baixa do resultado
MOV E, A        ; Armazenar novo valor da parte baixa
JC INC_MSB      ; Se houver carry, incrementar MSB

MOV A, D        ; Carregar MSB do resultado em A
JMP NEXT_STEP   ; Continuar para o próximo passo

INC_MSB:
INR D           ; Incrementar MSB do resultado

NEXT_STEP:
DCR B           ; Decrementar DADO02 (multiplicando)
JMP MUL_LOOP    ; Repetir o loop

END_LOOP:
HLT             ; Parar o programa

; Dados na memória


