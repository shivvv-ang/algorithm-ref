#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<vector<int>> &adj, vector<int> &visited) {
    visited[node] = 1;

    for(auto neighbor : adj[node]) {
        if(!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

int main() {
    int n = 6;

    vector<vector<int>> adj(n);

    // edges
    adj[0] = {1};
    adj[1] = {0,2};
    adj[2] = {1};

    adj[3] = {4};
    adj[4] = {3};

    // 5 isolated

    vector<int> visited(n, 0);
    int components = 0;

    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            dfs(i, adj, visited);
            components++;
        }
    }

    cout << "Connected Components: "
         << components << endl;
}
