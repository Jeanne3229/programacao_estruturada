#include <stdio.h>
#include <stdlib.h>
#define CARACTERES 50
#define TAM 2


struct Contas{
    int n_conta;
    char nome[CARACTERES];
    int cpf;
    int telefone;
};

int qtdStr(char texto[]){
    int i = 0;
    while(texto[i] != '\0'){
        i += 1;
    }
    return i;
}

void lerStr(char str[], int max){
    fgets(str, max, stdin);
    int tam = qtdStr(str);
    if(tam > 0 && str[tam - 1] == '\n'){
        str[tam - 1] = '\0';
    }
}




void Cadastro(struct Contas *C, int tamanho){
    for(int i = 0; i < tamanho; i++){
        printf("\nDigite o numero da conta[%d]: ",i);
        scanf("%d", &C[i].n_conta);
        printf("\nDigite o nome[%d]: ", i);
        lerStr(C[i].nome, CARACTERES);
        lerStr(C[i].nome, CARACTERES);
        printf("\nDigite seu CPF[%d]: ", i);
        scanf("%d", &C[i].cpf);
        printf("\nDigite seu numero de telefone[%d]: ", i);
        scanf("%d", &C[i].telefone);
    }
}



int main()
{
    struct Contas corrente[TAM];
    struct Contas poupanca[TAM];
    printf("\n-----AREA CADASTRO INICIAL CONTA *CORRENTE*----\n");
    Cadastro(corrente, TAM);
    printf("\n-----AREA CADASTRO INICIAL CONTA *POUPANCA*----\n");
    Cadastro(poupanca, TAM);





    return 0;
}
