#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int r, int c,
             vector<vector<int>>& image,
             vector<vector<bool>>& vis,
             int newColor,
             int original) {

        int n = image.size();
        int m = image[0].size();

        vis[r][c] = true;
        image[r][c] = newColor;

        int delRow[] = {-1, 1, 0, 0};
        int delCol[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = r + delRow[k];
            int nc = c + delCol[k];

            if (nr >= 0 && nr < n &&
                nc >= 0 && nc < m &&
                !vis[nr][nc] &&
                image[nr][nc] == original) {

                dfs(nr, nc, image, vis, newColor, original);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {

        int n = image.size();
        int m = image[0].size();

        int original = image[sr][sc];

        if (original == newColor)
            return image;

        vector<vector<bool>> vis(n, vector<bool>(m, false));

        dfs(sr, sc, image, vis, newColor, original);

        return image;
    }
};
