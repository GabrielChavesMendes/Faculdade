Guia_1502
800736 - João Marcos

LXI H, dado01  ; HL <- endereço de dado01
MOV A, M       ; A <- MEM[HL] (dado01)
MOV B, A
ADD B          ; A <- A + A (dobro de A)
MOV B, A
ADD B          ; A <- A + A (quádruplo de A)
INX H          ; HL <- HL + 1 (endereço de dado02)
MOV B, M       ; B <- MEM[HL] (dado02)
MOV C, B
RRC            ; B <- B / 2 (deslocamento à direita)
ADD C          ; A <- A + B
STA dado03     ; MEM[dado03] <- A (resultado)
HLT            ; parar

; Área de dados
dado01: DB 03h ; exemplo de valor para dado01
dado02: DB 04h ; exemplo de valor para dado02
dado03: DB 00h ; resultado (inicializado com zero)