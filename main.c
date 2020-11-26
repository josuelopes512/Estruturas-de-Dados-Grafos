#include <stdio.h>
#include <stdlib.h>
#include "grafoLista.h"

int main(int argc, char const *argv[]){
  int grafos = 0, arestas = 0, i, inicial, qtd_final;
  char alfabeto[200];
  int tamPalavra;
  
      
  printf("Estrutura de Dados - Tipo de Grafo: Lista de Adjacencia");
  
  printf("\nQTD de Estados: ");
  scanf("%d", &grafos); //4
  setbuf(stdin, NULL);
  
  printf("\nQTD de Arestas: ");
  scanf("%d", &arestas); //4
  setbuf(stdin, NULL);

  printf("\nAlfabeto: ");
  scanf("%s", alfabeto); 
  setbuf(stdin, NULL);

  printf("\nEstado Inicial: S");
  scanf("%d", &inicial); 
  setbuf(stdin, NULL);

  printf("QTD de Estados Finais: ");
  scanf("%d", &qtd_final); 
  setbuf(stdin, NULL);

  int *final = (int *)malloc(qtd_final*sizeof(int));

  for (i = 0; i < qtd_final; i++){
    printf("\n%d - Estado Final: S",i+1);
    scanf("%d", &final[i]);
    setbuf(stdin, NULL);
  }
  
  printf("Digite o tamanho da palavra: ");
  scanf("%d", &tamPalavra);
  char *palavra = (char *)malloc(tamPalavra*sizeof(char));
  
  printf("\nDigite a Palavra: ");
  scanf("%s", palavra); 
  setbuf(stdin, NULL);
  
  
 
  GrafoLista *gl = adjGrafoLista(grafos, arestas, alfabeto, inicial, final);
  addEstados(gl);
  exibeGrafo(gl);
  conferePalavra(gl, palavra);
  

  return 0;
}
