class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        vector<int> suffixSum(n, 0);
       suffixSum[n - 1] = piles[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffixSum[i] = suffixSum[i + 1] + piles[i];
        }
     for (int i = n - 1; i >= 0; i--) {
     for (int m = 1; m <= n; m++) {
         if (i + 2 * m >= n) {
          dp[i][m] = suffixSum[i];
                } else {
          int minOpponentScore = INT_MAX;
        for (int x = 1; x <= 2 * m; x++) {
             minOpponentScore = min(minOpponentScore, dp[i + x][max(m, x)]);
                    }
                    dp[i][m] = suffixSum[i] - minOpponentScore;
                }
            }
        }
 return dp[0][1];
    }
};