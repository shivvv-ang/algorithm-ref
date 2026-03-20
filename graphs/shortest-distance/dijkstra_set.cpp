#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    vector<vector<pair<int,int>>> adj(vertices);  

    for(int i = 0; i <edges; i++){
        int node    = vec[i][0];
        int adjnode = vec[i][1];
        int wt      = vec[i][2];

        adj[node].push_back({adjnode, wt});
        adj[adjnode].push_back({node, wt});
    }

    vector<int> sd(vertices, INT_MAX);
    sd[source] = 0;

    set<pair<int,int>>st;
    st.insert({0, source});  

    while(!st.empty()){
        auto front = *(st.begin());
        st.erase(front);

        int dis  = front.first;   
        int node = front.second;

        if(dis > sd[node]) continue;  

        for(auto it : adj[node]){
            int adjnode = it.first;
            int wt = it.second;

            if(dis + wt < sd[adjnode]){
               if(sd[adjnode] != INT_MAX){
                   st.erase({sd[adjnode], adjnode});
               }

                sd[adjnode] = dis + wt;
                st.insert({sd[adjnode], adjnode});
            }
        }
    }

    return sd;
}