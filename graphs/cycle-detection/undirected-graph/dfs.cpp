#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        bool dfs(int x, int y, int parentx, int parenty, vector<vector<char>>& grid,
                 vector<vector<bool>>& vis) {
    
            vis[x][y] = true;
    
            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, 1, 0, -1};
    
            for (int i = 0; i < 4; i++) {
                int nr = x + delrow[i];
                int nc = y + delcol[i];
    
                if (nr < 0 || nr >= grid.size() || nc < 0 || nc >= grid[0].size())
                    continue;
    
                if (!vis[nr][nc] && grid[nr][nc] == grid[x][y]) {
                    if (dfs(nr, nc, x, y, grid, vis))
                        return true;
                } else if (vis[nr][nc] && grid[nr][nc] == grid[x][y] &&
                           !(nr == parentx && nc == parenty)) {
                    return true;
                }
            }
            return false;
        }
    
        bool containsCycle(vector<vector<char>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
    
            vector<vector<bool>> vis(n, vector<bool>(m, false));
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!vis[i][j]) {
                        if (dfs(i, j, -1, -1, grid, vis))
                            return true;
                    }
                }
            }
            return false;
        }
    };