typedef struct Vertice{
    int no;
    char ponte;
    struct Vertice *vizinhos;
}Adjacencia;

typedef struct grafoLista{
    int qtd_no;
    int qtd_aresta;
    char *alfabeto;
    int inicial;
    int *final;
    struct Vertice **lista;
}GrafoLista;



GrafoLista *adjGrafoLista(int n_nos, int n_pontes, char *alfabeto, int inicial, int *final);
void criarAresta(GrafoLista *g, int inicio, int fim, char ponte);
void liberaGlista(GrafoLista *g);
Adjacencia *criaAdj(int vertice, char ponte);
void exibeGrafo(GrafoLista *g);
void qtdAresta(GrafoLista *g);
void addEstados(GrafoLista *g);
