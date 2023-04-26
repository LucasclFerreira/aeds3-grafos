#include <iostream>
#include <vector>

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
};

int main() {
    Grafo grafo = Grafo(8);
    grafo.adicionar_aresta(0, 1);
    grafo.adicionar_aresta(0, 2);
    grafo.adicionar_aresta(2, 3);
    grafo.adicionar_aresta(3, 4);
    grafo.adicionar_aresta(3, 5);
    grafo.adicionar_aresta(4, 5);
    grafo.adicionar_aresta(4, 6);
    grafo.adicionar_aresta(6, 7);

    grafo.remover_aresta(0, 2);

    grafo.mostrar_lista();
}