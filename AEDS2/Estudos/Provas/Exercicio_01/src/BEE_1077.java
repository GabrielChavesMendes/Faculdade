import java.util.Scanner;
import java.util.ArrayList;

public class BEE_1077 {

    static class Infixa{
        private int num;
        private String expressao;
        private ArrayList <String> variavel = new ArrayList<>();
        private ArrayList <String> comandos = new ArrayList<>();

        Infixa(){
            this.num = 0;
            this.expressao = " ";
            this.variavel = new ArrayList<>();
            this.comandos = new ArrayList<>();
        }

        int getNum(){
            return this.num;
        }

        void setNum(int num){
            this.num = num;
        }

        String getExpressao(){
            return this.expressao;
        }

        void setExpressao(String expressao){
            this.expressao = expressao;
        }

        ArrayList<String> getVariavel(){
            return this.variavel;
        }

        void setVariavel(String c){
                    this.variavel.add(c);
        }

        ArrayList<String> getComando(){
            return this.comandos;
        }

        void setComando(String comando){
            this.comandos.add(comando);
        }
    }

    static void Separa(Infixa infixa){

        for(int i = 0; i < infixa.getExpressao().length(); i++){
            char c = infixa.getExpressao().charAt(i);
            
            
            if(Character.isLetter(c) || Character.isDigit(c)){
                //Se for letra ou numero coloca no ArrayList Variavel
                infixa.setVariavel(String.valueOf(c)); 

            }else if(c == '/' || c == '*' || c == '+' || c == '-' || c == '^'){
                //Se for simbolos coloca no ArrayList Comando
                infixa.setComando(String.valueOf(c)); 
            }
        }
    }

    static void ImprimiPosfixa(Infixa infixa) {
        int cont_var = 0; // Contador para variáveis

        // Percorre a lista de comandos
        for (String comando : infixa.getComando()) {
            // Se for um operador de multiplicação ou divisão
            if (comando.equals("*") || comando.equals("/") || comando.equals("^")) {
                if (cont_var < infixa.getVariavel().size()) {
                    System.out.print(infixa.getVariavel().get(cont_var)); // Imprime a variável
                    cont_var++;
                }
                if (cont_var < infixa.getVariavel().size()) {
                    System.out.print(infixa.getVariavel().get(cont_var)); // Imprime a próxima variável
                    cont_var++;
                }
                System.out.print(comando); // Imprime o comando
            }
            // Se for um operador de adição ou subtração
            else if (comando.equals("+") || comando.equals("-")) {
                if (cont_var < infixa.getVariavel().size()) {
                    System.out.print(infixa.getVariavel().get(cont_var)); // Imprime a variável
                    cont_var++;
                }
                System.out.print(comando); // Imprime o comando
            }
        }

        // Verifica se ainda existem variáveis para imprimir
        while (cont_var < infixa.getVariavel().size()) {
            System.out.print(infixa.getVariavel().get(cont_var));
            cont_var++;
        }

        System.out.println(); // Nova linha após a impressão da expressão
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);

        Infixa infixa = new Infixa();

        int n = sc.nextInt();
        String expressao;

        infixa.setNum(n);

        for(int i = 0; i < infixa.getNum(); i++){

            sc.nextLine();
            expressao = sc.nextLine();
            infixa.setExpressao(expressao);

            Separa(infixa);

            ImprimiPosfixa(infixa);
        }        
        
        sc.close();
    }
}
