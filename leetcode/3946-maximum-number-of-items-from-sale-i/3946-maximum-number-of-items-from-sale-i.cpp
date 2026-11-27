class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> gifts(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j &&
                    items[i][0] != 0 &&
                    items[j][0] % items[i][0] == 0) {
                    ++gifts[i];
                }
            }
        }
        vector<int> prev(budget + 1, 0);
        vector<int> cur(budget + 1, 0);
  for (int j = 0; j < n; ++j) {
            int price = items[j][1];
            int gift = gifts[j];
            cur = prev;
            for (int b = price; b <= budget; ++b) {
                cur[b] = max(
                    cur[b],
                    prev[b - price] + 1 + gift
                );
                cur[b] = max(
                    cur[b],
                    cur[b - price] + 1
                );
            }
            prev.swap(cur);
        }
        return prev[budget];
    }
};