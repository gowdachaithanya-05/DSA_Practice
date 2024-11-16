#include <iostream>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;
    int numVertices;

    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        if (src != dest) {
            adjList[dest].push_back(src);
        }
    }
};

void bfs(Graph& graph, int startVertex) {
    vector<bool> visited(graph.numVertices, false);
    queue<int> q;
    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int currentVertex = q.front();
        q.pop();
        cout << currentVertex << " ";

        for (int adjVertex : graph.adjList[currentVertex]) {
            if (!visited[adjVertex]) {
                visited[adjVertex] = true;
                q.push(adjVertex);
            }
        }
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

    int startVertex;
    cout << "Enter the starting vertex for BFS: ";
    cin >> startVertex;

    cout << "BFS traversal starting from vertex " << startVertex << ":\n";

    clock_t startTime = clock();
    bfs(graph, startVertex);
    clock_t endTime = clock();

    double timeTaken = double(endTime - startTime) / CLOCKS_PER_SEC;
    cout << "Time taken for BFS: " << timeTaken << " seconds" << endl;

    return 0;
}
