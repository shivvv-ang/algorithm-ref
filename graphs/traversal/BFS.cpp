#include<bits/stdc++.h>
using namespace std;

void bfs(int start,
    vector<vector<int>> &adj,
    vector<int> &visited) {

queue<int> q;
q.push(start);
visited[start] = 1;

while(!q.empty()) {
   int node = q.front();
   q.pop();

   for(auto neighbor : adj[node]) {
       if(!visited[neighbor]) {
           visited[neighbor] = 1;
           q.push(neighbor);
       }
   }
}
}


int main(){
    return 0;
}