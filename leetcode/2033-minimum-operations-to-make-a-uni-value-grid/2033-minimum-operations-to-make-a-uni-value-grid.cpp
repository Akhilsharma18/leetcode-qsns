class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> nums;
        for (auto &row : grid) {
        for (int val : row) {
         nums.push_back(val);
            }
        }
      int rem = nums[0] % x;
        for (int val : nums) {
            if (val % x != rem) return -1;
        }
       sort(nums.begin(), nums.end());
        int median = nums[nums.size() / 2];
        int akhil = 0;
        for (int val : nums) {
            akhil += abs(val - median) / x;
        }
     return akhil;
    }
};