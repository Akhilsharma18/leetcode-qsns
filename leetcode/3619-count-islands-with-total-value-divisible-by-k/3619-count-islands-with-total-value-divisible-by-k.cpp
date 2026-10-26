class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int directions[5] = {1, 0, -1, 0, 1};
        int count = 0;
 for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;
  queue<pair<int, int>> q;
                q.emplace(i, j);
    long long total = grid[i][j];
                grid[i][j] = 0;
     while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();
   for (int d = 0; d < 4; ++d) {
                        int nr = r + directions[d];
                        int nc = c + directions[d + 1];
      if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                            grid[nr][nc] == 0) {
                            continue;
                        }
       total += grid[nr][nc];
                        grid[nr][nc] = 0;
                        q.emplace(nr, nc);
                    }
                }
  if (total % k == 0) ++count;
            }
        }

        return count;
    }
};