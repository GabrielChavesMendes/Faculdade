;855947 - Antonio Drumond Cota de Sousa

; Guardar valores 1 a 3 nos enderecos C020 a C022
MVI B,45H
LXI H,C120
MOV M,B

MVI B,A8H
LXI H,C121
MOV M,B

MVI B,6AH
LXI H,C122
MOV M,B

MVI B,A8H
LXI H,C121
MOV M,B

;Adicionar primeiro valor
LXI H,C120
MOV B,M
ADD B

;Adicionar segundo valor
LXI H,C121
MOV B,M
ADD B

;Subtrair terceiro valor
LXI H,C122
MOV B,M
SUB B

;Guardar resultado na posicao C123
LXI H,C123
MOV M,A

HLT
