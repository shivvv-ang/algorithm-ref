#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{

    vis[node] = 1;

    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<vector<int>> &adjT)
{
    vis[node] = 1;

    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs2(it, vis, adjT);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    vector<vector<int>> adj(v);

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    stack<int> st;
    vector<int> vis(v);

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    vector<vector<int>> adjT(v);

    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    int scc = 0;

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (!vis[top])
        {
            scc++;
            dfs2(top, vis, adjT);
        }
    }

    return scc;
}