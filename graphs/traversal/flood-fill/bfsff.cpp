#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>> &image,int sr, int sc,int newColor)
{

    int n = image.size();
    int m = image[0].size();

    int original = image[sr][sc];
    if (original == newColor)
        return image;

    queue<pair<int, int>> q;
    q.push({sr, sc});

    image[sr][sc] = newColor;

    int delRow[] = {-1, 1, 0, 0};
    int delCol[] = {0, 0, -1, 1};

    while (!q.empty())
    {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int nr = r + delRow[k];
            int nc = c + delCol[k];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                image[nr][nc] == original)
            {

                image[nr][nc] = newColor;
                q.push({nr, nc});
            }
        }
    }

    return image;
}
