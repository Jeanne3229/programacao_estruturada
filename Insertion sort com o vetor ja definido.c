#include <stdio.h>
#include <stdlib.h>
#define TAM 7

void ordenar_precos(double precos[], int tamanho){ //definicao dos parametros e funcao
  int i, anterior;
  double atual;

for(i = 0; i < tamanho; i++) {
  atual = precos[i]; //definicao do indice de precos ser igual a variavel atual
  anterior = i - 1;} //anterior para voltar ao indice 0 para comparacao
  while(anterior >= 0 && precos[anterior] > atual) { //anterior tem q ser maior q 0 ou igual para nao fugir dos indices e o preco anterior tem que ser maior q o atual para ser colocado na esquerda.
    precos[anterior + 1] = precos[anterior] //o anterior mais um é a cadeira da direita e o preco anterior normal é a esquerda, voce meio que pega o valor que ta na esquerda e bota pra direita se ele estiver de acordo com o while.
    anterior = anterior - 1} //para garantir que ele sempre diminua para comparacao 
  precos[anterior + 1] = atual; } //definir o indice seguinte como atual fora do while, pois so vai ser executado depois que todas estiverem ordenadas

int main() {
  double precos[7] = {45.50, 12.90, 89.00, 5.50, 34.00, 21.00, 67.00};
  int i;

  ordenar_precos(precos, TAM);

  for(i = 0; i < TAM; i++) {
    printf("{%.2f}", precos[i]);}

return 0; }

  

      
