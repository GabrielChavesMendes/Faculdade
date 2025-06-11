package visao;
import entidades.Episodio;
import entidades.Serie;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

import aeds3.ParIdId;
import modelo.ArquivoEpisodios;
import modelo.ArquivoSeries;

public class MenuSeries {

    ArquivoSeries arqSeries;
    private static Scanner console = new Scanner(System.in);

    public MenuSeries() throws Exception {
        arqSeries = new ArquivoSeries();
    }

    public void menu() {

        int opcao;
        do {

            System.out.println("\n\nPUCFlix 1.0");
            System.out.println( "-----------");
            System.out.println("> Início > Séries");
            System.out.println("\n1 - Incluir");
            System.out.println("2 - Buscar");
            System.out.println("3 - Alterar");
            System.out.println("4 - Excluir");
            System.out.println("0 - Voltar ao menu anterior");

            System.out.print("\nOpção: ");
            try {
                opcao = Integer.valueOf(console.nextLine());
            } catch(NumberFormatException e) {
                opcao = -1;
            }

            switch (opcao) {
                case 1:
                    incluirSerie();
                    break;
                case 2:
                    buscarSerie();
                    break;
                case 3:
                    alterarSerie();
                    break;
                case 4:
                    excluirSerie();
                    break;
                case 0:
                    break;
                default:
                    System.out.println("Opção inválida!");
                    break;
            }

        } while (opcao != 0);
    }

    public void incluirSerie() {
        System.out.println("\nInclusão de série");
        String nome = "";
        String sinopse = "";
        LocalDate dataLancamento = null;
        String streaming = "";
        boolean dadosCorretos = false;
        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy");

        dadosCorretos = false;
        do {
            System.out.print("Nome (min. de 4 letras): ");
            nome = console.nextLine();
            if(nome.length()>=4)
                dadosCorretos = true;
            else
                System.err.println("O nome da série deve ter no mínimo 4 caracteres.");
        } while(!dadosCorretos);

        dadosCorretos = false;
        do {
            System.out.print("Sinopse (min. de 4 letras): ");
            sinopse = console.nextLine();
            if(sinopse.length()>=4)
                dadosCorretos = true;
            else
                System.err.println("A sinopse deve ter no mínimo 4 caracteres.");
        } while(!dadosCorretos);

        dadosCorretos = false;
        do {
            System.out.print("Data de lançamento (DD/MM/AAAA): ");
            String dataStr = console.nextLine();
            try {
                dataLancamento = LocalDate.parse(dataStr, formatter);
                dadosCorretos = true;
            } catch (Exception e) {
                System.err.println("Data inválida! Use o formato DD/MM/AAAA.");
            }
        } while(!dadosCorretos);

        dadosCorretos = false;
        do {
            System.out.print("Streaming (min. de 4 letras): ");
            streaming = console.nextLine();
            if(streaming.length()>=4)
                dadosCorretos = true;
            else
                System.err.println("O nome do Streaming deve ter no mínimo 4 caracteres.");
        } while(!dadosCorretos);

        System.out.print("\nConfirma a inclusão da série? (S/N) ");
        char resp = console.nextLine().charAt(0);
        if(resp=='S' || resp=='s') {
            try {
                Serie c = new Serie(nome, sinopse, dataLancamento, streaming);
                arqSeries.create(c);
                System.out.println("Série incluída com sucesso.");
            } catch(Exception e) {
                System.out.println("Erro do sistema. Não foi possível incluir a série!");
            }
        }
    }

    public void buscarSerie() {
        System.out.println("\nBusca de série por nome");
        System.out.print("\nNome: ");
        String nome = console.nextLine(); 
        if(nome.isEmpty())
            return; 

        try {
            Serie[] series = arqSeries.readNome(nome);  
            if (series.length>0) {
                int n=1;
                for(Serie s : series) {
                    System.out.println((n++)+": "+s);
                }
                System.out.print("Escolha a série: ");
                int o;
                do { 
                    try {
                        o = Integer.valueOf(console.nextLine());
                    } catch(NumberFormatException e) {
                        o = -1;
                    }
                    if(o<=0 || o>n-1)
                        System.out.println("Escolha um número entre 1 e "+(n-1));
                }while(o<=0 || o>n-1);
                mostraSerie(series[o-1]);
            } else {
                System.out.println("Nenhuma série encontrada.");
            }
        } catch(Exception e) {
            System.out.println("Erro do sistema. Não foi possível buscar as séries!");
            e.printStackTrace();
        }
    }

    public void mostraSerie(Serie serie) {
        if (serie != null) {
            System.out.println("\n----------------------");
            System.out.printf("Nome......: %s%n", serie.getNome());
            System.out.printf("Sinopse.....: %s%n", serie.getSinopse());
            System.out.printf("Lançamento: %s%n", serie.getDataLancamento().format(DateTimeFormatter.ofPattern("dd/MM/yyyy")));
            System.out.printf("Streaming.....: R$ %s%n", serie.getStreaming());
            System.out.println("----------------------\n");
        }
    }

    public void alterarSerie() {
        System.out.println("\nAlteração de série");
        System.out.print("\nNome da série a ser alterada: ");
        String nome = console.nextLine();  
        if(nome.isEmpty()) {
            System.out.println("Nome vazio ou inválido!");
            return;
        }
    
        try {
            Serie[] series = arqSeries.readNome(nome); 
            if (series.length > 0) {//verifica se algum nome foi encontrado no arquivo
                int n = 1;
                for (Serie s : series) {
                    System.out.println((n++) + ": " + s);
                }
    
                System.out.print("Escolha a série para alterar: ");
                int o;
                do { 
                    try {
                        o = Integer.valueOf(console.nextLine());
                    } catch (NumberFormatException e) {
                        o = -1;
                    }
                    if(o <= 0 || o > n-1)
                        System.out.println("Escolha um número entre 1 e " + (n-1));
                } while(o <= 0 || o > n-1);
    
                Serie serieSelecionada = series[o - 1];
                System.out.println("Alterando a série: " + serieSelecionada);
    
                String novoNome = "";
                String novaSinopse = "";
                LocalDate novaDataLancamento = null;
                String novoStreaming = "";
    
                System.out.print("Novo nome (deixe em branco para manter): ");
                novoNome = console.nextLine();
                if (!novoNome.isEmpty()) {
                    serieSelecionada.setNome(novoNome);
                }
    
                System.out.print("Nova sinopse (deixe em branco para manter): ");
                novaSinopse = console.nextLine();
                if (!novaSinopse.isEmpty()) {
                    serieSelecionada.setSinopse(novaSinopse);
                }
    
                System.out.print("Nova data de lançamento (DD/MM/AAAA) ou deixe em branco para manter: ");
                String dataStr = console.nextLine();
                if (!dataStr.isEmpty()) {
                    try {
                        novaDataLancamento = LocalDate.parse(dataStr, DateTimeFormatter.ofPattern("dd/MM/yyyy"));
                        serieSelecionada.setDataLancamento(novaDataLancamento);
                    } catch (Exception e) {
                        System.err.println("Data inválida! Manterá a data anterior.");
                    }
                }
    
                System.out.print("Novo nome do streaming (deixe em branco para manter): ");
                novoStreaming = console.nextLine();
                if (!novoStreaming.isEmpty()) {
                    serieSelecionada.setStreaming(novoStreaming);
                }
    
                System.out.print("\nConfirma a alteração da série? (S/N) ");
                char resp = console.nextLine().charAt(0);
                if (resp == 'S' || resp == 's') {
                    try {
                        arqSeries.update(serieSelecionada); 
                        System.out.println("Série alterada com sucesso.");
                    } catch (Exception e) {
                        System.out.println("Erro do sistema. Não foi possível alterar a série!");
                    }
                }
            } else {
                System.out.println("Nenhuma série encontrada com esse nome.");
            }
        } catch (Exception e) {
            System.out.println("Erro do sistema. Não foi possível buscar a série!");
            e.printStackTrace();
        }
    }

public void excluirSerie() {
    System.out.println("\nExclusão de série");
    System.out.print("\nNome da série a ser excluída: ");
    String nome = console.nextLine();  
    if (nome.isEmpty()) {
        System.out.println("Nome vazio ou inválido!");
        return;
    }
    
    try {
        // Buscar a série pelo nome
        Serie[] series = arqSeries.readNome(nome);
        
        if (series == null || series.length == 0) {
            System.out.println("Nenhuma série encontrada com esse nome.");
            return;
        }
        
        // Se houver mais de uma série com o mesmo nome
        Serie serieSelecionada;
        if (series.length > 1) {
            System.out.println("\nForam encontradas várias séries:");
            for (int i = 0; i < series.length; i++) {
                System.out.println((i+1) + " - " + series[i].getNome() + 
                                 " (ID: " + series[i].getID() + ")");
            }
            
            System.out.print("\nSelecione a série desejada (1-" + series.length + "): ");
            int escolha;
            try {
                escolha = Integer.parseInt(console.nextLine());
                if (escolha < 1 || escolha > series.length) {
                    System.out.println("Opção inválida. Operação cancelada.");
                    return;
                }
                serieSelecionada = series[escolha-1];
            } catch (NumberFormatException e) {
                System.out.println("Número inválido. Operação cancelada.");
                return;
            }
        } else {
            serieSelecionada = series[0];
        }
        
        // Verificar se há episódios vinculados a esta série
        ArquivoEpisodios arqEpisodios = new ArquivoEpisodios();
        ArrayList<ParIdId> pii = arqEpisodios.getAllEpisodesFromSerie(serieSelecionada.getID());
        if (!pii.isEmpty()) {
            System.out.println("\nEsta série não pode ser excluída porque possui " + 
                             pii.size() + " episódio(s) vinculado(s).");
            System.out.println("Exclua primeiro todos os episódios da série.");
            return;
        }
        
        // Confirmar exclusão
        System.out.print("\nConfirma a exclusão da série '" + serieSelecionada.getNome() + "'? (S/N) ");
        char resp = console.nextLine().charAt(0);
        if (resp == 'S' || resp == 's') {
            if (arqSeries.delete(serieSelecionada.getID())) {
                System.out.println("Série excluída com sucesso!");
            } else {
                System.out.println("Erro ao excluir a série.");
            }
        } else {
            System.out.println("Operação cancelada.");
        }
        
    } catch (Exception e) {
        System.out.println("Erro ao tentar excluir a série: " + e.getMessage());
        e.printStackTrace();
    }
}

}
