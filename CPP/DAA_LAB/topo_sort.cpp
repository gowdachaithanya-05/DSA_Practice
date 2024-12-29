#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;
    int numVertices;

    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }
};

void dfsUtil(int v, vector<bool>& visited, stack<int>& Stack, const vector<vector<int>>& adjList) {
    visited[v] = true;

    for (auto& i : adjList[v]) {
        if (!visited[i]) {
            dfsUtil(i, visited, Stack, adjList);
        }
    }

    Stack.push(v);
}

void topologicalSort(Graph& graph) {
    stack<int> Stack;
    vector<bool> visited(graph.numVertices, false);

    for (int i = 0; i < graph.numVertices; i++) {
        if (!visited[i]) {
            dfsUtil(i, visited, Stack, graph.adjList);
        }
    }

    while (!Stack.empty()) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
    cout << endl;
}

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph graph(numVertices);

    cout << "Enter the number of edges: ";
    cin >> numEdges;

    cout << "Enter the edges (src dest):\n";
    for (int i = 0; i < numEdges; ++i) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    cout << "Topological Sort of the graph:\n";
    topologicalSort(graph);

    return 0;
}
