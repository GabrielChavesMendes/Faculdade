#include <stdio.h>
#include <string.h>

struct Passagens {
    int ID;
    char Origem[4];
    char Destino[4];
    char Cidadeorg[50];
    char Cidadedest[50];
    char Data[11];
    char Hpartida[6];
    char Hchegada[6];
    float Valor;
};

//-------------------------------**-------------------------------//
/*==================================================*
|       Função para remover caracteres extras       |
*==================================================*/
void limparBuffer(){
  char c;
  while((c = getchar()) != '\n' && c != EOF); //c recebe um caracter e verifica se não é um \n ou é o final do arquivo (EOF)
}

//-------------------------------**-------------------------------//
/*==================================================*
|       Função para Menu de Escolhas                |
*==================================================*/
void exibirMenu() {
    //Esta função é o menu principal do arquivo, puxado no MAIN
    printf("Menu:\n"
           "1) Listar todas as passagens\n"
           "2) Pesquisar uma passagem\n"
           "3) Cadastrar uma passagem\n"
           "4) Editar uma passagem\n"
           "5) Excluir uma passagem\n"
           "6) Sair do programa\n"
           "Digite de 1 a 6 qual função do Menu será executada: ");
}

//-------------------------------**-------------------------------//
/*==================================================*
|     Função1 (Listagem de Todas as Passagens)      |
*==================================================*/
void listarPassagens(struct Passagens *passagens, int quantidadePassagens) {
    printf("Listagem de Passagens:\n");

    //O loop irá continuar até o total de passagens, valor atribuido em "quantidadePassagens" e printar todas as informações
    for (int i = 0; i < quantidadePassagens; i++) {
            printf("ID: %d,\n"
                "Origem: %s,\n"
                "Destino: %s,\n"
                "Cidade Origem: %s,\n"
                "Cidade Destino: %s,\n"
                "Data: %s,\n"
                "Hora Partida: %s,\n"
                "Hora Chegada: %s,\n"
                "Valor: %.2f\n\n",
                passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
                passagens[i].Cidadeorg, passagens[i].Cidadedest,
                passagens[i].Data,
                passagens[i].Hpartida,
                passagens[i].Hchegada,
                passagens[i].Valor);
    }
}

//-------------------------------**-------------------------------//
/*==================================================*
|    Função2 (Menu para Pesquisa de uma Passagem)   |
*==================================================*/
void menuPesquisa(){
  //Função para criar um menu, que servirá para propor ao usuário escolhas de como Pesquisar uma Passsagem
  //Esta função é chamada no Main
  printf("Menu de Pesquisas:\n"
         "1) Pesquisar por ID\n"
         "2) Pesquisar por Código de Origem\n"
         "3) Pesquisar por Código de Destino\n"
         "4) Pesquisar por Cidade de Origem\n"
         "5) Pesquisar por Cidade de Destino\n"
         "Escolha uma opção de 1 a 5 para pesquisar a passagem: ");
}

/*==================================================*
|      Função 2 (Pesquisa de Passagem por ID)       |
*==================================================*/
void pesquisarPassagem(struct Passagens *passagens, int quantidadePassagens, int idPesquisa) {
    for (int i = 0; i < quantidadePassagens; i++) {
        if (passagens[i].ID == idPesquisa) { //Verifica se o ID no ídice i é igual ao ID fornecido pelo usuário
            printf("Passagem encontrada por ID %d:\n", idPesquisa);
            printf("ID: %d,\n"
                "Origem: %s,\n"
                "Destino: %s,\n"
                "Cidade Origem: %s,\n"
                "Cidade Destino: %s,\n"
                "Data: %s,\n"
                "Hora Partida: %s,\n"
                "Hora Chegada: %s,\n"
                "Valor: %.2f\n",
                    passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
                    passagens[i].Cidadeorg, passagens[i].Cidadedest,
                    passagens[i].Data,
                    passagens[i].Hpartida,
                    passagens[i].Hchegada,
                    passagens[i].Valor);
            return;
        }
    }

    printf("Passagem com ID %d não encontrada.\n", idPesquisa);
}

/*=====================================================*
| Função 2 (Pesquisa de Passagem por Código de Origem) |
*=====================================================*/
void pesquisarPassagemPorCodigoOrigem(struct Passagens *passagens, int quantidadePassagens, const char *codigoOrigem) {
    printf("Passagens com Código de Origem %s:\n", codigoOrigem);

    int encontrou = 0; //Variável de parâmetro que verifica se a passagem foi encontrada ou não

    for (int i = 0; i < quantidadePassagens; i++) {
        if (strcmp(passagens[i].Origem, codigoOrigem) == 0){ //Verifica se o código no parâmetro i é igual ao fornecido e com o uso do strcmp compara se as strings são iguai e retorna 0 se for
            printf("ID: %d,\n"
                   "Origem: %s,\n"
                   "Destino: %s,\n"
                   "Cidade Origem: %s,\n"
                   "Cidade Destino: %s,\n"
                   "Data: %s,\n"
                   "Hora Partida: %s,\n"
                   "Hora Chegada: %s,\n"
                   "Valor: %.2f\n\n",
                   passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
                   passagens[i].Cidadeorg, passagens[i].Cidadedest,
                   passagens[i].Data,
                   passagens[i].Hpartida,
                   passagens[i].Hchegada,
                   passagens[i].Valor);
            encontrou = 1; //Variável recebe o valor como 1
        }
    } if (!encontrou){ //Se a varíavel continuar sendo 0 a passagem não foi encontrada
        printf("Nenhuma passagem encontrada com Código de Origem %s.\n", codigoOrigem);
    }
}

/*======================================================*
| Função 2 (Pesquisa de Passagem por Código de Destino) |
*======================================================*/
void pesquisarPassagemPorCodigoDestino(struct Passagens *passagens, int quantidadePassagens, const char *codigoDestino) {
    printf("Passagens com Código de Destino %s:\n", codigoDestino);

    int encontrou = 0;

    for (int i = 0; i < quantidadePassagens; i++) {
        if (strcmp(passagens[i].Destino, codigoDestino) == 0) {
            printf("ID: %d,\n"
                   "Origem: %s,\n"
                   "Destino: %s,\n"
                   "Cidade Origem: %s,\n"
                   "Cidade Destino: %s,\n"
                   "Data: %s,\n"
                   "Hora Partida: %s,\n"
                   "Hora Chegada: %s,\n"
                   "Valor: %.2f\n\n",
                   passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
                   passagens[i].Cidadeorg, passagens[i].Cidadedest,
                   passagens[i].Data,
                   passagens[i].Hpartida,
                   passagens[i].Hchegada,
                   passagens[i].Valor);
            encontrou = 1;
        }
    } if (!encontrou) {
        printf("Nenhuma passagem encontrada com Código de Origem %s.\n", codigoDestino);
    }
}

/*=====================================================*
| Função 2 (Pesquisa de Passagem por Cidade de Origem) |
*=====================================================*/
void pesquisarPassagemPorCidadeOrigem(struct Passagens *passagens, int quantidadePassagens, const char *cidadeOrigem) {
    printf("Passagens com Cidade de Origem %s:\n", cidadeOrigem);

    int encontrou = 0;

    for (int i = 0; i < quantidadePassagens; i++) {
        if (strcmp(passagens[i].Cidadeorg, cidadeOrigem) == 0) {
            printf("ID: %d,\n"
                   "Origem: %s,\n"
                   "Destino: %s,\n"
                   "Cidade Origem: %s,\n"
                   "Cidade Destino: %s,\n"
                   "Data: %s,\n"
                   "Hora Partida: %s,\n"
                   "Hora Chegada: %s,\n"
                   "Valor: %.2f\n\n",
                   passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
                   passagens[i].Cidadeorg, passagens[i].Cidadedest,
                   passagens[i].Data,
                   passagens[i].Hpartida,
                   passagens[i].Hchegada,
                   passagens[i].Valor);
            encontrou = 1;
        }
    } if (!encontrou) {
        printf("Nenhuma passagem encontrada com Código de Origem %s.\n", cidadeOrigem);
    }
}

/*======================================================*
| Função 2 (Pesquisa de Passagem por Cidade de Destino) |
*======================================================*/
void pesquisarPassagemPorCidadeDestino(struct Passagens *passagens, int quantidadePassagens, const char *cidadeDestino) {
    printf("Passagens com Cidade de Destino %s:\n", cidadeDestino);

    int encontrou = 0;

    for (int i = 0; i < quantidadePassagens; i++) {
        if (strcmp(passagens[i].Cidadedest, cidadeDestino) == 0) {
            printf("ID: %d,\n"
                   "Origem: %s,\n"
                   "Destino: %s,\n"
                   "Cidade Origem: %s,\n"
                   "Cidade Destino: %s,\n"
                   "Data: %s,\n"
                   "Hora Partida: %s,\n"
                   "Hora Chegada: %s,\n"
                   "Valor: %.2f\n\n",
                   passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
                   passagens[i].Cidadeorg, passagens[i].Cidadedest,
                   passagens[i].Data,
                   passagens[i].Hpartida,
                   passagens[i].Hchegada,
                   passagens[i].Valor);
            encontrou = 1;
        }
    } if (!encontrou) {
        printf("Nenhuma passagem encontrada com Código de Origem %s.\n", cidadeDestino);
    }
}

/*=================================================================================*
| Função 2 (Pesquisa de Passagem com Base na Opção do Menu Escolhida Pelo Usuário) |
*=================================================================================*/
void pesquisarPassagemPorOpcao(struct Passagens *passagens, int quantidadePassagens, int opcao) {
    int idPesquisa;
    char codigoPesquisa[4];
    char cidadePesquisa[50];

    //Switch Case com base no parâmetro da variável(opcao) digitada no int main, em que cada opção do switch chama uma função diferente
    switch (opcao) {
        case 1:
            // Pesquisar por ID
            printf("Digite o ID da passagem a ser pesquisada: ");
            scanf("%d", &idPesquisa);
            pesquisarPassagem(passagens, quantidadePassagens, idPesquisa);
            break;

        case 2:
            // Pesquisar por Código de Origem
            printf("Digite o Código de Origem a ser pesquisado: ");
            scanf("%3s", codigoPesquisa);
            pesquisarPassagemPorCodigoOrigem(passagens, quantidadePassagens, codigoPesquisa);
            break;

        case 3:
            // Pesquisar por Código de Destino
            printf("Digite o Código de Destino a ser pesquisado: ");
            scanf("%3s", codigoPesquisa);
            pesquisarPassagemPorCodigoDestino(passagens, quantidadePassagens, codigoPesquisa);
            break;

        case 4:
            // Pesquisar por Cidade de Origem
            printf("Digite a Cidade de Origem a ser pesquisada: ");
            scanf("%s", cidadePesquisa);
            pesquisarPassagemPorCidadeOrigem(passagens, quantidadePassagens, cidadePesquisa);
            break;

        case 5:
            // Pesquisar por Cidade de Destino
            printf("Digite a Cidade de Destino a ser pesquisada: ");
            scanf("%s", cidadePesquisa);
            pesquisarPassagemPorCidadeDestino(passagens, quantidadePassagens, cidadePesquisa);
            break;

        default:
            printf("Opção de pesquisa inválida.\n");
            break;
    }
}

//-------------------------------**-------------------------------//
/*=====================================================*
|           Função 3 (Cadastro de Passagens)           |
*=====================================================*/
void cadastro(struct Passagens *passagens, int *quantidadePassagens, int *ultimoID) {
    if (*quantidadePassagens >= 100){ //Limita a quantidade de passagens cadastradas até 100
        printf("Limite de passagens atingido.\n");
        return;
    }

    struct Passagens viagem; //Cria uma variável "viagem" do tipo struct Passagens, para armazenar dados de uma nova passagem

    // Incrementa o último ID antes de atribuir ao ID da nova passagem
    (*ultimoID)++;
    viagem.ID = *ultimoID;

    //Entrada de dados
    printf("Digite o Código do aeroporto origem: ");
    scanf("%3s", viagem.Origem);
    limparBuffer();

    printf("Digite o Código do aeroporto destino: ");
    scanf("%3s", viagem.Destino);
    limparBuffer();

    printf("Digite a Cidade de origem: ");
    scanf("%[^\n]", viagem.Cidadeorg);
    limparBuffer();

    printf("Digite a Cidade destino: ");
    scanf("%[^\n]", viagem.Cidadedest);
    limparBuffer();

    // Restrição para a data, o loop irá repetir até a data ser válida, ou seja, ter digitado dd/mm/yyyy
    do {
        printf("Digite a Data (dd//mm/yyyy): ");
        scanf("%s", viagem.Data);
        limparBuffer();

        // Verifica se a data é válida
        if (!verificarData(viagem.Data)){ //Quando a data for inserida, a função irá verificar e se retornar falso, a data não é válida
            printf("Data inválida. Digite novamente.\n");
        }
    } while (!verificarData(viagem.Data)); //O loop continua enquanto retornar falso

    // Restrição para a hora de partida
    do {
        printf("Digite a Hora de partida (hora:minuto): ");
        scanf("%s", viagem.Hpartida);
        limparBuffer();

        // Verifica se a hora de partida é válida
        if (!verificarHora(viagem.Hpartida)){ //Segue a lógica da data
            printf("Hora de partida inválida. Digite novamente.\n");
        }
    } while (!verificarHora(viagem.Hpartida));

    // Restrição para a hora de chegada
    do {
        printf("Digite a Hora de chegada (hora:minuto): ");
        scanf("%s", viagem.Hchegada);
        limparBuffer();

        // Verifica se a hora de chegada é válida
        if (!verificarHora(viagem.Hchegada)){ //Segue a lógica da data
            printf("Hora de chegada inválida. Digite novamente.\n");
        }
    } while (!verificarHora(viagem.Hchegada));

    printf("Digite o Valor da passagem: ");
    scanf("%f", &viagem.Valor);
    limparBuffer();

    // Adiciona a nova passagem ao array
    passagens[*quantidadePassagens] = viagem;

    // Incrementa a quantidade de passagens cadastradas
    (*quantidadePassagens)++;
}

//-------------------------------**-------------------------------//
/*=====================================================*
|       Função Para Verificar se Data é Válida         |
*=====================================================*/
int verificarData(const char *data) {
    int dia, mes, ano;
    //Verifica se a leitura da data está certa
    //Uso do "sscanf" para converter string em 3 interios
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3){ // !=3 verifica se a quantidade de interios lidas será igual 3, se não retornará 0
        return 0; //Retorna 0 se não estiver certa
    }
    // Verifica limites para dia, mes e ano
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0){
        return 0; //Se os valores estiverem errados retorna 0
    }

    return 1; //Retorna 1 se a data for válida
}

//-------------------------------**-------------------------------//
/*=====================================================*
|       Função Para Verificar se a Hora é Válida       |
*=====================================================*/
int verificarHora(const char *hora) {
    int hh, mm;
    if (sscanf(hora, "%d:%d", &hh, &mm) != 2) {
        return 0;
    }

    // Verifica limites para horas e minutos
    if (hh < 0 || hh > 23 || mm < 0 || mm > 59) {
        return 0;
    }

    return 1;
}

//-------------------------------**-------------------------------//
/*=====================================================*
|      Função 4 (Editar Passagens já Existentes)       |
*=====================================================*/
void editarPassagem(struct Passagens *passagens, int quantidadePassagens) {
    int idEdicao;
    printf("Digite o ID da passagem a ser editada: ");
    scanf("%d", &idEdicao);

    // Encontrar a passagem a ser editada
    int indiceEdicao = -1;
    for (int i = 0; i < quantidadePassagens; i++){ //Loop para varrer todas as passagens e verificar se o ID no índice i é igual ao ID fornecido
        if (passagens[i].ID == idEdicao){
            indiceEdicao = i; //A variável "indiceEdicao irá receber o valor de i caso encontrar o ID
            break; //Se "indiceEdicao" permanecer -1
        }
    }

    if (indiceEdicao == -1) {
        printf("Passagem com ID %d não encontrada.\n", idEdicao);
        return;
    }

    // Solicitar as informações atualizadas ao usuário
    printf("Digite o Código do Aeroporto origem: ");
    scanf("%3s", passagens[indiceEdicao].Origem);
    limparBuffer();

    printf("Digite o Código do Aeroporto destino: ");
    scanf("%3s", passagens[indiceEdicao].Destino);
    limparBuffer();

    printf("Digite a Cidade de origem: ");
      scanf("%[^\n]", passagens[indiceEdicao].Cidadeorg);
      limparBuffer();

      printf("Digite a Cidade destino: ");
      scanf("%[^\n]", passagens[indiceEdicao].Cidadedest);
      limparBuffer();

      printf("Digite a Data (dia mês ano): ");
      scanf("%s", &passagens[indiceEdicao].Data);
     limparBuffer();

      printf("Digite a Hora de partida (hora minuto): ");
      scanf("%s", &passagens[indiceEdicao].Hpartida);
     limparBuffer();

      printf("Digite a Hora de chegada (hora minuto): ");
      scanf("%s", &passagens[indiceEdicao].Hchegada);
     limparBuffer();

      printf("Digite o Valor da passagem: ");
      scanf("%f", &passagens[indiceEdicao].Valor);
     limparBuffer();

    // Mensagem indicando que a edição foi concluída
    printf("Passagem com ID %d editada com sucesso.\n", idEdicao);
}


//-------------------------------**-------------------------------//
/*=====================================================*
|      Função 5 (Excluir Passagens do Arquivo)         |
*=====================================================*/
void excluirPassagem(struct Passagens *passagens, int *quantidadePassagens) {
    int idExclusao;
    printf("Digite o ID da passagem a ser excluída: ");
    scanf("%d", &idExclusao);

    // Encontrar a passagem a ser excluída
    int indiceExclusao = -1;
    for (int i = 0; i < *quantidadePassagens; i++){ //Loop para buscar a passagem a ser excluida
        if (passagens[i].ID == idExclusao){
            indiceExclusao = i;
            break;
        }
    }

    if (indiceExclusao == -1) {
        printf("Passagem com ID %d não encontrada.\n", idExclusao);
        return;
    }

    // Remover a passagem do array
    for (int i = indiceExclusao; i < *quantidadePassagens - 1; i++) {
        //Loop para mover as todas as passagens que estão após as passagem escolhida para trás, removendo ela do array
        passagens[i] = passagens[i + 1];
    }

    // Decrementar a quantidade de passagens
    (*quantidadePassagens)--;

    // Mensagem indicando que a exclusão foi concluída
    printf("Passagem com ID %d excluída com sucesso.\n", idExclusao);
}


//-------------------------------**-------------------------------//
/*================================================================*
|  Função Para Salvar a Quantidade de Passagens(primeira linha),  |
|  o Ultimo ID(segunda linha) e as Novas Passagens(Prox linhas)   |
*================================================================*/
void salvarPassagens(struct Passagens *passagens, int quantidadePassagens, int ultimoID) {
    FILE *arquivo;

    arquivo = fopen("passagens.txt", "w"); // Abre o arquivo para escrita (modo "w" - write, ou seja, escrita)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreve a quantidade de passagens cadastradas e o último ID
    fprintf(arquivo, "%d\n%d\n", quantidadePassagens, ultimoID);

    // Escreve os dados de cada passagem no arquivo
    for (int i = 0; i < quantidadePassagens; i++) {
        fprintf(arquivo, "%d;%s;%s;%s;%s;%s;%s;%s;%.2f\n",
                passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
                passagens[i].Cidadeorg, passagens[i].Cidadedest,
                passagens[i].Data,
                passagens[i].Hpartida,
                passagens[i].Hchegada,
                passagens[i].Valor);
    }

    fclose(arquivo); // Fecha o arquivo após a escrita
}


//-------------------------------**-------------------------------//
/*================================================================*
|  Função Para Carregar as Informações das Passagens no Arquivo   |
*================================================================*/
void carregarPassagens(struct Passagens *passagens, int *quantidadePassagens, int *ultimoID) {
    FILE *arquivo;

    arquivo = fopen("passagens.txt", "r"); // Abre o arquivo para leitura (modo "r" - read, ou seja, leitura)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Lê a quantidade de passagens cadastradas e o último ID
    fscanf(arquivo, "%d\n%d\n", quantidadePassagens, ultimoID);

    // Lê os dados de cada passagem do arquivo
    for (int i = 0; i < *quantidadePassagens; i++) {
       fscanf(arquivo, "%d;%3s;%3s;%49[^;];%49[^;];%10[^;];%5[^;];%5[^;];%f\n",
       &passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
       passagens[i].Cidadeorg, passagens[i].Cidadedest,
       passagens[i].Data,
       passagens[i].Hpartida,
       passagens[i].Hchegada,
       &passagens[i].Valor);

    }

    fclose(arquivo); // Fecha o arquivo após a leitura
}


//-------------------------------**-------------------------------//
/*================================================================*
|  Função MAIN, que chama todas as outras funções acima por meio  |
|           do uso do (do, while) e do (switch case)              |
*================================================================*/
int main(void) {
    int opcao;
    int quantidadePassagens = 0;
    int ultimoID = 0;
    struct Passagens passagens[100]; // Ajuste o tamanho do array conforme necessário

    carregarPassagens(passagens, &quantidadePassagens, &ultimoID);

    do {
        exibirMenu(); // Chama a função para exibir o menu

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarPassagens(passagens, quantidadePassagens);
                break;

            case 2:
            printf("2) Pesquisar uma passagem\n");
            menuPesquisa(); // Chama a função de Menu para pesquisa
            scanf("%d", &opcao);
            pesquisarPassagemPorOpcao(passagens, quantidadePassagens, opcao);
            break;


            case 3:
                printf("3) Cadastrar uma passagem\n");
                cadastro(passagens, &quantidadePassagens, &ultimoID);
                salvarPassagens(passagens, quantidadePassagens, ultimoID);
                break;

            case 4:
              printf("4) Editar uma passagem\n");
              editarPassagem(passagens, quantidadePassagens);
              salvarPassagens(passagens, quantidadePassagens, ultimoID);
              break;

            case 5:
              printf("5) Excluir uma passagem\n");
              excluirPassagem(passagens, &quantidadePassagens);
              salvarPassagens(passagens, quantidadePassagens, ultimoID);
              break;

            case 6:
                printf("6) Sair do programa\n");
                break;

            default:
                printf("Opcao invalida. Digite um numero de 1 a 6.\n");
        }
    } while (opcao != 6);

    return 0;
}
