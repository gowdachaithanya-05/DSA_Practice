#include <iostream>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;
    int numVertices;

    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }
};

void dfs(Graph& graph, int startVertex, vector<bool>& visited) {
    stack<int> stk;
    stk.push(startVertex);

    while (!stk.empty()) {
        int currentVertex = stk.top();
        stk.pop();

        if (!visited[currentVertex]) {
            cout << currentVertex << " ";
            visited[currentVertex] = true;
        }

        for (int adjVertex : graph.adjList[currentVertex]) {
            if (!visited[adjVertex]) {
                stk.push(adjVertex);
            }
        }

    }
    cout << endl;
}

bool isConnected(Graph& graph) {
    vector<bool> visited(graph.numVertices, false);
    dfs(graph, 0, visited); // Start DFS from vertex 0

    // Check if all vertices are visited
    for (bool v : visited) {
        if (!v) return false;
    }
    return true;
    // for(int i=0; i<graph.numVertices; i++) {
    //     if(!visited[i]) {
    //         dfs(graph, i, visited);
    //     }
    // }    
}

int main() {
    int numVertices, numEdges;
    clock_t s, e;
    double t;

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

    // Check if the graph is connected
    if (isConnected(graph)) {
        cout << "The graph is connected." << endl;

        int startVertex;
        cout << "Enter the starting vertex for DFS: ";
        cin >> startVertex;

        vector<bool> visited(graph.numVertices, false);
        s = clock();
        cout << "DFS traversal starting from vertex " << startVertex << ":\n";
        dfs(graph, startVertex, visited);
        e = clock();

        t = double(e - s) / CLOCKS_PER_SEC;
        cout << "Time taken for DFS: " << t << " seconds" << endl;
    } else {
        cout << "The graph is not connected." << endl;
        dfs(graph, startVertex, visited);
    }

    return 0;
}
