; Antonio Drumond Cota de Sousa - 855947

JMP MAIN

LOADER: 	MVI A,0C
	STA C0C0

	MVI A,32
	STA C0D0

	RET


HALFA:	MVI B,FE	;1111 1110
	ANA B
	RRC	; Divide por 2

	RET


MULTI:	MVI A,00
BACK:	ADD B
	DCR C
	JNZ BACK

	RET



MAIN:	CALL LOADER

	; Calcular 8 * dado01 (guardado em C0C0)
	MVI C,08
	LXI H,C0C0
	MOV B,M
	CALL MULTI
	STA C0C2	; Grava o resultado da multiplicacao

	; Calcular dado02 / 2
	STA C0D0
	CALL HALFA
	STA C0D2

	LXI H,C0C2	; Soma final
	ADD M
	STA C0C4	; Resultado final

HLT
