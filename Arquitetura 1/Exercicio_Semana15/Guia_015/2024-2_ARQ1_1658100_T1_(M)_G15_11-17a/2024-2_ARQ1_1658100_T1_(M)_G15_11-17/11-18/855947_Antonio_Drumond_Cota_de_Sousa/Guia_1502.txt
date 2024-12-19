;855947 - Antonio Drumond Cota de Sousa
;Valores iniciais guardados em C0E0 e abaixo
;Resultado final guardado em C113

;Carregar os 4 valores, em duas unidades de memoria cada

LXI H,C0E0
MVI M,1BH
LXI H,C0E1
MVI M,EF

LXI H,C0F0
MVI M,45H
LXI H,C0F1
MVI M,54H

LXI H,C100
MVI M,8BH
LXI H,C101
MVI M,C7

LXI H,C110
MVI M,4EH
LXI H,C111
MVI M,F5

; Somas
LDA C0E1
LXI H,C0F1
ADD M

LXI H,C0E4
MOV M,A

LDA C0E0
JNC AFTER1
INR A
AFTER1: LXI H,C0F0
ADD M

STA C0E3

LXI H,C0E4
MOV A,M
LXI H,C101
ADD M
STA C0E4

LXI H,C100
MOV A,M
JNC AFTER2
INR A
AFTER2: LXI H,C0E3
ADD M
STA C0E3

;Subtracao
;Calcular o Complemento de 2 do numero a ser subtraido e guardar em C0F3

LXI H,C111
MOV A,M
CMA
MOV B,A
INR B

LXI H,C110
MOV A,M
CMA
JNC AFTER3
INR A
AFTER3: STA C0F3
LXI H,C0F4
MOV M,B

;Subtrair somando com o complemento de 2, guardar resultado em C113
LDA C0E4
LXI H,C0F4
ADD M
STA C114

LDA C0E3
JNC AFTER4
INR A
AFTER4: LXI H,C0F3
ADD M
STA C113

HLT
