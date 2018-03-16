#include<iostream>
#include<vector>
using namespace std;

class Graph{

private:
    int nodes, edges;
public:
    Graph(int nodes, int edges) {
        this->edges = edges;
        this->nodes = nodes;
    }

    void BFS(int source, int destination);
    void DFS(int source, int destination);
    void Dijkstra(int source, int destination);
};

void Graph::BFS(int source, int destination){

}
int main() {

    Graph *graph = new Graph(3,3);
    graph->BFS();
    return 0;
}
