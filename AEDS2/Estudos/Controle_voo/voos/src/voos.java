import java.util.*;

class Aviao{
    String [] leste = new String[10];
    String [] oeste = new String[10];
    String [] sul = new String[10];
    String [] norte = new String[10];

    public Aviao(String[] leste, String[] oeste, String[] sul, String[] norte) {
        this.leste = leste;
        this.oeste = oeste;
        this.sul = sul;
        this.norte = norte;
    }

    public String[] getLeste() {
        return leste;
    }

    public void setLeste(String[] leste) {
        this.leste = leste;
    }

    public String[] getOeste() {
        return oeste;
    }

    public void setOeste(String[] oeste) {
        this.oeste = oeste;
    }

    public String[] getSul() {
        return sul;
    }

    public void setSul(String[] sul) {
        this.sul = sul;
    }

    public String[] getNorte() {
        return norte;
    }

    public void setNorte(String[] norte) {
        this.norte = norte;
    }
}

public class voos {
    public static void main(String[] args) throws Exception {

        Aviao voo = new Aviao(args, args, args, args);
        
        Scanner sc = new Scanner(System.in);

        String entrada;
        boolean fim = true;

        while(fim){
            entrada = sc.nextLine();
            int posicao = Integer.parseInt(entrada);
            String entrada2;

            if(posicao == -1){
                entrada2 = sc.nextLine();
                int confere = Integer.parseInt(entrada2);
                while(confere != -2 || confere != -3 || confere != -4){
                    voo.setOeste(entrada2);
                    entrada2 = sc.nextLine();
                }
            }
        }

        sc.close();
    }
}
