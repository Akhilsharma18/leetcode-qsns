class Solution {
public:
    int findGCD(vector<int>& nums) {
      int maxi = nums[0];
      int mini = nums[0];
      for( int x : nums){
        maxi = max(maxi , x);
        mini = min(mini, x);
      }
      return gcd(maxi , mini);
    }
};