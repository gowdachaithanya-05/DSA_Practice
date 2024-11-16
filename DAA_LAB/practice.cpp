#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;
typedef pair<int, int> pii;
void ae(vector<vector<pii>>& graph, int v, int u, int w){
    graph[u].push_back(make_pair(w,v));
    graph[v].push_back(make_pair(w,u));

}

int prim(vector<vector<pii>>& graph, int v, int sv){
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> key(v, INT_MAX);
    vector<int> parent(v, -1);
    vector<bool> mst(v, false);
    key[sv] = 0;
    pq.push(make_pair(0, sv));
   
    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
       
        mst[u]= true;
       
        for(auto& i : graph[u]){
            int v = i.second;
            int w = i.first;
            if(!mst[v] && key[v]>w){
                key[v]=w;
                pq.push(make_pair(key[v],v));
                parent[v]=u;

            }

        }
    }
    int totalCost = 0;
    cout << "Edges in the MST: "<< endl;
    for(int i=0; i<v; i++){
        if(parent[i] != -1){
            cout << char ('A' + parent[i]) << "-" << char ('A' + i) << " => weight : " << key[i] <<endl;
            totalCost += key[i];
        }
    }
    return totalCost;

}

int main(){
    int nv, ne, w;
    // char u,v;

    cout << "enter no. of vertices and edges : ";
    cin >> nv ;
    cin >> ne ;

    // unordered_map<char, int> vertexMap;
    unordered_map<char, int> vertexMap;

    vector<vector<pii>> graph(nv);
    cout << "Enter the vertices";
    for(int i=0; i<nv ; i++){
        char v;
        cin >> v;
        vertexMap[v]=i;
    }
    
    cout << "Enter edeges :" ;
    for(int i=0; i < ne; i++){
        char u; 
        char v;
        cin >> u >> v >> w ;
        ae(graph, vertexMap[u], vertexMap[v], w);

    }
    char svchar;
    cout << "Enter source vertex : ";
    cin >> svchar ;

    int sv = vertexMap[svchar] ;
    
    int cost = prim(graph, nv, vertexMap[sv]);
    cout<< "total cost of MST : " << cost ;

    return 0;
}



// #include <iostream>
// #include <vector>
// #include <climits>
// #include <queue>
// using namespace std;

// typedef pair<int, int> pii;

// void ae(vector<vector<pii>>& graph, int u, int v, int w) {
//     graph[u].push_back(make_pair(w, v));
//     graph[v].push_back(make_pair(w, u));
// }

// int prim(vector<vector<pii>>& graph, int nv, int sv) {
//     priority_queue<pii, vector<pii>, greater<pii>> pq;
//     vector<int> key(nv, INT_MAX);
//     vector<int> parent(nv, -1);
//     vector<bool> inMST(nv, false);
    
//     key[sv] = 0;
//     pq.push(make_pair(0, sv));

//     while (!pq.empty()) {
//         int u = pq.top().second;
//         pq.pop();
        
//         if (inMST[u]) continue; // Skip if already included in MST
//         inMST[u] = true;

//         for (auto& i : graph[u]) {
//             int v = i.second;
//             int w = i.first;
//             if (!inMST[v] && key[v] > w) {
//                 key[v] = w;
//                 pq.push(make_pair(key[v], v));
//                 parent[v] = u;
//             }
//         }
//     }

//     int totalCost = 0;
//     cout << "Edges in the MST:" << endl;
//     for (int i = 0; i < nv; ++i) {
//         if (parent[i] != -1) {
//             cout << parent[i] << " - " << i << " (weight: " << key[i] << ")" << endl;
//             totalCost += key[i];
//         }
//     }
//     return totalCost;
// }

// int main() {
//     int nv, ne;
//     cout << "Enter number of vertices and edges: ";
//     cin >> nv >> ne;

//     vector<vector<pii>> graph(nv);

//     cout << "Enter edges (u, v, weight):" << endl;
//     for (int i = 0; i < ne; ++i) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         ae(graph, u, v, w);
//     }

//     int sv;
//     cout << "Enter starting vertex: ";
//     cin >> sv;

//     int cost = prim(graph, nv, sv);
//     cout << "Total cost of MST: " << cost << endl;

//     return 0;
// }
