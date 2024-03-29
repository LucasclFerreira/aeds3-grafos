#include <iostream>
#include <stdlib.h>

using namespace std;

class Grafo {
    private:
        int num_vertices;  // total de vértices do grafo
        int **mat_adj;  // criado um vetor de vetores de int para a matriz
    public:
        Grafo(int num_vertices) {
            this->num_vertices = num_vertices;
            mat_adj = new int*[num_vertices];
            for (int i = 0; i < num_vertices; i++) {
                mat_adj[i] = new int[num_vertices];
                for (int j = 0; j < num_vertices; j++) {
                    mat_adj[i][j] = 0;
                }
            }
        }

        void adicionar_aresta(int v1, int v2) {
            mat_adj[v1][v2] = 1;
            mat_adj[v2][v1] = 1;
        }

        void remover_aresta(int v1, int v2) {
            mat_adj[v1][v2] = 0;
            mat_adj[v2][v1] = 0;
        }

        void mostra_mat() {
            for (int i = 0; i < num_vertices; i++) {
                printf("%d: ", i);
                for (int j = 0; j < num_vertices; j++)
                    printf("%d ", mat_adj[i][j]);
                printf("\n");
            }
        }
};

int main() {
    // r = 0; v = 1; s = 2; w = 3; t = 4; x = 5; u = 6; y = 7
    Grafo grafo = Grafo(8);
    grafo.adicionar_aresta(0, 1);
    grafo.adicionar_aresta(0, 2);
    grafo.adicionar_aresta(2, 3);
    grafo.adicionar_aresta(3, 4);
    grafo.adicionar_aresta(3, 5);
    grafo.adicionar_aresta(4, 5);
    grafo.adicionar_aresta(4, 6);
    grafo.adicionar_aresta(6, 7);

    grafo.mostra_mat();

    return 0;
}