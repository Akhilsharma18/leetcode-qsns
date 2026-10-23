class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
           for (int num : nums) {
            int sum = 0;
          while (num) {
                sum += num % 10;
                num /= 10;
            }
        ans = min(ans, sum);
        }
     return ans;
    }
};