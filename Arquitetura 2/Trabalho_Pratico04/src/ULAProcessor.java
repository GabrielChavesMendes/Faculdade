import java.nio.file.*;

public class ULAProcessor {
    
    // Mapeia operações para códigos hexadecimais
    private static char getOperationCode(String operation) {
        switch (operation.toLowerCase()) {
            case "zerol":    return '0';
            case "uml":      return '1';
            case "copiaa":   return '2';
            case "copiab":   return '3';
            case "na":      return '4';
            case "nb":      return '5';
            case "aenb":    return '6';
            case "naeb":     return '7';
            case "axb":      return '8';
            case "naxnb":    return '9';
            case "naxnbn":   return 'A';
            case "aeb":     return 'B';
            case "aebn":     return 'C';
            case "aobn":     return 'D';
            case "aob":      return 'E';
            case "naonbn":  return 'F';
            default:        return 'X'; // Operação inválida
        }
    }

    public static void main(String[] args) {
        String[] registers = {"0", "0", "0"}; // X, Y, W
        
        try {
            // Ler todas as linhas do arquivo de uma vez
            var inputLines = Files.readAllLines(Paths.get("src/testeula.ula"));
            var outputWriter = Files.newBufferedWriter(Paths.get("testeula.hex"));

            for (String line : inputLines) {
                if (line.isEmpty()) continue;
                
                String[] parts = line.split("=");
                if (parts.length < 2) continue;
                
                String value = parts[1].replace(";", "").trim();
                
                // Processar cada comando
                switch (parts[0].toLowerCase()) {
                    case "x":
                        registers[0] = value;
                        break;
                    case "y":
                        registers[1] = value;
                        break;
                    case "w":
                        registers[2] = String.valueOf(getOperationCode(value));
                        // Escrever no formato: XY<operação>
                        outputWriter.write(registers[0] + registers[1] + registers[2]);
                        outputWriter.newLine();
                        break;
                }
            }
            
            outputWriter.close();
        } catch (Exception e) {
            System.out.println("Erro durante processamento: " + e.getMessage());
        }
    }
}