class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
      vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;
       vector<long long> exact(mx + 1, 0);
      for (int g = mx; g >= 1; g--) {
            long long cnt = 0;
       for (int j = g; j <= mx; j += g)
                cnt += freq[j];
         exact[g] = cnt * (cnt - 1) / 2;
          for (int j = 2 * g; j <= mx; j += g)
                exact[g] -= exact[j];
        }
      vector<long long> pref(mx + 1, 0);
        for (int i = 1; i <= mx; i++)
            pref[i] = pref[i - 1] + exact[i];
      vector<int> ans;
      for (long long q : queries) {
            int g = lower_bound(pref.begin(), pref.end(), q + 1) - pref.begin();
            ans.push_back(g);
        }
     return ans;
    }
};