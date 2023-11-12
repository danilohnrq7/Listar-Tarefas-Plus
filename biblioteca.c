#include "biblioteca.h"
#include <stdio.h>
#include "string.h"

int altera_categoria(int* verifica, ListaDeTarefas* lt, int indice) {
    //switch case para preenceher a categoria na struct de acordo com a entrada do usuario
    switch (*verifica) {
        case 1:
            strcpy(lt->tarefas[indice].categoria, "Pessoal");
            break;
        case 2:
            strcpy(lt->tarefas[indice].categoria, "Casa");
            break;
        case 3:
            strcpy(lt->tarefas[indice].categoria, "Pets");
            break;
        case 4:
            strcpy(lt->tarefas[indice].categoria, "Faculdade/Escola");
            break;
        case 5:
            strcpy(lt->tarefas[indice].categoria, "Trabalho");
            break;
        case 6:
            strcpy(lt->tarefas[indice].categoria, "Financeira");
            break;
        case 7:
            strcpy(lt->tarefas[indice].categoria, "Alimentacao");
            break;
        case 8:
            strcpy(lt->tarefas[indice].categoria, "Intelectual/Espiritual");
            break;
        case 9:
            strcpy(lt->tarefas[indice].categoria, "Saude/Exercicio");
            break;
        case 10:
            strcpy(lt->tarefas[indice].categoria, "Outros");
            break;
    };
}

int altera_andamento(int* verifica, ListaDeTarefas* lt, int indice) {
    //switch case para preenceher a categoria na struct de acordo com a entrada do usuario
    switch (*verifica) {
        case 1:
            strcpy(lt->tarefas[indice].categoria, "Pessoal");
            break;
        case 2:
            strcpy(lt->tarefas[indice].categoria, "Casa");
            break;
        case 3:
            strcpy(lt->tarefas[indice].categoria, "Pets");
            break;
    };
}

//Função de cadastro
int cadastrarTarefa(ListaDeTarefas *lt){
    //Variável para o controle do retorno das funções
    int verif_categoria;

    //Lendo a prioridade da tarefa
    printf("Digite a prioridade da tarefa: (digite um valor de 0 a 10)\n");
    scanf("%d",&lt->tarefas[lt->qtd].prioridade);
    getchar();

    //Lendo a descrição da tarefa
    printf("Digite a descricao da tarefa: ");
    scanf(" %[^\n]",lt->tarefas[lt->qtd].descricao);
    getchar();

    //Lendo a categoria da tarefa
    printf("Selecione a categoria da tarefa, Digite um dos numeros:\n1-Pessoal  |  2-Casa  |  3-Pets  |  4-Faculdade/Escola  |  5-Trabalho  |  6-Financeira  |\n7-Alimentacao |  8-Intelectual/Espiritual  |  9-Saude/Exercicio  |  10-Outros  |\n");
    scanf("%d", &verif_categoria);
    altera_categoria(&verif_categoria, lt, lt->qtd);


    //Lendo o status da tarefa
    printf("Essa tarefa está completa?  Digite:\n'1' se estiver completa\n'2' se estiver em andamento\n'3' se ainda não tiver iniciado ainda\n'" );
    scanf(" %[^\n]",lt->tarefas[lt->qtd].estado);
    getchar();

    //Aumentando a variável do número de structs
    lt->qtd ++;

    //Guardando a nova struct em um arquivo binário e verificando retorno da função
    int controle = salvarTarefas(lt);
    if (controle != 0){
        printf("\nErro ao tentar executar a funcao :(\n");
    }

    return 0;
};

    //scanf(" %[^\n]", lt->tarefas[lt->qtd].categoria);




//
int alterarTarefa(ListaDeTarefas *lt){
    //Variáveis para: o controle do retorno da função - verificar se a tarefa foi encontrada - ler o número da tarefa a ser deletada
    int controle, verifica = 1, num_tarefa, escolha;

    //Verificando se existe alguma tarefa cadastrada
    if (lt->qtd == 0){
        printf("\nNao existem tarefas cadastradas.\n");
    }
    else {
        //Listando as tarefas e verificando o retorno da função
        controle = listarTarefas(*lt);
        if (controle != 0){
            printf("\nErro ao tentar executar a funcao :(\n");
        }

        //Opção 0 para cancelar o delete
        printf("\n0 - Cancelar.\n");

        //Lendo o número da tarefa ou o 0
        printf("\nDigite o numero da tarefa que deseja alterar ou 0 para cancelar: ");
        scanf("%d",&num_tarefa);

        //Cancelando o delete
        if (num_tarefa == 0){
            verifica = 0;
            printf("\n\nCancelado!\n");
        }

            //aletarando a tarefa
        else {

            //Percorrendo a ListaDeTarefas e comparando o número digitado com o número da tarefa
            for (int i = 0; i < lt->qtd; i++){ //Laço 1
                if (i+1 == num_tarefa){

                    //Atualizando o resto da ListaDeTarefas pelo índice.
                    //Adicionando o conteúdo da próxima struct Tarefa (próximo índice da struct ListaDeTarefas) à atual struct Tarefa
                    for (int j = i; j < lt->qtd - 1; j++){ //Laço 2
                        lt->tarefas[j] = lt->tarefas[j+1];
                    }
                    printf("Qual campo da tarefa deseja alterar? :\n1-Prioridade  |  2-Descrição  |  3-Categoria  |  4-Andamento");
                    scanf("%d",&escolha);

                    if(escolha == 1){
                        printf("Digite a prioridade da tarefa: (digite um valor de 0 a 10)\n");
                        scanf("%d",&lt->tarefas[i].prioridade);
                        getchar();
                        verifica = 0;
                    }
                    else if(escolha == 2){
                        printf("Digite a descricao da tarefa: ");
                        scanf(" %[^\n]",lt->tarefas[i].descricao);
                        getchar();
                        verifica = 0;
                    }
                    else if(escolha == 3){
                        int verif_categoria;
                        printf("Selecione a categoria da tarefa, Digite um dos numeros:\n1-Pessoal  |  2-Casa  |  3-Pets  |  4-Faculdade/Escola  |  5-Trabalho  |  6-Financeira  |\n7-Alimentacao |  8-Intelectual/Espiritual  |  9-Saude/Exercicio  |  10-Outros  |\n");
                        scanf("%d", &verif_categoria);
                        getchar();
                        altera_categoria(&verif_categoria, lt, i);
                        verifica = 0;
                    }
                    else if (escolha == 4) {
                        printf("Selecione o estado atual da tarefa. Digite:\n'1' se estiver completa\n'2' se estiver em andamento\n'3' se ainda não tiver iniciado ainda\n");
                        scanf(" %[^\n]", lt->tarefas[i].estado);
                        verifica = 0;
                    }
                    else{
                        printf("ERRO AO TENTAR ALTERAR A TAREFA, TENTE NOVAMENTE");
                        break;
                    }

                    //Reduzindo o número de tarefas
                    /*lt->qtd -= 1;
                    printf("\n\nTarefa Apagada!\n");
                    //Atualizando a variável que verifica se a tarefa foi encontrada
                    verifica = 0;
                    //Saindo do laço 1
                    break;*/
                }

            }
        }
        //Caso a tarefa não seja encontrada
        if (verifica == 1){
            printf("\n\nTarefa não encontrada\n");
        }
    }

    //Guardando a nova struct em um arquivo binário e verificando retorno da função
    controle = salvarTarefas(lt);
    if (controle != 0){
        printf("\nErro ao tentar executar a funcao :(\n");
    }

    return 0;
};

//Função de delete
int deletarTarefa(ListaDeTarefas *lt){

    //Variáveis para: o controle do retorno da função - verificar se a tarefa foi encontrada - ler o número da tarefa a ser deletada
    int controle, verifica = 1, num_tarefa;

    //Verificando se existe alguma tarefa cadastrada
    if (lt->qtd == 0){
        printf("\nNao existem tarefas cadastradas.\n");
    }
    else {
        //Listando as tarefas e verificando o retorno da função
        controle = listarTarefas(*lt);
        if (controle != 0){
            printf("\nErro ao tentar executar a funcao :(\n");
        }

        //Opção 0 para cancelar o delete
        printf("\n0 - Cancelar.\n");

        //Lendo o número da tarefa ou o 0
        printf("\nDigite o numero da tarefa que deseja apagarn ou 0 para cancelar: ");
        scanf("%d",&num_tarefa);

        //Cancelando o delete
        if (num_tarefa == 0){
            verifica = 0;
            printf("\n\nCancelado!\n");
        }

            //Iniciando o delete
        else {

            //Percorrendo a ListaDeTarefas e comparando o número digitado com o número da tarefa
            for (int i = 0; i < lt->qtd; i++){ //Laço 1
                if (i+1 == num_tarefa){

                    //Atualizando o resto da ListaDeTarefas pelo índice.
                    //Adicionando o conteúdo da próxima struct Tarefa (próximo índice da struct ListaDeTarefas) à atual struct Tarefa
                    for (int j = i; j < lt->qtd - 1; j++){ //Laço 2
                        lt->tarefas[j] = lt->tarefas[j+1];
                    }

                    //Reduzindo o número de tarefas
                    lt->qtd -= 1;
                    printf("\n\nTarefa Apagada!\n");
                    //Atualizando a variável que verifica se a tarefa foi encontrada
                    verifica = 0;
                    //Saindo do laço 1
                    break;
                }

            }
        }
        //Caso a tarefa não seja encontrada
        if (verifica == 1){
            printf("\n\nTarefa não encontrada\n");
        }
    }

    //Guardando a nova struct em um arquivo binário e verificando retorno da função
    controle = salvarTarefas(lt);
    if (controle != 0){
        printf("\nErro ao tentar executar a funcao :(\n");
    }

    return 0;
}

//funcao para anular qualquer conteudo que esteja inicialmente na struct lista de tarefas
void zerarListaDeTarefas(ListaDeTarefas *lt) {
    lt->qtd = 0;
    //for para iterar sobre todos os itens
    for (int i =0; i < 100; i++){
        //tornando os valores nulos
        lt->tarefas[i].prioridade = 0;
        lt->tarefas[i].descricao[0] ='\0';
        lt->tarefas[i].categoria[0] ='\0';
        lt->tarefas[i].estado[0] ='\0';
    }}

//Função de lista
int listarTarefas(ListaDeTarefas lt){

    //Verificando se existe alguma tarefa cadastrada
    if (lt.qtd == 0){
        printf("\nNao existem tarefas cadastradas.\n");
    }
        //Caso exista
    else {
        //Mostrando a quantidade de tarefas cadastradas
        printf("Quantidade de tarefas: %d\n", lt.qtd);

        //Printando todas as tarefas
        for (int i = 0; i < lt.qtd; i++){

            printf("\nTarefa %d:\n", i+1); //Número
            printf("Prioridade da tarefa: %d\n", lt.tarefas[i].prioridade); //Prioridade
            printf("Descricao da tarefa: %s\n", lt.tarefas[i].descricao); //Descrição
            printf("Categoria da tarefa: %s\n", lt.tarefas[i].categoria); //Categoria
            printf("Andamento da tarefa: %s\n", lt.tarefas[i].estado); //Andamento
        }
    }
    return 0;
}

//Função para printar o menu
void printMenu(){

    //Printando o Menu
    printf("Menu:\n");
    printf("1 - Cadastrar tarefa.\n");
    printf("2 - Deletar tarefa.\n");
    printf("3 - Listar tarefas.\n");
    printf("4 - Alterar tarefas.\n");
    printf("0 - Sair.\n\n");

}

//Função para salvar as structs em um arquivo binário
int salvarTarefas(ListaDeTarefas *lt){

    //Abrindo o arquivo binário no modo de escrita
    FILE *f = fopen("arquivo.bin", "wb");

    //Verificando se foi possível abrir e escrever o arquivo
    if (f == NULL) {
        printf("Erro ao escrever o arquivo.\n");
        //Caso não seja possível abrir ou escrever o arquivo, retorna 1 encerrando a função
        return 1;
    }

    //Escrevendo a struct no arquivo
    fwrite(lt->tarefas, sizeof(Tarefa), lt->qtd, f);
    //Fechando o arquivo
    fclose(f);


    return 0;
}

//Função para ler o arquivo binário e salvar as informações nas structs
int carregarTarefas(ListaDeTarefas *lt){
    //Abrindo o arquivo binário no modo de leitura
    FILE *f = fopen("arquivo.bin", "rb");

    //Verificando se foi possível abrir e ler o arquivo
    if (f == NULL) {
        //Caso não seja possível abrir ou ler o arquivo, retorna 1 encerrando a função
        printf("Erro ao ler o arquivo.\n");
        return 1;
    }

    //Variável para descobrir o número de tarefas presentes no arquivo
    int i = 0;

    //Armazenando todas as tarefas do arquivo em structs Tarefas dentro da struct ListaDeTarefas
    while (fread(&lt->tarefas[i], sizeof(Tarefa), 1, f) == 1) {
        //Iterando a quantidade de tarefas
        i++;
    }

    //Armazenando o número de tarefas
    lt->qtd = i;

    //Fechando o arquivo
    fclose(f);
    return 0;
};