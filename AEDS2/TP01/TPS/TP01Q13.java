import java.util.Scanner;

public class TP01Q13 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int quant;
        int num, num2, num3;
        String frase;

        quant = sc.nextInt();

        while (quant != 0) {
            if (quant == 2) {
                num = sc.nextInt();
                num2 = sc.nextInt();
                frase = sc.nextLine();
                frase = modificaString(frase, num, num2, 0);
                System.out.println(algebra(frase));
            } else if (quant == 3) {
                num = sc.nextInt();
                num2 = sc.nextInt();
                num3 = sc.nextInt();
                frase = sc.nextLine();
                frase = modificaString(frase, num, num2, num3);
                System.out.println(algebra(frase));
            }
            quant = sc.nextInt();
        }
    }

    public static String modificaString(String frase, int num, int num2, int num3) {
        return modificaString_recusiva(frase, num, num2, num3, 0, new StringBuilder());
    }

    private static String modificaString_recusiva(String frase, int num, int num2, int num3, int i, StringBuilder modificada) {
        if (i >= frase.length()) {
            return modificada.toString();
        }

        char c = frase.charAt(i);
        if (c == 'a') {
            modificada.append(c);
            return modificaString_recusiva(frase, num, num2, num3, i + 3, modificada);
        } else if (c == 'o') {
            modificada.append(c);
            return modificaString_recusiva(frase, num, num2, num3, i + 2, modificada);
        } else if (c == 'n') {
            modificada.append(c);
            return modificaString_recusiva(frase, num, num2, num3, i + 3, modificada);
        } else if (c == 'A') {
            modificada.append(num);
        } else if (c == 'B') {
            modificada.append(num2);
        } else if (c == 'C') {
            modificada.append(num3);
        } else {
            modificada.append(c);
        }

        return modificaString_recusiva(frase, num, num2, num3, i + 1, modificada);
    }

    public static int algebra(String frase) {
        char[] fraseArray = frase.toCharArray();
        return algebra_recurisva(fraseArray, 0);
    }

    private static int algebra_recurisva(char[] fraseArray, int i) {
        if (i >= fraseArray.length) {
            return acharResultadoFinal(fraseArray, 0, new StringBuilder());
        }

        if (fraseArray[i] == ')') {
            fraseArray = pilha(fraseArray, i);
        }

        return algebra_recurisva(fraseArray, i + 1);
    }

    private static int acharResultadoFinal(char[] fraseArray, int i, StringBuilder resultado) {
        if (i >= fraseArray.length) {
            String finalResult = resultado.toString();
            return finalResult.isEmpty() ? 0 : Character.getNumericValue(finalResult.charAt(0));
        }

        if (fraseArray[i] == '0' || fraseArray[i] == '1') {
            resultado.append(fraseArray[i]);
        }

        return acharResultadoFinal(fraseArray, i + 1, resultado);
    }

    public static char[] pilha(char[] frase, int i) {
        return pilha_recursiva(frase, i, new char[300], 0);
    }

    private static char[] pilha_recursiva(char[] frase, int i, char[] resultado, int aux) {
        if (i < 0) {
            return frase;
        }

        resultado[aux] = frase[i];
        frase[i] = '\u0000';

        if (resultado[aux] == '(') {
            resultado[aux + 1] = frase[i - 1];
            int num;
            if (resultado[aux + 1] == 'a') {
                num = And(resultado);
            } else if (resultado[aux + 1] == 'o') {
                num = Or(resultado);
            } else if (resultado[aux + 1] == 'n') {
                num = Not(resultado);
            } else {
                return pilha_recursiva(frase, i - 1, resultado, aux + 1);
            }
            frase[i - 1] = (char) (num + 48);
            return frase;
        }

        return pilha_recursiva(frase, i - 1, resultado, aux + 1);
    }

    public static int And(char[] resultado) {
        return new String(resultado).contains("0") ? 0 : 1;
    }

    public static int Or(char[] resultado) {
        return new String(resultado).contains("1") ? 1 : 0;
    }

    public static int Not(char[] resultado) {
        return new String(resultado).contains("1") ? 0 : 1;
    }
}
