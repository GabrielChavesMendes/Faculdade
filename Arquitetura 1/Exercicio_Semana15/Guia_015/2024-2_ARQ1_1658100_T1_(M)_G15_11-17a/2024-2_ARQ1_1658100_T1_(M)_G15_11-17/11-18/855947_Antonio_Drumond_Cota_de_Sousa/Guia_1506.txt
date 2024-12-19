; Antonio Drumond Cota de Sousa - 855947

JMP MAIN

LOADER:	MVI A,28
	STA C0C0
	MVI A,3A
	STA C0D0
	RET

BXC:  	MVI A,00
BACK:   	ADD B
	DCR C
	JNZ BACK

	RET 

MAIN:	CALL LOADER

	; Multiplicar primeiro valor por 3
	LXI H,C0C0
	MOV B,M
	MVI C,03
	CALL BXC
	STA C0C2

	; Multiplicar segundo valor por 2
	LXI H,C0D0
	MOV B,M
	MVI C,02
	CALL BXC
	STA C0D2

	; Subtrair os produtos
	LDA C0C2
	LXI H,C0D2
	SUB M
	STA C0C4
HLT