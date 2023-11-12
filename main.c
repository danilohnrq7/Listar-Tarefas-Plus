//Danilo Henrique de Paulo  22.222.008-9
//Turma: 610
//Disciplina: CC2632

//Projeto 1 - Gerenciamento de tarefas

#include <stdio.h>
#include "biblioteca.h"

int main(void) {

    ListaDeTarefas ListaGeral;
    zerarListaDeTarefas(&ListaGeral);
    //Variaveis para ler o comando do usuario e verificar o retorno das funções
    int opcao, controle;

    //Lendo o arquivo e verificando o retorno da função
    controle = carregarTarefas(&ListaGeral);
    if (controle != 0){
        printf("\nErro ao tentar executar a funcao :(\n");
    }

    printf("Bem Vindo ao programa de gerenciamento de tarefas!!!\n\n");

    //Usando um laço de repetição para o Menu
    do {
        //Função de print do menu
        printMenu();

        //Lendo o número da opção desejada
        printf("Digite o numero da opcao desejada: ");
        scanf("%d",&opcao);
        printf("\n----------------------------------\n\n");

        //Número 1 chama a função cadastrar
        if (opcao == 1){
            printf("Funcao 1 - Cadastrar\n");

            //Chamando a função de cadastro e verificando seu retorno
            controle = cadastrarTarefa(&ListaGeral);
            if (controle != 0){
                printf("\nErro ao tentar executar a funcao :(\n");
            }
        }
            //Número 2 chama a função deletar
        else if (opcao == 2){
            printf("Funcao 2 - Deletar\n");

            //Chamando a função de delete e verificando seu retorno
            controle = deletarTarefa(&ListaGeral);
            if (controle != 0){
                printf("\nErro ao tentar executar a funcao :(\n");
            }
        }
            //Número 3 chama a função listar
        else if (opcao == 3){
            printf("Funcao 3 - Listar\n");

            //Chamando a função de lista e verificando seu retorno
            controle = listarTarefas(ListaGeral);
            if (controle != 0){
                printf("\nErro ao tentar executar a funcao :(\n");
            }
        }else if (opcao == 4){
            printf("Funcao 4 - Alterarr\n");

            //Chamando a função de alteração e verificando seu retorno
            controle = alterarTarefa(&ListaGeral);
            if (controle != 0){
                printf("\nErro ao tentar executar a funcao :(\n");
            }
        }
            //Qualquer outro digito além de 0, 1, 2, 3 ou 4 informará ao usuário que a opção escolhida não é válida e repetirá o menu
        else if (opcao != 0){
            printf("Opcao invalida :(\n");
        }

        printf("\n----------------------------------\n\n");
    }
        //Caso o usuário digite 0 o laço acabará
    while (opcao != 0);
    //Mensagem de despedida
    printf("Ate mais :)");

    return 0;
}