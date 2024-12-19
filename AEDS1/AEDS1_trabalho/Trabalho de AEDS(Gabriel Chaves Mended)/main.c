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
|       Fun��o para remover caracteres extras       |
*==================================================*/
void limparBuffer(){
  char c;
  while((c = getchar()) != '\n' && c != EOF); //c recebe um caracter e verifica se n�o � um \n ou � o final do arquivo (EOF)
}

//-------------------------------**-------------------------------//
/*==================================================*
|       Fun��o para Menu de Escolhas                |
*==================================================*/
void exibirMenu() {
    //Esta fun��o � o menu principal do arquivo, puxado no MAIN
    printf("Menu:\n"
           "1) Listar todas as passagens\n"
           "2) Pesquisar uma passagem\n"
           "3) Cadastrar uma passagem\n"
           "4) Editar uma passagem\n"
           "5) Excluir uma passagem\n"
           "6) Sair do programa\n"
           "Digite de 1 a 6 qual fun��o do Menu ser� executada: ");
}

//-------------------------------**-------------------------------//
/*==================================================*
|     Fun��o1 (Listagem de Todas as Passagens)      |
*==================================================*/
void listarPassagens(struct Passagens *passagens, int quantidadePassagens) {
    printf("Listagem de Passagens:\n");

    //O loop ir� continuar at� o total de passagens, valor atribuido em "quantidadePassagens" e printar todas as informa��es
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
|    Fun��o2 (Menu para Pesquisa de uma Passagem)   |
*==================================================*/
void menuPesquisa(){
  //Fun��o para criar um menu, que servir� para propor ao usu�rio escolhas de como Pesquisar uma Passsagem
  //Esta fun��o � chamada no Main
  printf("Menu de Pesquisas:\n"
         "1) Pesquisar por ID\n"
         "2) Pesquisar por C�digo de Origem\n"
         "3) Pesquisar por C�digo de Destino\n"
         "4) Pesquisar por Cidade de Origem\n"
         "5) Pesquisar por Cidade de Destino\n"
         "Escolha uma op��o de 1 a 5 para pesquisar a passagem: ");
}

/*==================================================*
|      Fun��o 2 (Pesquisa de Passagem por ID)       |
*==================================================*/
void pesquisarPassagem(struct Passagens *passagens, int quantidadePassagens, int idPesquisa) {
    for (int i = 0; i < quantidadePassagens; i++) {
        if (passagens[i].ID == idPesquisa) { //Verifica se o ID no �dice i � igual ao ID fornecido pelo usu�rio
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

    printf("Passagem com ID %d n�o encontrada.\n", idPesquisa);
}

/*=====================================================*
| Fun��o 2 (Pesquisa de Passagem por C�digo de Origem) |
*=====================================================*/
void pesquisarPassagemPorCodigoOrigem(struct Passagens *passagens, int quantidadePassagens, const char *codigoOrigem) {
    printf("Passagens com C�digo de Origem %s:\n", codigoOrigem);

    int encontrou = 0; //Vari�vel de par�metro que verifica se a passagem foi encontrada ou n�o

    for (int i = 0; i < quantidadePassagens; i++) {
        if (strcmp(passagens[i].Origem, codigoOrigem) == 0){ //Verifica se o c�digo no par�metro i � igual ao fornecido e com o uso do strcmp compara se as strings s�o iguai e retorna 0 se for
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
            encontrou = 1; //Vari�vel recebe o valor como 1
        }
    } if (!encontrou){ //Se a var�avel continuar sendo 0 a passagem n�o foi encontrada
        printf("Nenhuma passagem encontrada com C�digo de Origem %s.\n", codigoOrigem);
    }
}

/*======================================================*
| Fun��o 2 (Pesquisa de Passagem por C�digo de Destino) |
*======================================================*/
void pesquisarPassagemPorCodigoDestino(struct Passagens *passagens, int quantidadePassagens, const char *codigoDestino) {
    printf("Passagens com C�digo de Destino %s:\n", codigoDestino);

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
        printf("Nenhuma passagem encontrada com C�digo de Origem %s.\n", codigoDestino);
    }
}

/*=====================================================*
| Fun��o 2 (Pesquisa de Passagem por Cidade de Origem) |
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
        printf("Nenhuma passagem encontrada com C�digo de Origem %s.\n", cidadeOrigem);
    }
}

/*======================================================*
| Fun��o 2 (Pesquisa de Passagem por Cidade de Destino) |
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
        printf("Nenhuma passagem encontrada com C�digo de Origem %s.\n", cidadeDestino);
    }
}

/*=================================================================================*
| Fun��o 2 (Pesquisa de Passagem com Base na Op��o do Menu Escolhida Pelo Usu�rio) |
*=================================================================================*/
void pesquisarPassagemPorOpcao(struct Passagens *passagens, int quantidadePassagens, int opcao) {
    int idPesquisa;
    char codigoPesquisa[4];
    char cidadePesquisa[50];

    //Switch Case com base no par�metro da vari�vel(opcao) digitada no int main, em que cada op��o do switch chama uma fun��o diferente
    switch (opcao) {
        case 1:
            // Pesquisar por ID
            printf("Digite o ID da passagem a ser pesquisada: ");
            scanf("%d", &idPesquisa);
            pesquisarPassagem(passagens, quantidadePassagens, idPesquisa);
            break;

        case 2:
            // Pesquisar por C�digo de Origem
            printf("Digite o C�digo de Origem a ser pesquisado: ");
            scanf("%3s", codigoPesquisa);
            pesquisarPassagemPorCodigoOrigem(passagens, quantidadePassagens, codigoPesquisa);
            break;

        case 3:
            // Pesquisar por C�digo de Destino
            printf("Digite o C�digo de Destino a ser pesquisado: ");
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
            printf("Op��o de pesquisa inv�lida.\n");
            break;
    }
}

//-------------------------------**-------------------------------//
/*=====================================================*
|           Fun��o 3 (Cadastro de Passagens)           |
*=====================================================*/
void cadastro(struct Passagens *passagens, int *quantidadePassagens, int *ultimoID) {
    if (*quantidadePassagens >= 100){ //Limita a quantidade de passagens cadastradas at� 100
        printf("Limite de passagens atingido.\n");
        return;
    }

    struct Passagens viagem; //Cria uma vari�vel "viagem" do tipo struct Passagens, para armazenar dados de uma nova passagem

    // Incrementa o �ltimo ID antes de atribuir ao ID da nova passagem
    (*ultimoID)++;
    viagem.ID = *ultimoID;

    //Entrada de dados
    printf("Digite o C�digo do aeroporto origem: ");
    scanf("%3s", viagem.Origem);
    limparBuffer();

    printf("Digite o C�digo do aeroporto destino: ");
    scanf("%3s", viagem.Destino);
    limparBuffer();

    printf("Digite a Cidade de origem: ");
    scanf("%[^\n]", viagem.Cidadeorg);
    limparBuffer();

    printf("Digite a Cidade destino: ");
    scanf("%[^\n]", viagem.Cidadedest);
    limparBuffer();

    // Restri��o para a data, o loop ir� repetir at� a data ser v�lida, ou seja, ter digitado dd/mm/yyyy
    do {
        printf("Digite a Data (dd//mm/yyyy): ");
        scanf("%s", viagem.Data);
        limparBuffer();

        // Verifica se a data � v�lida
        if (!verificarData(viagem.Data)){ //Quando a data for inserida, a fun��o ir� verificar e se retornar falso, a data n�o � v�lida
            printf("Data inv�lida. Digite novamente.\n");
        }
    } while (!verificarData(viagem.Data)); //O loop continua enquanto retornar falso

    // Restri��o para a hora de partida
    do {
        printf("Digite a Hora de partida (hora:minuto): ");
        scanf("%s", viagem.Hpartida);
        limparBuffer();

        // Verifica se a hora de partida � v�lida
        if (!verificarHora(viagem.Hpartida)){ //Segue a l�gica da data
            printf("Hora de partida inv�lida. Digite novamente.\n");
        }
    } while (!verificarHora(viagem.Hpartida));

    // Restri��o para a hora de chegada
    do {
        printf("Digite a Hora de chegada (hora:minuto): ");
        scanf("%s", viagem.Hchegada);
        limparBuffer();

        // Verifica se a hora de chegada � v�lida
        if (!verificarHora(viagem.Hchegada)){ //Segue a l�gica da data
            printf("Hora de chegada inv�lida. Digite novamente.\n");
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
|       Fun��o Para Verificar se Data � V�lida         |
*=====================================================*/
int verificarData(const char *data) {
    int dia, mes, ano;
    //Verifica se a leitura da data est� certa
    //Uso do "sscanf" para converter string em 3 interios
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3){ // !=3 verifica se a quantidade de interios lidas ser� igual 3, se n�o retornar� 0
        return 0; //Retorna 0 se n�o estiver certa
    }
    // Verifica limites para dia, mes e ano
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 0){
        return 0; //Se os valores estiverem errados retorna 0
    }

    return 1; //Retorna 1 se a data for v�lida
}

//-------------------------------**-------------------------------//
/*=====================================================*
|       Fun��o Para Verificar se a Hora � V�lida       |
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
|      Fun��o 4 (Editar Passagens j� Existentes)       |
*=====================================================*/
void editarPassagem(struct Passagens *passagens, int quantidadePassagens) {
    int idEdicao;
    printf("Digite o ID da passagem a ser editada: ");
    scanf("%d", &idEdicao);

    // Encontrar a passagem a ser editada
    int indiceEdicao = -1;
    for (int i = 0; i < quantidadePassagens; i++){ //Loop para varrer todas as passagens e verificar se o ID no �ndice i � igual ao ID fornecido
        if (passagens[i].ID == idEdicao){
            indiceEdicao = i; //A vari�vel "indiceEdicao ir� receber o valor de i caso encontrar o ID
            break; //Se "indiceEdicao" permanecer -1
        }
    }

    if (indiceEdicao == -1) {
        printf("Passagem com ID %d n�o encontrada.\n", idEdicao);
        return;
    }

    // Solicitar as informa��es atualizadas ao usu�rio
    printf("Digite o C�digo do Aeroporto origem: ");
    scanf("%3s", passagens[indiceEdicao].Origem);
    limparBuffer();

    printf("Digite o C�digo do Aeroporto destino: ");
    scanf("%3s", passagens[indiceEdicao].Destino);
    limparBuffer();

    printf("Digite a Cidade de origem: ");
      scanf("%[^\n]", passagens[indiceEdicao].Cidadeorg);
      limparBuffer();

      printf("Digite a Cidade destino: ");
      scanf("%[^\n]", passagens[indiceEdicao].Cidadedest);
      limparBuffer();

      printf("Digite a Data (dia m�s ano): ");
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

    // Mensagem indicando que a edi��o foi conclu�da
    printf("Passagem com ID %d editada com sucesso.\n", idEdicao);
}


//-------------------------------**-------------------------------//
/*=====================================================*
|      Fun��o 5 (Excluir Passagens do Arquivo)         |
*=====================================================*/
void excluirPassagem(struct Passagens *passagens, int *quantidadePassagens) {
    int idExclusao;
    printf("Digite o ID da passagem a ser exclu�da: ");
    scanf("%d", &idExclusao);

    // Encontrar a passagem a ser exclu�da
    int indiceExclusao = -1;
    for (int i = 0; i < *quantidadePassagens; i++){ //Loop para buscar a passagem a ser excluida
        if (passagens[i].ID == idExclusao){
            indiceExclusao = i;
            break;
        }
    }

    if (indiceExclusao == -1) {
        printf("Passagem com ID %d n�o encontrada.\n", idExclusao);
        return;
    }

    // Remover a passagem do array
    for (int i = indiceExclusao; i < *quantidadePassagens - 1; i++) {
        //Loop para mover as todas as passagens que est�o ap�s as passagem escolhida para tr�s, removendo ela do array
        passagens[i] = passagens[i + 1];
    }

    // Decrementar a quantidade de passagens
    (*quantidadePassagens)--;

    // Mensagem indicando que a exclus�o foi conclu�da
    printf("Passagem com ID %d exclu�da com sucesso.\n", idExclusao);
}


//-------------------------------**-------------------------------//
/*================================================================*
|  Fun��o Para Salvar a Quantidade de Passagens(primeira linha),  |
|  o Ultimo ID(segunda linha) e as Novas Passagens(Prox linhas)   |
*================================================================*/
void salvarPassagens(struct Passagens *passagens, int quantidadePassagens, int ultimoID) {
    FILE *arquivo;

    arquivo = fopen("passagens.txt", "w"); // Abre o arquivo para escrita (modo "w" - write, ou seja, escrita)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // Escreve a quantidade de passagens cadastradas e o �ltimo ID
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

    fclose(arquivo); // Fecha o arquivo ap�s a escrita
}


//-------------------------------**-------------------------------//
/*================================================================*
|  Fun��o Para Carregar as Informa��es das Passagens no Arquivo   |
*================================================================*/
void carregarPassagens(struct Passagens *passagens, int *quantidadePassagens, int *ultimoID) {
    FILE *arquivo;

    arquivo = fopen("passagens.txt", "r"); // Abre o arquivo para leitura (modo "r" - read, ou seja, leitura)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    // L� a quantidade de passagens cadastradas e o �ltimo ID
    fscanf(arquivo, "%d\n%d\n", quantidadePassagens, ultimoID);

    // L� os dados de cada passagem do arquivo
    for (int i = 0; i < *quantidadePassagens; i++) {
       fscanf(arquivo, "%d;%3s;%3s;%49[^;];%49[^;];%10[^;];%5[^;];%5[^;];%f\n",
       &passagens[i].ID, passagens[i].Origem, passagens[i].Destino,
       passagens[i].Cidadeorg, passagens[i].Cidadedest,
       passagens[i].Data,
       passagens[i].Hpartida,
       passagens[i].Hchegada,
       &passagens[i].Valor);

    }

    fclose(arquivo); // Fecha o arquivo ap�s a leitura
}


//-------------------------------**-------------------------------//
/*================================================================*
|  Fun��o MAIN, que chama todas as outras fun��es acima por meio  |
|           do uso do (do, while) e do (switch case)              |
*================================================================*/
int main(void) {
    int opcao;
    int quantidadePassagens = 0;
    int ultimoID = 0;
    struct Passagens passagens[100]; // Ajuste o tamanho do array conforme necess�rio

    carregarPassagens(passagens, &quantidadePassagens, &ultimoID);

    do {
        exibirMenu(); // Chama a fun��o para exibir o menu

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarPassagens(passagens, quantidadePassagens);
                break;

            case 2:
            printf("2) Pesquisar uma passagem\n");
            menuPesquisa(); // Chama a fun��o de Menu para pesquisa
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
