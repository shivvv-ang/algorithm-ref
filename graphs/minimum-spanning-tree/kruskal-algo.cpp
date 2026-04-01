#include <bits/stdc++.h>
using namespace std;

class Disjoinset
{
    vector<int> rank, parent, size;

public:
    Disjoinset(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpr(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findUpr(parent[node]);
    }

    void unionbyrank(int u, int v)
    {
        int ulp_u = findUpr(u);
        int ulp_v = findUpr(v);

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionbysize(int u, int v)
    {
        int ulp_u = findUpr(u);
        int ulp_v = findUpr(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    bool static comp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }

    int spanningTree(int V, vector<vector<int>> &edges)
    {

        int totalweight = 0;

        sort(edges.begin(), edges.end(), comp);

        Disjoinset ds(V);

        for (auto e : edges)
        {

            int u = e[0];

            int v = e[1];

            int wt = e[2];

            if (ds.findUpr(u) != ds.findUpr(v))
            {
                totalweight += wt;
            }

            ds.unionbyrank(u, v);
        }

        return totalweight;
    }
};