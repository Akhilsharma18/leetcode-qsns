class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
       for (int i = 0; i < n; i++) {
            int mx = *max_element(nums.begin(), nums.begin() + i + 1);
            int mn = *min_element(nums.begin() + i, nums.end());
         if (mx - mn <= k)
                return i;
        }

        return -1;
    }
};