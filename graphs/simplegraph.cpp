#include <iostream>
using namespace std;

class Graph {
private:
    int V;
    int **adj;

public:
    Graph(int V) {
        this->V = V;
        adj = new int*[V];
        for (int i = 0; i < V; i++) {
            adj[i] = new int[V];
            for (int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void printAdjMatrix() {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << i + 1 << " --> ";
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1) {
                    cout << j + 1 << " ";
                }
            }
            cout << endl;
        }
    }

    ~Graph() {
        for (int i = 0; i < V; i++) {
            delete[] adj[i];
        }
        delete[] adj;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 4);
    g.addEdge(3, 4);

    cout << "Adjacency Matrix:" << endl;
    g.printAdjMatrix();

    cout << "Adjacency List:" << endl;
    g.printAdjList();

    return 0;
}
