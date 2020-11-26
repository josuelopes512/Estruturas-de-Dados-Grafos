#include <stdio.h>
#include <stdlib.h>
#include "grafoMatriz.h"
#define NULL ((void *)0)

//vertice = no
//arestas = peso, ligaçao entre dois nos

GrafoMatriz *adjGrafoMatriz(int n_nos, int n_pontes){
    int i, j;
    GrafoMatriz*g = (GrafoMatriz *)malloc(sizeof(GrafoMatriz));
    g->vertices = n_nos;
    g->arestas = n_pontes;
    g->matriz = (int **)malloc(sizeof(int *)*n_nos );
    for(i = 0; i < n_nos; i++){
    	g->matriz[i] = (int *)malloc(sizeof(int) * n_nos);
	}
    for (i = 0; i < n_nos; i++){
        for (j = 0; j < n_nos; j++){
            g->matriz[i][j] = 0;
        }
    }
    return g;
}

void liberaGmatriz(GrafoMatriz *g){
    int i;
	for(i = 0; i < g->vertices; i++){
        free(g->matriz[i]);
	}
    free(g->matriz);
    free(g);
}

void addGrafo(GrafoMatriz *g, int inicio, int fim, int ponte){
    if(g == NULL){
        return;
    }
    g->matriz[inicio][fim] = ponte;
}

int verticeMaiorGrau(GrafoMatriz *g){
    int i, j, k = 0;
    int *temp = (int *)malloc((g->vertices)*sizeof(int));

    for(i = 0; i < g->vertices; i++){
    	temp[i] = 0;
	}

    for (i = 0; i < g->vertices; i++){
        for (j = 0; j < g->vertices; j++){
            if (g->matriz[i][j] > k){
                temp[i] = g->matriz[i][j];
            } 
            
        }
    }

    for (i = 0; i < g->vertices; i++){
        if (temp[i] > k){
            k = temp[i];
        }
    }

    for (i = 0; i < g->vertices; i++){
        for (j = 0; j < g->vertices; j++){
            if (g->matriz[i][j] == k){
                printf("O vertice de maior grau v%d -> v%d: %d \n", i, j, k);
                return k;
            } 
        }
    }
}

int qtdArestaMaiorValor(GrafoMatriz *g, int valor){
    int i, j, k = 0;
    
    for (i = 0; i < g->vertices; i++){
        for (j = 0; j < g->vertices; j++){
            if (g->matriz[i][j] >= valor){
            	k++;
            }   
        }
    }
	printf("Qtd de Arestas maior ou igual a %d: %d", valor, k);
    return k;
}

void exibeMatriz(GrafoMatriz *g){
	if(g == NULL){
		return;
	}
	
	int i,j;
	for (i = 0; i < g->vertices; i++){
        for (j = 0; j < g->vertices; j++){
        	printf("%d ", g->matriz[i][j] );
        }
        printf("\n");
    }
}
