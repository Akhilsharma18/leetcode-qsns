class Solution {
public:
    int m, n;
    vector<vector<int>> vis;
    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj, char ch) {
        vis[i][j] = 1;
       int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
       for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];
           if (ni < 0 || nj < 0 || ni >= m || nj >= n)
                continue;
            if (grid[ni][nj] != ch)
                continue;
          if (ni == pi && nj == pj)
                continue;
            if (vis[ni][nj])
                return true;
          if (dfs(grid, ni, nj, i, j, ch))
                return true;
        }
      return false;
    }
   bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vis.assign(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
             if (!vis[i][j]) {
                if (dfs(grid, i, j, -1, -1, grid[i][j]))
                  return true;
                }
            }
        }
     return false;
   } 
};