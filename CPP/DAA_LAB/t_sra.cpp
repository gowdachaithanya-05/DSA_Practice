#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform topological sort using source removal algorithm
vector<int> topologicalSort(int n, vector<vector<int>>& adjList) {
    vector<int> inDegree(n, 0);

    // Calculate in-degree of each node
    for (int i = 0; i < n; i++) {
        for (int j : adjList[i]) {
            inDegree[j]++;
        }
    }

    // Queue to store nodes with in-degree 0
    queue<int> q;

    // Enqueue nodes with in-degree 0
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;

    // Process nodes in the queue
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adjList[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    return topoOrder;
}

int main() {
    int n, m;
    cout << "Enter the number of vertices: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;

    vector<vector<int>> adjList(n);

    cout << "Enter the edges (u v) where u -> v:" << endl;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
    }

    vector<int> topoOrder = topologicalSort(n, adjList);
    cout << "Topological Sort Order: ";
    for (int i : topoOrder) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
