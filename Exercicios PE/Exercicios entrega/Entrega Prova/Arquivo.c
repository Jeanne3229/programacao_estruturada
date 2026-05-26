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
        printf("\nlf", vp[i].preco / 100.00);
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
