//selection voce escolhe o menor observando o vetor inteiro e coloca pra o primeiro indice (repete)
//enquanto o insertion desloca/insere valor pra esquerda 

#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void selecao_ordenada(int v[], int tamanho[]) {
  int i, j, menor_indice, temporario; } //i é o indice, j é quem vai observar o vetor inteiro e temporario e quem vai trocar os dois valores sem perder eles (o negocio q o prof deu de ux=a)


//a escolha do indice 
for(i = 0; i < tamanho; i++){
  menor_indice = i; //vamos assumir que o menor indice e i
  //aqui vai olhar o vetor todo (o j começa a frente do i e vai ate o final)
  for(j = i + 1; j < tamanho; j++) { 
    //se o j encontrar alguem menor que o valor que esta armazenado no menor indice 
    if(vetor[j] < vetor[menor_indice]) {
      menor_indice = j; //se encontrar ele vai substituir o j } }

  temp = vetor[menor_indice]; // guarda o menor no temporario 
  vetor[menor_indice] = vetor[i]; // coloca o valor q o i menor estava
  vetor[i] = temporario; //troca os lugares

int main() {
  int numeros[TAM] = {5, 3, 4, 1, 2};
  int i; //definir i novamente pois ele nao existe fora da funcao
  selecao_ordenada(numeros, TAM);

  for(i = 0; i < TAM; i++) {
    printf("{%d}", numeros[i]); }


return 0;
}
