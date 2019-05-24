#include <iostream>
#include <list>

using namespace std;

class Graph {
    int numberOfVertices;
    list<int> *adjacencyList;

    public:
        Graph(int vertices);
        void addEdge(int v, int w);
        void BFS(int source);
        void InitializeDFS(int v);
        void DFS(int v, bool visited[]);
};

Graph::Graph(int vertices) {
    this->numberOfVertices = vertices;
    adjacencyList = new list<int>[vertices];
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::BFS(int source) {

    bool *visited = new bool[numberOfVertices];
    for(int i=0; i<numberOfVertices; i++) {
        visited[i] = false;
    }

    list<int> queue;

    visited[source] = true;
    queue.push_back(source);

    list<int>::iterator i;

    while(!queue.empty()) {
        source = queue.front();
        cout << source << " ";
        queue.pop_front();

        for(i = adjacencyList[source].begin(); i != adjacencyList[source].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

void Graph::DFS(int source, bool visited[]) {
    visited[source] = true;
    cout << source << " ";

    list<int>::iterator i;
    for(i = adjacencyList[source].begin(); i != adjacencyList[source].end(); ++i) {
        if (!visited[*i]) {
            DFS(*i, visited);
        }
    }
}

void Graph::InitializeDFS(int v) {
    bool *visited = new bool[numberOfVertices];
    for(int i=0; i < numberOfVertices; i++) {
        visited[i] = false;
    }

    DFS(v, visited);
}

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.BFS(0);

    g.InitializeDFS(0);

    return 0;
}
