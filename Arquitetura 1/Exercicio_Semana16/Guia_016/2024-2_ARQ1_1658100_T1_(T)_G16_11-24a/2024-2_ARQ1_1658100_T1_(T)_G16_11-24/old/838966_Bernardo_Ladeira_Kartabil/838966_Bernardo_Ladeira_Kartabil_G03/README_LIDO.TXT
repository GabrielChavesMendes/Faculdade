Estou muito feliz com meu progresso no Verilog 
e na matéria arquitetura 1, 
consegui fazer esse TP sem muitas dificuldades!

Estava com dúvida no agrupamento, 
mas eu consegui entender!!!! Tanto que no exercício 2 até fiz as caixinhas com os bits!

Coloquei alguns comentários dos meus raciocínios, 
com o objetivo de mostrar o que eu aprendi no código.


Uma coisa que eu não entendi é a função do "underline" 
no meio do número binário:

reg signed [7:0] a = 8'b1111_1010; // binary 

OBS.: É UM SEPARADOR PARA AJUDAR NA LEITURA
 
Outra coisa que eu não entendi:

O "~", utilizado nos programas do ex1.v e ex3.v

     d = ~a+1; 
     e = ~(a-1); 
 
     d = ~b+1; 
     e = ~(b-1); 

     d = ~c+1; 
     e = ~(c-1); 


Eu não entendi o que significa;

OBS.: NEGAÇÃO.


No exercício 5, ele também é utilizado:

$display("0= %d = %3b = %3b",   ~1 , (1-1), ~(1*1) ); 
$display("1= %d = %3b = %3b",   ~0 , (2-1), ~(0*1) ); 
$display("2= %d = %3b = %3b", (1+1), (3-1), ~0+~0  ); 
