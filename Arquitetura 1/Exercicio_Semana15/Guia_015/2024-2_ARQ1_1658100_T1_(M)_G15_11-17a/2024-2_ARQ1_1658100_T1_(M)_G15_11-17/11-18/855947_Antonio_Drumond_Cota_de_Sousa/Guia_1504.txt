;855947 - Antonio Drumond Cota de Sousa

JMP MAIN

LOADER:	MVI A,A3
	STA C060

	MVI A,3F
	STA C070

	RET


MAIN:	CALL LOADER
	LDA C070
	ADD A ; Duplica  segundo valor
	MOV B,A
	
	LDA C060
	SUB B ; Subtrai do primeiro valor o dobro do primeiro

	ADD A ; Duplica pela ultima vez

	STA C062

HLT
