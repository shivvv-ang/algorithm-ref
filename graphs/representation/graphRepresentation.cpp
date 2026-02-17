#include<bits/stdc++.h>;
using namespace std;

int main(){
    int n , m; // n represent no of nodes and m represent no of edges
    cin>>n>>m;

    //MATRIX

    // graph here (o(n) time to store  it and takes o(n^2) space complexity)

    int adjMatrix[n+1][n+1];

    for(int i=0;i<m;i++){
        int u , v;
        cin>>u>>v;

        //if there's weight given as welll

        // int u , v ,w;
        // cin>>u>>v>>w;
        // adjMatrix[u][v] =  w;

        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    }


    //LIST 

    //arrays of vectors space complexity o(2 * e) for undirected graph and for directed graph o(e)

    vector<int>adj[n+1]; 

    for(int i=0;i<n;i++){
        int u , v;
        cin>>u>>v;

        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);

        //u->v (for directed graph)
       // adj[u].push_back(v);
    }

    //when weights are given 
    vector<vector<pair<int,int>>>adjlist(n);

    //directed graph

      // edges: u -> v with weight w
      adjlist[0].push_back({1, 4});
      adjlist[1].push_back({2, 3});
      adjlist[2].push_back({3, 2});
      adjlist[3].push_back({3, 5});
      adjlist[4].push_back({4, 1});


    //undirected graph 

    // function to add undirected edge
    auto addEdge = [&](int u, int v, int w) {
        adjlist[u].push_back({v, w});
        adjlist[v].push_back({u, w});
    };

    addEdge(0, 1, 4);
    addEdge(0, 2, 3);
    addEdge(1, 3, 2);
    addEdge(2, 3, 5);
    addEdge(3, 4, 1);

    return 0;
}