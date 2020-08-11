#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

/*A maioria das funções foram adaptadas das mostradas em sala. As funções diferentes estão comentadas abaixo.*/

struct elemento{
    struct elemento *ant;
    struct elemento *prox;
    CLIENTE dados;
};

typedef struct elemento Elem;

Lista *cria_lista(){
    Lista *li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL){
        *li = NULL;
    }
    return li;
}

int lista_vazia(Lista *li){
    if(li == NULL){
        return 1;
    }
    if(*li == NULL){
        return 1;
    }
    return 0;
}

int insere_lista(Lista *li, CLIENTE cli){
    if(li == NULL){
        return 0;
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL){
        return 0;
    }
    no->dados = cli;
    if(lista_vazia(li)){
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }else{
        Elem *anterior, *atual = *li;
        while(atual != NULL && atual->dados.codigo < cli.codigo){
            anterior = atual;
            atual = atual->prox;
        }
        if(atual == *li){
            no->ant = NULL;
            (*li)->ant = no;
            no->prox=(*li);
            *li = no;
        }else{
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if(atual != NULL){
                atual->ant = no;
            }
        }
    }
    return 1;
}

/*Essa função basicamente passa pela lista toda imprimindo as informações de contato até o fim da lista*/
int exibir_lista(Lista *li, CLIENTE cli){
    if(li == NULL){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL){
        cli=no->dados;
        printf("\nCodigo: %d", cli.codigo);
        printf("\nNome: %s", cli.nome);
        printf("\nEmpresa: %s", cli.empresa);
        printf("\nDepartamento: %s", cli.departamento);
        printf("\nTelefone: %s", cli.telefone);
        printf("\nCelular: %s", cli.celular);
        printf("\nE-mail: %s\n", cli.email);
        no=no->prox;
    }

}

int consulta_lista_id(Lista *li, int id, CLIENTE *cli){
    if(li == NULL){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL && no->dados.codigo != id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }else{
        *cli = no->dados;
        return 1;
    }
}

/*Foi usado o strcmp para identificar quando o nome digitado é igual ao nome de determinada posição da lista(se strcmp==0 isso
significa que as strings são iguais)*/
int consulta_lista_nome(Lista *li, char nome[30], CLIENTE *cli){
    if(li == NULL){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL){
        int aux = strcmp(no->dados.nome, nome)==0;
        if (aux){
            *cli = no->dados;
            printf("\n      DADOS\n");
            printf("\nCodigo: %d", cli->codigo);
            printf("\nNome: %s", cli->nome);
            printf("\nEmpresa: %s", cli->empresa);
            printf("\nDepartamento: %s", cli->departamento);
            printf("\nTelefone: %s", cli->telefone);
            printf("\nCelular: %s", cli->celular);
            printf("\nE-mail: %s\n", cli->email);
            no = no->prox;
        }else{
        no = no->prox;
        }
    }
    if(no == NULL){
        return 0;
    }
}

int remove_lista(Lista *li, int id){
    if(li == NULL){
        return 0;
    }
    Elem *no = *li;
    while(no != NULL && no->dados.codigo != id){
        no = no->prox;
    }
    if(no == NULL){
        return 0;
    }
    if(no->ant == NULL){
        *li = no->prox;
    }else{
        no->ant->prox = no->prox;
    }
    if(no->prox != NULL){
        no->prox->ant = no->ant;
    }
    free(no);
    return 1;
}

/*Função para salvar arquivo que passa por toda a lista armazenando os dados onde o valor não é nulo*/
void salvar_arquivo(Lista *li){
    FILE *f=fopen("arquivo.bin", "wb");
    Elem *no=*li;
    CLIENTE cli;
    while(no!=NULL){
        cli=no->dados;
        fwrite(&cli, sizeof(CLIENTE), 1, f);
        no=no->prox;
    }
    fclose(f);
}





