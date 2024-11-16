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

// int primMST(vector<vector<pii>>& graph, int V, int startVertex) {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     vector<int> key(V, INT_MAX);
//     vector<int> parent(V, -1);
//     vector<bool> inMST(V, false);

//     key[startVertex] = 0;
//     pq.push(make_pair(0, startVertex));

//     while (!pq.empty()) {
//         int u = pq.top().second;
//         pq.pop();

//         inMST[u] = true;

//         for (auto& i : graph[u]) {
//             int v = i.second;
//             int weight = i.first;

//             if (!inMST[v] && key[v] > weight) {
//                 key[v] = weight;
//                 pq.push(make_pair(key[v], v));
//                 parent[v] = u;
//             }
//         }
//     }

//     int totalCost = 0;
//     cout << "Edges in the MST:" << endl;
//     for (int i = 0; i < V; ++i) {
//         if (parent[i] != -1) {
//             cout << parent[i] << " - " << i << " (weight: " << key[i] << ")" << endl;
//             totalCost += key[i];
//         }
//     }

//     return totalCost;
// }

// int main() {
//     int V, E;
//     cout << "Enter the number of vertices: ";
//     cin >> V;
//     cout << "Enter the number of edges: ";
//     cin >> E;

//     vector<vector<pii>> graph(v);

//     cout << "Enter edges (u, v, weight):" << endl;
//     for (int i = 0; i < E; ++i) {
//         int u, v, weight;
//         cin >> u >> v >> weight;
//         addEdge(graph, u, v, weight);
//     }

//     int startVertex;
//     cout << "Enter the starting vertex (0 to " << V - 1 << "): ";
//     cin >> startVertex;

//     int mstCost = primMST(graph, V, startVertex);
//     cout << "Total cost of MST: " << mstCost << endl;

//     return 0;
// }


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>
#include <string>
using namespace std;

typedef pair<int, int> pii;

void addEdge(vector<vector<pii>>& graph, int u, int v, int weight) {
    graph[u].push_back(make_pair(weight, v));
    graph[v].push_back(make_pair(weight, u));
}

int primMST(vector<vector<pii>>& graph, int V, int startVertex) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    key[startVertex] = 0;
    pq.push(make_pair(0, startVertex));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        inMST[u] = true;

        for (auto& i : graph[u]) {
            int v = i.second;
            int weight = i.first;

            if (!inMST[v] && key[v] > weight) {
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }

    int totalCost = 0;
    cout << "Edges in the MST:" << endl;
    for (int i = 0; i < V; ++i) {
        if (parent[i] != -1) {
            cout << (char)('A' + parent[i]) << " - " << (char)('A' + i) << " (weight: " << key[i] << ")" << endl;
            totalCost += key[i];
        }
    }

    return totalCost;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    unordered_map<char, int> vertexMap;
    vector<vector<pii>> graph(V);

    cout << "Enter vertices (e.g., A, B, C, ...):" << endl;
    for (int i = 0; i < V; ++i) {
        char vertex;
        cin >> vertex;
        vertexMap[vertex] = i;
    }

    cout << "Enter edges (u, v, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        char u, v;
        int weight;
        cin >> u >> v >> weight;
        addEdge(graph, vertexMap[u], vertexMap[v], weight);
    }

    char startVertexChar;
    cout << "Enter the starting vertex: ";
    cin >> startVertexChar;

    int startVertex = vertexMap[startVertexChar];

    int mstCost = primMST(graph, V, startVertex);
    cout << "Total cost of MST: " << mstCost << endl;

    return 0;
}
