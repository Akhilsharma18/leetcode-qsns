class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
 if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
   unordered_map<int, int> freq;
    for (int x : nums)
            freq[x]++;
    int ans = -1;
   if (k == 1) {
            for (auto &p : freq) {
                if (p.second == 1)
                    ans = max(ans, p.first);
            }
            return ans;
        }
      if (freq[nums[0]] == 1)
            ans = max(ans, nums[0]);
     if (freq[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);
 return ans;
    }
};