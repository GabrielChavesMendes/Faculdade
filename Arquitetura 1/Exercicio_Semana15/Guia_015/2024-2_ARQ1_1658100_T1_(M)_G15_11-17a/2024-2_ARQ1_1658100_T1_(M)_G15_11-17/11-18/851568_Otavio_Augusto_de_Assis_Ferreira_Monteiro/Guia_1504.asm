;Aluno - Otávio Augusto de Assis Ferreira Monteiro
;Matricula - 851568


JMP MAIN

LOADER:	MVI A,A3
	STA C060

	MVI A,3F
	STA C070

	RET


MAIN:	CALL LOADER
	LDA C070
	ADD A ; 
	MOV B,A
	
	LDA C060
	SUB B ; 

	ADD A ;

	STA C062

HLT