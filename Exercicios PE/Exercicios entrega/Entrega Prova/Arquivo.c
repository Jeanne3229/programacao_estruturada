#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

struct Categoria{
    int codigo;
    char nome[50];
};

struct Produto{
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria;
    int preco;
};

int busca(struct Categoria *C, int codigo, int tamanho){
    if(tamanho == 0){
        return -1;
    }
    for(int i = 0; i < tamanho; i++){
        if(C[i].codigo == codigo){
            return i;
        }
    }
    return -2;
}

void lerStr(char str[], int max){
    fgets(str, max, stdin);
    int tam = strlen(str);
    if(max > 0 && str[tam - 1] == '\n'){
        str[tam - 1] = '\0';
    }
}

void CadastrarCategoria(struct Categoria v[], int *qtd){
    if(*qtd >= TAM){
        return;
    }
    printf("\nDigite o codigo da *categoria*: ");
    scanf("%d", &v[*qtd].codigo);
    int pos = busca(v, v[*qtd].codigo, *qtd);
    if(pos >= 0){
        printf("\nEsse codigo ja existe no sistema!");
        return;
    }

    printf("\nDigite o nome da categoria que voce deseja cadastrar: ");
    lerStr(v[*qtd].nome, 50);
    lerStr(v[*qtd].nome, 50);
    *qtd += 1;
}


void imprimirCategoria(struct Categoria v[], int qtd){
    for(int i = 0; i < qtd; i++){
        printf("\nCODIGO DA CATEGORIA: %d", v[i].codigo);
        printf("\nTITULO: %s", v[i].nome);
    }
}

void imprimirProduto(struct Produto vp[], int qtdProduto, struct Categoria vc[], int qtdcategoria){
    int j;
    for(int i = 0; i < qtdProduto; i++){
        printf("\nCODIGO: %d", vp[i].codigo);
        printf("\nTITULO: %s", vp[i].titulo);
        printf("\nDESCRICAO: %s", vp[i].descricao);
        j = busca(vc, vp[i].categoria, qtdcategoria);
        printf("\n%lf", vp[i].preco / 100.00);
        if(j >= 0){
        printf("\n%s", vc[j].nome);
        }
    }
}

void selectionSort(struct Produto v[], int qtd){
    int i, j, menor;
    struct Produto aux;
    for(i = 0; i < qtd - 1; i++){
        menor = i;
        for(j = i + 1; j <= qtd - 1; j++){
            if(strcmp(v[j].descricao, v[menor].descricao) < 0){
                menor = j;
        }
    }
    aux = v[i];
    v[i] = v[menor];
    v[menor] = aux;
} }

void buscaBinaria(struct Produto v[], int qtd, char *x){
    int inicio = 0;
    int fim = qtd - 1;
    int meio;

    while(inicio <= fim){

        meio = (inicio + fim) / 2;

        int comp = strcmp(v[meio].descricao, x);

        if(comp == 0){
            printf("Encontrado!\n");
            printf("%s\n", v[meio].descricao);
            return;
        }
        else if(comp > 0){
            fim = meio - 1;
        }
        else{
            inicio = meio + 1;
        }
    }
    printf("Nao encontrado!\n");
}


int main(){
    //Declaração dos vetores e contadores de quantidade de cada
    struct Categoria categorias[TAM];
    struct Produto produtos[TAM];
    int qtdCategorias = 0;
    int qtdProdutos = 0;
    int opcao;
    char termoBusca[256];

    do {
        printf("\n====SISTEMA DE ESTOQUE====\n");
        printf("1. Cadastrar Categoria\n");
        printf("2. Imprimir Categorias\n");
        printf("3. Cadastrar Produto (Teste)\n");
        printf("4. Imprimir Produtos\n");
        printf("5. Ordenar Produtos por Descricao (Selection Sort)\n");
        printf("6. Buscar Produto por Descricao (Busca Binaria)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao) {
            case 1:
                CadastrarCategoria(categorias, &qtdCategorias);
                break;
            case 2:
                if (qtdCategorias == 0) {
                    printf("\nNenhuma categoria cadastrada ainda.\n");
                } else {
                    imprimirCategoria(categorias, qtdCategorias);
                }
                break;
            case 3:
                if(qtdProdutos >= TAM) {
                    printf("\nEstoque de produtos cheio!\n");
                    break;
                }
                printf("\n---CADASTRAR PRODUTO---\n");
                printf("Codigo do produto: ");
                scanf("%d", &produtos[qtdProdutos].codigo);
                getchar();
                printf("Titulo do produto: ");
                lerStr(produtos[qtdProdutos].titulo, 100);
                printf("Descricao do produto: ");
                lerStr(produtos[qtdProdutos].descricao, 256);
                printf("Codigo da Categoria a qual ele pertence: ");
                scanf("%d", &produtos[qtdProdutos].categoria);
                printf("Preco: ");
                scanf("%d", &produtos[qtdProdutos].preco);
                qtdProdutos++;
                printf("\nProduto cadastrado com sucesso!\n");
                break;

            case 4:
                if (qtdProdutos == 0) {
                    printf("\nNenhum produto cadastrado ainda!\n");
                } else {
                    imprimirProduto(produtos, qtdProdutos, categorias, qtdCategorias);
                }
                break;

            case 5:
                if (qtdProdutos > 0) {
                    selectionSort(produtos, qtdProdutos);
                    printf("\nProdutos ordenados por descricao com sucesso!\n");
                } else {
                    printf("\nCadastre produtos antes de ordenar\n");
                }
                break;

            case 6:
                if (qtdProdutos == 0) {
                    printf("\nNenhum produto cadastrado para buscar\n");
                    break;
                }
                printf("\nDigite a descricao exata do produto que deseja buscar: ");
                lerStr(termoBusca, 256);
                buscaBinaria(produtos, qtdProdutos, termoBusca);
                break;
            case 0:
                printf("\nEncerrando o sistema\n");
                break;
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
