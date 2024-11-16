// #include <iostream>
// #include <vector>
// #include <queue>
// #include <climits>
// using namespace std;

// typedef pair<int, int> pii;

// void addEdge(vector<vector<pii>>& graph, int u, int v, int weight) {
//     graph[u].push_back(make_pair(weight, v));
//     graph[v].push_back(make_pair(weight, u));
// }

// void printPath(vector<int>& parent, int j) {
//     vector<int> path;
//     while (j != -1) {
//         path.push_back(j);
//         j = parent[j];
//     }
//     for (int i = path.size() - 1; i > 0; --i) {
//         cout << path[i] << " -> ";
//     }
//     cout << path[0];
// }

// void dijkstra(vector<vector<pii>>& graph, int V, int startVertex) {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     vector<int> dist(V, INT_MAX);
//     vector<int> parent(V, -1);

//     dist[startVertex] = 0;
//     pq.push(make_pair(0, startVertex));

//     while (!pq.empty()) {
//         int u = pq.top().second;
//         pq.pop();

//         for (auto& i : graph[u]) {
//             int v = i.second;
//             int weight = i.first;

//             if (dist[v] > dist[u] + weight) {
//                 dist[v] = dist[u] + weight;
//                 pq.push(make_pair(dist[v], v));
//                 parent[v] = u;
//             }
//         }
//     }

//     cout << "Shortest paths from vertex " << startVertex << " to all other vertices:" << endl;
//     for (int i = 0; i < V; ++i) {
//         if (i != startVertex) {
//             cout << "Path to vertex " << i << ": ";
//             printPath(parent, i);
//             cout << " - Distance: " << dist[i] << endl;
//         }
//     }
// }

// int main() {
//     int V, E;
//     cout << "Enter the number of vertices: ";
//     cin >> V;
//     cout << "Enter the number of edges: ";
//     cin >> E;

//     vector<vector<pii>> graph(V);

//     cout << "Enter edges (u, v, weight):" << endl;
//     for (int i = 0; i < E; ++i) {
//         int u, v, weight;
//         cin >> u >> v >> weight;
//         addEdge(graph, u, v, weight);
//     }

//     int startVertex;
//     cout << "Enter the starting vertex (0 to " << V - 1 << "): ";
//     cin >> startVertex;

//     dijkstra(graph, V, startVertex);

//     return 0;
// }





#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
#include <string>
using namespace std;

typedef pair<int, int> pii;

void addEdge(vector<vector<pii>>& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(weight, v));
    graph[v].push_back(make_pair(weight, u));
}

void printPath(vector<int>& parent, int j, const vector<string>& vertexNames) {
    vector<int> path;
    while (j != -1) {
        path.push_back(j);
        j = parent[j];
    }
    for (int i = path.size() - 1; i > 0; --i) {
        cout << vertexNames[path[i]] << " -> ";
    }
    cout << vertexNames[path[0]];
}

void dijkstra(vector<vector<pii>>& graph, int V, int startVertex, const vector<string>& vertexNames) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& i : graph[u]) {
            int v = i.second;
            int weight = i.first;

            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                parent[v] = u;
            }
        }
    }

    cout << "Shortest paths from " << vertexNames[startVertex] << " to all other vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        if (i != startVertex) {
            cout << "Path to " << vertexNames[i] << ": ";
            printPath(parent, i, vertexNames);
            cout << " - Distance: " << dist[i] << endl;
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    unordered_map<string, int> vertexMap;
    vector<string> vertexNames(V);
    vector<vector<pii>> graph(V);

    cout << "Enter the names of the vertices:" << endl;
    for (int i = 0; i < V; ++i) {
        cin >> vertexNames[i];
        vertexMap[vertexNames[i]] = i;
    }

    cout << "Enter edges (name1, name2, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        string uName, vName;
        int weight;
        cin >> uName >> vName >> weight;
        addEdge(graph, vertexMap[uName], vertexMap[vName], weight);
    }

    string startVertexName;
    cout << "Enter the starting vertex: ";
    cin >> startVertexName;

    int startVertex = vertexMap[startVertexName];

    dijkstra(graph, V, startVertex, vertexNames);

    return 0;
}

