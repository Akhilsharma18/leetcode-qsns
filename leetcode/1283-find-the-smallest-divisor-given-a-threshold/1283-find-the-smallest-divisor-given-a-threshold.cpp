class Solution {
public:
    int findSum(vector<int>& nums, int divisor) {
        int sum = 0;
      for (int x : nums) {
            sum += (x + divisor - 1) / divisor;   
        }
    return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
      while (left <= right) {
            int mid = left + (right - left) / 2;
      if (findSum(nums, mid) <= threshold) {
                right = mid - 1; 
            }
          else {
                left = mid + 1; 
            }
        }
return left;
    }
};