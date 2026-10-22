class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dist(row, vector<int>(col, -2));
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        if (grid[0][0] == 1) {
            dist[0][0] = health - 1;
            if (dist[0][0] <= 0) 
                return false;
        } else {
            dist[0][0] = health;
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();
            if (i == row - 1 && j == col - 1)
                return true;
            vector<pair<int, int>> dirs = {
                {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}
            };
            for (auto [x, y] : dirs) {
                if (x >= 0 && x < row && y >= 0 && y < col && dist[x][y] == -2) {
                    int cost = grid[x][y] == 1 ? 1 : 0;
                    int newHealth = dist[i][j] - cost;
                    if (newHealth > 0 && newHealth > dist[x][y]) {
                        dist[x][y] = newHealth;
                        if (cost == 0)
                            q.push_front({x, y});
                        else
                            q.push_back({x, y});
                    }
                }
            }
        }
        return false;
    }
};