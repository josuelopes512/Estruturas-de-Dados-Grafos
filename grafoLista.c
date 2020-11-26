#include <stdio.h>
#include <stdlib.h>
#include "grafoLista.h"
#define NULL ((void *)0)

GrafoLista *adjGrafoLista(int n_nos, int n_pontes, char *alfabeto, int inicial, int *final){
    int i, j;
    GrafoLista *g = (GrafoLista *)malloc(sizeof(GrafoLista));
    g->qtd_no = n_nos;
    g->qtd_aresta = n_pontes;
    g->alfabeto = alfabeto;
    g->inicial = inicial;
    g->final = final;

    g->lista = (Adjacencia *)malloc(n_nos*sizeof(Adjacencia));
    for (i = 0; i < n_nos; i++){
        g->lista[i] = NULL;
    }   
    return g;
}

void liberaGlista(GrafoLista *g){
    free(g->lista);
    free(g);
}

Adjacencia *criaAdj(int vertice, char ponte){
    Adjacencia *temp = (Adjacencia *)malloc(sizeof(Adjacencia));
    temp->no = vertice;
    temp->ponte = ponte;
    temp->vizinhos = NULL;
    return temp;
}

void criarAresta(GrafoLista *g, int inicio, int fim, char ponte){
    if ((g == NULL) || ((fim < 0) || (fim >= g->qtd_no)) || ((inicio < 0) || (inicio >= g->qtd_no))){
        return;
    }
    Adjacencia *novo = criaAdj(fim, ponte);    
	novo->vizinhos = g->lista[inicio];
    g->lista[inicio] = novo;
    //novo = g->lista[inicio]; 
}

void exibeGrafo(GrafoLista *g){
    printf("Vertices: %d. Arestas: %d. \n", g->qtd_no, g->qtd_aresta);
    int i;
    for (i = 0; i <g->qtd_no; i++){
        printf("v%d: ", i);
        Adjacencia *ad = g->lista[i];
        while (ad){
            printf(" v%d(%c)", ad->no, ad->ponte);
            ad = ad->vizinhos;
        }
        printf("\n");
    }
}

void qtdAresta(GrafoLista *g){
    int i, k= 0;
    for (i = 0; i <g->qtd_no; i++){
        Adjacencia *ad = g->lista[i];
        while (ad){
            //printf(" v%d(%d)", ad->no, ad->ponte);
            if (ad != NULL){
                k++;
            }    
            ad = ad->vizinhos;
        }
        //printf("\n");
    }
    printf("Quantidade de Arestas: %d", k);
}

void addEstados(GrafoLista *g){
    int i, ki = 0, kf = 0;
    char texto;

	for (i = 0; i < g->qtd_aresta; i++){  
	  	texto = 0;  
        printf("\n%d - Digite o Estado Si: ", i+1);
        scanf("%d", &ki);
        setbuf(stdin, NULL);
        printf("\n%d - Digite o Estado Sf: ", i+1);
        scanf("%d", &kf);
        setbuf(stdin, NULL);
        printf("\n%d - Digite aresta ligando o S%d para S%d: ", i+1, ki, kf);
        scanf("%c", &texto);
  		setbuf(stdin, NULL);
        //printf("\n"); 
        criarAresta(g, ki, kf, texto);
    }
}

void conferePalavra(GrafoLista *g, char palavra[]){
    int inicial = g->inicial;
    int tamFinal = sizeof(g->final)/sizeof(int);
    int *final = (int *)malloc(tamFinal*sizeof(int));
    
	int i, j = 0, k;	

    i = 0;
    Adjacencia *ad = g->lista[inicial];
    while (i < strlen(palavra)){
        if(ad->ponte == palavra[i] && (ad->no != NULL)){
            printf("\naresta %c letra da palavra %c aceita\n",ad->ponte, palavra[i]);
            i = i + 1;
            ad = g->lista[ad->no];
        }
        if(ad->ponte != palavra[i] && ad->vizinhos != NULL){
            ad = ad->vizinhos;
        }
        if(ad == NULL){
            printf("palavra nao foi aceita");
        }
    }
}


