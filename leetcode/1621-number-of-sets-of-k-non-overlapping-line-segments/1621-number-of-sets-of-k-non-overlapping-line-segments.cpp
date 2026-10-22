class Solution {
public:
    using ll = long long;
    const ll MOD = 1e9 + 7;
   vector<vector<ll>> dp;
     ll combination(int n, int r) {
        if (r == 0 || r == n)
            return 1;
      if (dp[n][r] != -1)
            return dp[n][r];
      ll a = combination(n - 1, r - 1);
        ll b = combination(n - 1, r);
     return dp[n][r] = (a + b) % MOD;
    }
   int numberOfSets(int n, int k) {
        int total = n + k - 1;
        int choose = 2 * k ;
     dp.assign(total + 1, vector<ll>(choose + 1, -1));
    return combination(total, choose);
    }
};