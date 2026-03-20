#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<vector<pair<int, int>>> adj(vertices);

    for (int i = 0; i < edges; i++)
    {
        int node = vec[i][0];
        int adjnode = vec[i][1];
        int wt = vec[i][2];

        adj[node].push_back({adjnode, wt});
        adj[adjnode].push_back({node, wt});
    }

    vector<int> sd(vertices, INT_MAX);
    sd[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
    min_heap.push({0, source});

    while (!min_heap.empty())
    {
        auto front = min_heap.top();
        min_heap.pop();

        int dis = front.first;
        int node = front.second;

        if (dis > sd[node])
            continue;

        for (auto it : adj[node])
        {
            int adjnode = it.first;
            int wt = it.second;

            if (dis + wt < sd[adjnode])
            {
                sd[adjnode] = dis + wt;
                min_heap.push({sd[adjnode], adjnode});
            }
        }
    }

    return sd;
}