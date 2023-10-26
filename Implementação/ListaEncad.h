#ifndef LISTAENCAD_H
#define LISTAENCAD_H

typedef struct cadastro {
    char nome[30];
    char senha[10];   
} cadastro;

typedef struct produtos {
    char NOME[30];
    char DESCRICAO[100];
    float VALOR;
    int CATEGORIA;
    int QUANTIDADE;
    int QUANT_AVALIACAO;
    int NOTA_AVALIACAO;
} produtos;

typedef struct no_produtos {
    produtos produto;
    struct no_produtos *prox;
    struct no_produtos *ant;
} no_produtos;

typedef struct cliente {
    int total_carrinho;
    int total_comprados;
    no_produtos *carrinho_inicio;
    no_produtos *comprados_inicio;
    cadastro cadastro;
} cliente;

typedef struct vendedor{
    int total_produtos;
    no_produtos *inicio;
    cadastro cadastro;
    char nome_loja[30];
}vendedor;

typedef struct no_vendedores{
    vendedor valor;
    struct no_vendedores *prox;
    struct no_vendedores *ant;
}no_vendedores;

typedef struct no_clientes {
    cliente valor;
    struct no_clientes *prox;
    struct no_clientes *ant;
} no_clientes;

typedef struct lista_clientes {
    int total_clientes;
    no_clientes *inicio;
} lista_clientes;

typedef struct lista_vendedores{
    int total_vendedores;
    no_vendedores *inicio;
}lista_vendedores;

typedef struct lista_produtos
{
    no_produtos *inicio;
}lista_produtos;


lista_clientes *criar_lista_clientes();

int lista_clientes_vazia(lista_clientes *l);

int lista_carrinho_vazia(cliente *l);

int lista_comprados_vazia(cliente *l);

int verifica_cliente(lista_clientes *l,cadastro it);

int insere_novo_cliente(lista_clientes *l,cadastro it);

int insere_nova_compra(lista_clientes *l,cadastro it,produtos p);

int insere_novo_carrinho(lista_clientes *l,cadastro it,produtos p);

int insere_carrinho_comprados(lista_clientes *l,cadastro it);

int remove_do_carrinho(lista_clientes *l,cadastro it,int pos);

int limpa_carrinho(lista_clientes *l,cadastro it);

void mostra_lista_clientes(lista_clientes *l);

void mostrar_comprados(lista_clientes *l,cadastro it);

void mostrar_conta_cliente(lista_clientes *l, cadastro it);

void mostrar_comprados(lista_clientes *l,cadastro it);

void mostrar_carrinho(lista_clientes *l, cadastro it);

int avaliar_produto(lista_clientes *l,lista_vendedores *l2,cadastro it, int pos,int num);

int excluir_conta_cliente(lista_clientes *l, cadastro it);

int limpa_lista_clientes(lista_clientes *l);

int limpa_compra_carrinho(lista_clientes *l,cadastro it);

lista_clientes *ler_clientes();

int salvar_clientes(lista_clientes *l);

//                               TAD PRODUTOS

lista_produtos *criar();

void limpar_lista_produtos(lista_produtos *l);
int tamanho_lista_produtos(lista_produtos *l);
void mostrar_produtos(lista_produtos *l);

int inserirInicio_produtos(lista_produtos *l, produtos it);

int removerInicio_produtos(lista_produtos *l);

int buscarItemChave(lista_produtos *l,int chave,struct produtos *retorno);
int buscarPosicao(lista_produtos *l,int posicao,int *retorno);
int listaVazia_produtos(lista_produtos *l);

int produtos_de_categoria(lista_vendedores *v, int categoria, lista_produtos *p);

int mostrar_5_produtos(lista_vendedores *v, cliente *it, lista_produtos *p);


//                              TAD VENDEDOR


lista_vendedores *criar_lista_vendedores();

int lista_vendedores_vazia(lista_vendedores *l);

int verifica_vendedor(lista_vendedores *l, vendedor v);

int insere_novo_vendedor(lista_vendedores *l,vendedor v);

void mostrar_lista_vendedores(lista_vendedores *l);



#endif