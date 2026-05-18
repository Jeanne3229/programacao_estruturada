#include <stdio.h>
#include <stdlib.h>
#define TAM 26
#define CARACTERES 30

//STRUCT INICIAL !!
struct Estados{
    char nome[CARACTERES];
    int veiculos;
    int acidentes;
};

//FUNCOES AUXILIARES
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

//coletar dados - Funcao 1

void preencher(struct Estados *E, int tamanho){
    char tempStr[CARACTERES];
    for(int i = 0; i < tamanho; i++){
        printf("\nDigite o nome do estado[%d]: ", i);
        lerStr(E[i].nome, CARACTERES);
        printf("\nDigite a quantidade de veiculos do estado[%d]: ", i);
        scanf("%d", &E[i].veiculos);
        printf("\nDigite a quantidade de acidentes do estado[%d]: ", i);
        scanf("%d", &E[i].acidentes);
        lerStr(tempStr, CARACTERES);
        printf("\n--------\n");

    }
    printf("\n*FIM DA FUNCAO DE COLETA*\n");
}


//2a funcao
void MaiorMenor(struct Estados *E, int tamanho, int *maior, int *menor){ //passar como ponteiros pra mudar no main
    *maior = 0;
    *menor = 0;
    for(int i = 0; i < tamanho; i++){
        if(E[i].acidentes > E[*maior].acidentes){ //se o numero atual de acidentes for maior q o numero de acidentes criado inicia-
            *maior = i; //almente, ele toma o lugar. Nessa linha guardamos sua posicao !!
        }
        if(E[i].acidentes < E[*maior].acidentes){
            *menor = i;
        }
    }
}

//3a funcao
double percentual(struct Estados *E, int estado){
    return (E[estado].acidentes * 100.0) / E[estado].veiculos;
}

//4a funcao
double media(struct Estados *E, int tamanho){
    double somaM = 0;
    for(int i = 0; i < tamanho; i++){
        somaM += E[i].acidentes;
    }
    return somaM / tamanho;
}

//5a funcao
void AcimaDaMedia(struct Estados *E, int tamanho, double media){
    printf("\n*NOME DOS ESTADOS QUE ESTAO ACIMA DA MEDIA DE ACIDENTES DO PAIS*\n");
   for(int i = 0; i < tamanho; i++){
    if(E[i].acidentes > media){
        printf("\n-%s", E[i].nome);
    }
   }
}

int main()
{
    struct Estados meuVet[TAM];
    preencher(meuVet, TAM);
    int maior = 0;
    int menor = 0;
    MaiorMenor(meuVet, TAM, &maior, &menor);
    printf("\n");
    printf("\n*AREA DE EXIBICAO DE MAIOR E MENOR ACIDENTES*\n");
    printf("\nEstado com maior quantidade de acidentes: %s\n", meuVet[maior].nome);
    printf("\nEstado com menor quantidade de acidentes: %s", meuVet[menor].nome);


    for(int i = 0; i < TAM; i++){
        printf("\n*Nome do Estado*: %s \n*Percentual*: %lf\n", meuVet[i].nome, percentual(meuVet, i));
    }


    double mediaP; //variavel auxiliar
    mediaP = media(meuVet, TAM);

    printf("\n*AREA PERCENTUAL DO PAIS*");
    printf("\nA media do pais e: %lf\n", mediaP);
    printf("\n------------------------------\n");
    AcimaDaMedia(meuVet, TAM, mediaP);
    return 0;
}
