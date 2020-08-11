#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


int main(){
    Lista *li;
    int x, opcao, id, confirma, arq;
    CLIENTE cli;
    char nome[30];

    li = cria_lista();

    FILE *f;                    /*Procedimento que vai abrir o arquivo já existente ou criar um novo caso não exista*/
    f = fopen("arquivo.bin", "rb");
    if(f==NULL){
        f=fopen("arquivo.bin","wb");
    }
    while(!feof(f)){
        arq = fread(&cli, sizeof(CLIENTE), 1, f);
        if(arq){
        insere_lista(li, cli);
        }
    }
    fclose(f);

    do{                             /*Menu que irá funcionar enquanto a variável 'opcao' não for 0*/
        printf("\n\n        MENU\n");
        printf("\n1 - Inserir contato");
        printf("\n2 - Exibir lista");
        printf("\n3 - Busca por identificador");
        printf("\n4 - Busca por nome");
        printf("\n5 - Editar contato");
        printf("\n6 - Remover contato");
        printf("\n0 - Sair\n");
        scanf ("%d",&opcao);

        switch (opcao){
            case 1:                 /*Inserção de contato*/
                system("cls");
                printf("\n      INSERIR CONTATO\n");
                printf("\nCodigo: ");
                scanf("%d", &cli.codigo);
                printf("Nome: ");
                getchar();
                gets(cli.nome);
                printf("Empresa: ");
                gets(cli.empresa);
                printf("Departamento: ");
                gets(cli.departamento);
                printf("Telefone: ");
                gets(cli.telefone);
                printf("Celular: ");
                gets(cli.celular);
                printf("E-mail: ");
                gets(cli.email);

                x = insere_lista(li, cli);
                if (x) {
                    system("cls");
                    printf("\nContato inserido com sucesso.");
                } else {
                    system("cls");
                    printf("\nErro ao inserir contato.");
                }
            break;

            case 2:         /*Exibição de lista. Obs: os printfs estão dentro da função em lista.c*/
                x = exibir_lista(li, cli);
                system("cls");
                if(x){
                    printf("\n      LISTA\n");
                    exibir_lista(li, cli);
                }else{
                    printf("\nErro ao exibir lista.");
                }
            break;

            case 3:         /*Busca por código*/
                system("cls");
                printf("\nDigite o codigo: ");
                scanf("%d",&id);
                x = consulta_lista_id(li, id, &cli);
                if(x){
                    system("cls");
                    printf("\n      DADOS\n");
                    printf("\nCodigo: %d", cli.codigo);
                    printf("\nNome: %s", cli.nome);
                    printf("\nEmpresa: %s", cli.empresa);
                    printf("\nDepartamento: %s", cli.departamento);
                    printf("\nTelefone: %s", cli.telefone);
                    printf("\nCelular: %s", cli.celular);
                    printf("\nE-mail: %s\n", cli.email);
                }else{
                    system("cls");
                    printf("\nErro ao buscar codigo.");
                }
            break;

            case 4:     /*Busca por nome. Os printfs estão dentro da função*/
                system("cls");
                printf("\nDigite o nome: ");
                getchar();
                gets(nome);
                consulta_lista_nome(li, nome, &cli);
            break;

            case 5:     /*Procedimento para edição de cliente. Foram usadas as funções de consulta, remoção e inserção.*/
                system("cls");
                printf("\nDigite o codigo do cliente a ser editado: ");
                scanf("%d",&id);
                x = consulta_lista_id(li, id, &cli);
                if(x){
                    system("cls");
                    printf("\n      DADOS\n");
                    printf("\nCodigo: %d", cli.codigo);
                    printf("\nNome: %s", cli.nome);
                    printf("\nEmpresa: %s", cli.empresa);
                    printf("\nDepartamento: %s", cli.departamento);
                    printf("\nTelefone: %s", cli.telefone);
                    printf("\nCelular: %s", cli.celular);
                    printf("\nE-mail: %s\n", cli.email);

                    printf("\nVoce tem certeza que deseja editar este cliente?\n1.Sim\n2.Nao\n");
                    scanf("%d",&confirma);
                    if(confirma==1){
                        remove_lista(li, id);
                        printf("\n      EDITAR CONTATO\n");
                        printf("\nCodigo: ");
                        scanf("%d", &cli.codigo);
                        printf("Nome: ");
                        getchar();
                        gets(cli.nome);
                        printf("Empresa: ");
                        gets(cli.empresa);
                        printf("Departamento: ");
                        gets(cli.departamento);
                        printf("Telefone: ");
                        gets(cli.telefone);
                        printf("Celular: ");
                        gets(cli.celular);
                        printf("E-mail: ");
                        gets(cli.email);
                        x = insere_lista(li, cli);
                        if (x) {
                            system("cls");
                            printf("\nContato editado com sucesso.");
                        } else {
                            system("cls");
                            printf("\nErro ao inserir contato.");
                        }
                    }else if (confirma==2){
                        system("cls");
                        printf("\nCliente nao editado.");
                    }else{
                        system("cls");
                        printf("\nOpcao invalida.");
                    }
                }else{
                    system("cls");
                    printf("\nErro ao buscar codigo.");
                }
            break;

            case 6:     /*Remoção de cliente. Foi usada a função de consulta para a confirmação de remoção*/
                system("cls");
                printf("\nDigite o codigo do cliente a ser removido: ");
                scanf("%d",&id);
                x = consulta_lista_id(li, id, &cli);
                if(x){
                    system("cls");
                    printf("\n      DADOS\n");
                    printf("\nCodigo: %d", cli.codigo);
                    printf("\nNome: %s", cli.nome);
                    printf("\nEmpresa: %s", cli.empresa);
                    printf("\nDepartamento: %s", cli.departamento);
                    printf("\nTelefone: %s", cli.telefone);
                    printf("\nCelular: %s", cli.celular);
                    printf("\nE-mail: %s\n", cli.email);

                    printf("\nVoce tem certeza que deseja remover este cliente?\n1.Sim\n2.Nao\n");
                    scanf("%d",&confirma);

                    if(confirma==1){
                        remove_lista(li, id);
                        system("cls");
                        printf("\nCliente removido com sucesso.");
                    }else if (confirma==2){
                        system("cls");
                        printf("\nCliente nao removido.");
                    }else{
                        system("cls");
                        printf("\nOpcao invalida.");
                    }
                }else{
                    system("cls");
                    printf("\nErro ao buscar codigo.");
                }

            break;

            case 0:         /*Não há nada em case 0, já que ele só serve para sair do while*/
            break;

            default: printf("\nEscolha uma opcao valida");
            break;
            }
    }while(opcao);
    salvar_arquivo(li);     /*Após sair do while, o arquivo será salvo*/
}
