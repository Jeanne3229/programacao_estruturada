#include <stdio.h> 
#include <stdlib.h>
#define TAM 4
//Questao com insertion sort a partir de um vetor ja pronto
int main() {
  int numeros [TAM] = {3, 4, 1, 2} //Vetor ja criado sem pedir pro usuario.
  int i, anterior, atual //i e o indice, o anterior é o numero anterior do vetor e atual é o valor que esta no i

  for(i = 1; i <= TAM; i += 1) { //i se inicia no 1 pois começamos a analisar a partir do 2o valor. O primeiro é assumido como ordenado inicialmente
    atual = numeros[i] //Estamos acessando o indice dentro do for e guardando o valor no numero atual.
    anterior = i - 1; //Anterior esta indicado por i - 1, pois ele se trata do valor anterior do indice.
    while (anterior >= 0 && numeros[anterior] > atual) { //enquanto o anterior nao sair do vetor (n for menor q 0) e o numero anterior for maior q o atual
      numeros[anterior + 1] = numeros[anterior] //o numero maior vai para a direita
    numeros[anterior + 1] = atual;

printf("Números ordenados: ");
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", numeros[i]);
    }

    return 0;
}
