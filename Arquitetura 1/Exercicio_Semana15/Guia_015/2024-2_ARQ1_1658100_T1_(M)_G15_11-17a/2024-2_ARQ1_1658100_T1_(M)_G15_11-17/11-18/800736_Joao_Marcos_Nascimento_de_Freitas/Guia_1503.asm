LXI H, dado01  ; HL <- endereço de dado01
MOV A, M       ; A <- MEM[HL] (dado01)
INX H          ; HL <- HL + 1 (endereço de dado02)
ADD M          ; A <- A + MEM[HL] (dado02)
DAA            ; ajustar BCD se necessário
INX H          ; HL <- HL + 1 (endereço de dado03)
ADD M          ; A <- A + MEM[HL] (dado03)
DAA            ; ajustar BCD se necessário
STA dado04     ; MEM[dado04] <- A (resultado)
HLT            ; parar

; Área de dados
dado01: DB 12h ; exemplo de valor para dado01 (BCD)
dado02: DB 34h ; exemplo de valor para dado02 (BCD)
dado03: DB 56h ; exemplo de valor para dado03 (BCD)
dado04: DB 00h ; resultado (inicializado com zero)