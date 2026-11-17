class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> divisors(n + 1);

        for (int d = 1; d <= n; d++) {
            for (int v = 1; v < d; v++) {
                if (d % v == 0) {
                    divisors[d].push_back(v);
                }
            }
        }

        vector<vector<int>> cost(
            n + 1, vector<int>(n + 1, INF)
        );

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int L = j - i + 1;
                int best = INF;

                for (int d : divisors[L]) {
                    int changes = 0;

                    for (int start = i; start < i + d; start++) {
                        int l = start;
                        int r = start + ((j - start) / d) * d;

                        while (l < r) {
                            if (s[l] != s[r]) {
                                changes++;
                            }

                            l += d;
                            r -= d;
                        }
                    }

                    best = min(best, changes);
                }

                cost[i][j] = best;
            }
        }

        vector<vector<int>> dp(
            k + 1, vector<int>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int t = 1; t <= k; t++) {
            for (int i = t; i <= n; i++) {
                for (int j = t - 1; j < i; j++) {
                    if (dp[t - 1][j] < INF &&
                        cost[j][i - 1] < INF) {

                        dp[t][i] = min(
                            dp[t][i],
                            dp[t - 1][j] + cost[j][i - 1]
                        );
                    }
                }
            }
        }

        return dp[k][n];
    }
};