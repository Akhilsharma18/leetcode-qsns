class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> mx(n, -1e9), mn(n, 1e9);
        int mxi = nums[0], mni = nums[n-1];
        for (int i = 0; i < n; i++) {
            if (nums[i] > mxi) mxi = nums[i] ;
            mx[i] = mxi;
        }
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] < mni) mni = nums[i] ;
            mn[i] = mni;
        }
        for (int i = 0; i < n; i++) {
            if ((mx[i] - mn[i]) <= k) return i ;
        }
        return -1;
    }
};