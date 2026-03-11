#include <stdio.h>
#include <stdlib.h>
#define MAX_QTD 30
int main(){
  double nota1[MAX_QTD], nota2[MAX_QTD], media[MAX_QTD]; //Definir as variaveis
  int i; //definir para usar no primeiro for
  double soma_medias = 0; //para usar na media da turma, vai ser a soma de cada media
  double media_turma;
  //Pedir ao usuário a digitação das notas:

  for(i = 0; i < MAX_QTD; i += 1){
    printf("Digite a nota1 do aluno [%d]: ", i + 1);
    scanf("%lf", &nota1[i]); //Guardar em cada indice uma nota1 individual.
    printf("Digite a nota2 do aluno [%d]: ", i + 1);
    scanf("%lf", &nota2[i]); } //Guardar em cada indice uma nota2 individual.

  //Agora vamos calcular a media individual, somar elas e colocar na varial soma_medias para que a gente calcule a media da turma.

  for(i = 0; i < MAX_QTD; i += 1){
    media[i] = ((nota1[i] * 2.0) + (nota2[i] * 3.0)) / 5.0; //Calcula as medias individuais
    soma_medias += media[i]; } //A variavel vai guardar a soma das medias individuais

  media_turma = soma_medias / MAX_QTD; //Divide-se por MAX_QTD pois se trata de uma media simples, enquanto a media individual é uma media ponderada.
  printf("A media da turma e: %lf \n", media_turma);

  //Agora imprimir as notas e media dos alunos que possuem a media maior que a media da turma:

  for(i = 0; i < MAX_QTD; i += 1){
    if(media[i] > media_turma){
      printf("O aluno [%d] \n sua 1a nota foi: %.2f \n sua 2a nota foi: %.2f \n sua media foi: %.2f \n", i + 1, nota1[i], nota2[i], media[i]);} }


  printf("FIM DO PROGRAMA");



return 0;

}
