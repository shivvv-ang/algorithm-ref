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

        return parent[node] = findUpr(parent[node]); // path compression while finding the parent of a give node
    }

    // we attach smaller node to larger
    // 1) keeping the height of tree/graph lesser
    // 2) finding parent get easier with this route

    void unionbyrank(int u, int v)
    {
        int ulp_u = findUpr(u);
        int ulp_v = findUpr(v);

        if (ulp_u == ulp_v)
            return; // both belong to same component  and share the same parent

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

    // in union by size the size of an element keeps track of how mamy components are connected TO that element
    // time complexity for both union by rank and union by size is O(4 alpha ) which is near about constant
};

int main()
{

    Disjoinset ds(7);

    ds.unionbyrank(1, 2);
    ds.unionbyrank(2, 3);
    ds.unionbyrank(4, 5);
    ds.unionbyrank(6, 7);
    ds.unionbyrank(5, 6);

    if (ds.findUpr(3) == ds.findUpr(7))
    {
        cout << "same\n";
    }
    else
        cout << "not same \n";

    ds.unionbyrank(3, 7);

    return 0;
}