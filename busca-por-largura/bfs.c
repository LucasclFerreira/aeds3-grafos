#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

class Grafo {
    private:
        int num_vertices;
        vector<vector<int>> lista_adj;
    public:
        Grafo(int num_vertices) {
            this->num_vertices = num_vertices;
            lista_adj.resize(num_vertices);
        }

        void adicionar_aresta(int v1, int v2) {

            lista_adj[v1].push_back(v2);
            lista_adj[v2].push_back(v1);
        }

        void remover_aresta(int v1, int v2) {
            int i;
            for (i = 0; i < lista_adj[v1].size(); i++) {
                if (lista_adj[v1][i] == v2) {
                    lista_adj[v1].erase(lista_adj[v1].begin() + i);
                    break;
                }
            }

            for (i = 0; i < lista_adj[v2].size(); i++) {
                if (lista_adj[v2][i] == v1) {
                    lista_adj[v2].erase(lista_adj[v2].begin() + i);
                    break;
                }
            }
        }

        void mostrar_lista() {
            for (int i = 0; i < this->num_vertices; i++) {
                printf("\nVertice %d:", i);
                for (auto vert : lista_adj[i])
                    printf(" -> %d", vert);
                printf("\n");
            }
        }

        void bfs(int *visitado, int *anterior, int posicao) {
            int vertice;
            queue<int> fila;
            fila.push_back(posicao);
            visitado[posicao] = 1;
            int vizinhos[lista_adj[posicao].size()];

            while (!fila.empty()) {
                vertice = fila.pop_front();
                for (int j = 0; j < lista_adj[vertice]; j++) {
                    vizinhos[j] = lista_adj[vertice][j];
                }
            }
            
            for (auto vizinho : vizinhos) {
                if (!visitado[vizinho]) {
                    fila.push_back(vizinho);
                    visitado[vizinho] = 1;
                    anterior[vizinho] = vertice
                }
            }

        }
};

int main() {
    int num_vertices = 8;
    int visitado[num_vertices];  // declarando vetor para usar no dfs
    int anterior[num_vertices];
    for (int i = 0; i < num_vertices; i++) {  // preenchendo o vertor com zeros
        visitado[i] = 0;
        anterior[i] = 0;
    }

    Grafo grafo = Grafo(num_vertices);
    grafo.adicionar_aresta(0, 1);
    grafo.adicionar_aresta(0, 2);
    grafo.adicionar_aresta(2, 3);
    grafo.adicionar_aresta(3, 4);
    grafo.adicionar_aresta(3, 5);
    grafo.adicionar_aresta(4, 5);
    grafo.adicionar_aresta(4, 6);
    grafo.adicionar_aresta(6, 7);

    return 0;
}