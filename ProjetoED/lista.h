typedef struct cliente{
    int codigo;
    char nome[30], empresa[30], departamento[30], telefone[15], celular[15], email[30];
}CLIENTE;

typedef struct elemento *Lista;

Lista *cria_lista();

int lista_vazia(Lista *li);

int insere_lista(Lista *li, CLIENTE cli);

int exibir_lista(Lista *li, CLIENTE cli);

int consulta_lista_id(Lista *li, int id, CLIENTE *cli);

int consulta_lista_nome(Lista *li, char nome[30], CLIENTE *cli);

int remove_lista(Lista *li, int id);

void salvar_arquivo(Lista *li);







