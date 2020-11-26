typedef struct grafoMatriz{
    int vertices;
    int arestas;
    int **matriz;
}GrafoMatriz;

GrafoMatriz *adjGrafoMatriz(int n_nos, int n_pontes);
void liberaGmatriz(GrafoMatriz *g);
void addGrafo(GrafoMatriz *g, int inicio, int fim, int ponte);
int verticeMaiorGrau(GrafoMatriz *g);
int qtdArestaMaiorValor(GrafoMatriz *g, int valor);
void exibeMatriz(GrafoMatriz *g);
