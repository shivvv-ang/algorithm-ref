#include <bits/stdc++.h>
using namespace std;

void shortestDistance(vector<vector<int>> &mat)
{
    int n = mat.size();
    const int INF = 1e9;

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == -1)
                mat[i][j] = INF;

            if (i == j)
                mat[i][j] = 0;
        }
    }

    
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][k] != INF && mat[k][j] != INF)
                {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
    }

   
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == INF)
                mat[i][j] = -1;
        }
    }
}