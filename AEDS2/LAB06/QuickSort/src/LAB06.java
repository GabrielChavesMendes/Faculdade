import java.util.Scanner;
import java.util.Random;

public class LAB06 {

    static void swap(int[] array, int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    static void QuickSortFirstPivot (int [] array , int left , int right ){ //Pivo no incio
        int i = left, j = right, pivo = array[left];
           
        while (i <= j) {
            
            while (array[i] < pivo){
                i++;
            }

            while (array[j] > pivo){
                j--;
            }

            if (i <= j){ 
                swap(array, i, j);
                i++; 
                j--; 
            }
        }

        if (left < j){
            QuickSortFirstPivot(array, left, j);
        }

        if (i < right){
            QuickSortFirstPivot(array, i, right);
        }
     }


    static void QuickSortLastPivot (int [] array , int left , int right ){ //Pivo no final
        int i = left, j = right, pivo = array[right];
           
        while (i <= j) {
        
            while (array[i] < pivo){
                i++;
            }

            while (array[j] > pivo){
                j--;
            }

            if (i <= j){ 
                swap(array, i, j);
                i++; 
                j--; 
            }
        }

        if (left < j){
            QuickSortLastPivot(array, left, j);
        }

        if (i < right){
            QuickSortLastPivot(array, i, right);
        }
    }

    static void QuickSortRandomPivot(int[] array, int left, int right) { //Pivo aleatorio
        if (left < right) {
            
            Random rand = new Random();
            int index_Aleatorio = left + rand.nextInt(right - left + 1);
            int pivo = array[index_Aleatorio];

            // Troca o pivô aleatório com o último elemento
            swap(array, index_Aleatorio, right);

            int i = left, j = right - 1;

            while (i <= j) {
                while (i <= j && array[i] < pivo) {
                    i++;
                }

                while (i <= j && array[j] > pivo) {
                    j--;
                }

                if (i <= j) {
                    swap(array, i, j);
                    i++;
                    j--;
                }
            }

            swap(array, i, right);

            QuickSortRandomPivot(array, left, i - 1);
            QuickSortRandomPivot(array, i + 1, right);
        }
    }

    static void QuickSortMedianOfThree(int [] array , int left , int right ){ //Pivo media de tres
        int meio = (left + right) / 2;

        if (array[left] > array[meio]) {
            swap(array, left, meio);
        }
        if (array[left] > array[right]) {
            swap(array, left, right);
        }
        if (array[meio] > array[right]) {
            swap(array, meio, right);
        }
    
        int pivo = array[meio];
    
       
        int i = left, j = right;
         
        while (i <= j) {
        
            while (array[i] < pivo){
                i++;
            }

            while (array[j] > pivo){
                j--;
            }

            if (i <= j){ 
                swap(array, i, j);
                i++; 
                j--; 
            }
        }

        if (left < j){
            QuickSortMedianOfThree(array, left, j);
        }

        if (i < right){
            QuickSortMedianOfThree(array, i, right);
        }
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        Random rand = new Random();

        int escolha;
        int left, right; 
        int array1[] = new int[10]; //aleatorio
        int array2[] = {1, 2, 5, 4, 3, 6, 10, 9, 8, 7, 11, 12, 14, 13, 15}; //quase ordenado
        int array3[] = new int[20]; //ordenado

        for(int i = 0; i < 10; i++){
            array1[i] = rand.nextInt(100);
        }

        for(int i = 0; i < 10; i++){
            array3[i] = i;
        }

        System.out.println("Escolha entre as opcoes de implementacao de QuickSort:");
        System.out.println("1  - Pivo no inicio (aleatorio)          4  - Pivo no final (aleatorio)          7  - Pivo aleatorio (aleatorio)          10 - Pivo mediano (aleatorio)");
        System.out.println("2  - Pivo no inicio (quase ordenado)     5  - Pivo no final (quase ordenado)     8  - Pivo aleatorio (quase ordenado)     11 - Pivo mediano (quase ordenado)");
        System.out.println("3  - Pivo no inicio (ordenado)           6  - Pivo no final (ordenado)           9  - Pivo aleatorio (ordenado)           12 - Pivo mediano (ordenado)");
        System.out.println("Digite 0 para sair.");

        escolha = sc.nextInt();

        left = 0; 
        right = array1.length - 1;
        long startTime, endTime;
        double duration;

        switch(escolha){ 
            case 1:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array1[i] + " ");
                }
                System.out.println();
        
                //Medir o tempo de execução
                startTime = System.nanoTime();  // Medir em nanosegundos
                QuickSortFirstPivot(array1, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0;  
        
                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array1[i] + " ");
                }
                System.out.println();
        
                System.out.println("Tempo de execucao: " + duration  + " ms"); // 0.0068 ms
                break;

            case 2:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array2[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortFirstPivot(array2, left, right); 
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array2[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.0077 ms
                break;

            case 3:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array3[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortFirstPivot(array3, left, right); 
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array3[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.0067 ms
                break;
                    
            case 4:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array1[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortLastPivot(array1, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array1[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.006099 ms
                break;

            case 5:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array2[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortLastPivot(array2, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array2[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.006501 ms
                break;
                
            case 6:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array3[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortLastPivot(array3, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array3[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.006499 ms
                break;

            case 7:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array1[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortRandomPivot(array1, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array1[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.027699 ms
                break;

            case 8: 
               //Vetor desordenado
               System.out.println("Array antes:");
               for (int i = 0; i < 10; i++) {
                   System.out.print(array2[i] + " ");
               }
               System.out.println();

               //Medir o tempo de execução
               startTime = System.nanoTime();
               QuickSortRandomPivot(array2, left, right);
               endTime = System.nanoTime();
               duration = (endTime - startTime) / 1_000_000.0; 

               //Vetor ordenado
               System.out.println("Array depois:");
               for (int i = 0; i < 10; i++) {
                   System.out.print(array2[i] + " ");
               }
               System.out.println();

               System.out.println("Tempo de execucao: " + duration + " ms"); //0.0427 ms
               break;

            case 9: 
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array3[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortRandomPivot(array3, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array3[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.059899 ms
                break;

            case 10:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array1[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortMedianOfThree(array1, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array1[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.0076 ms
                break;

            case 11:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array2[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortMedianOfThree(array2, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array2[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.0061 ms
                break;

            case 12:
                //Vetor desordenado
                System.out.println("Array antes:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array3[i] + " ");
                }
                System.out.println();

                //Medir o tempo de execução
                startTime = System.nanoTime();
                QuickSortMedianOfThree(array3, left, right);
                endTime = System.nanoTime();
                duration = (endTime - startTime) / 1_000_000.0; 

                //Vetor ordenado
                System.out.println("Array depois:");
                for (int i = 0; i < 10; i++) {
                    System.out.print(array3[i] + " ");
                }
                System.out.println();

                System.out.println("Tempo de execucao: " + duration + " ms"); //0.007201 ms
                break;

            default:
                System.out.println("Invalido\n");;

            }
            
        sc.close();
    }
}
