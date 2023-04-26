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
            lista_adj[v1].erase(remove(lista_adj[v1].begin(), lista_adj[v1].end(), v2), lista_adj[v1].end());
            lista_adj[v2].erase(v1);
        }
};

int main() {

}