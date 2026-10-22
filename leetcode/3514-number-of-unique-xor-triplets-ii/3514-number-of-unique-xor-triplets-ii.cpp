class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
      if(nums.size() == 1) return 1;
 const int MAX = 2048;
     vector<bool> one(MAX, false);
        vector<bool> two(MAX, false);
        vector<bool> three(MAX, false);
     for (int val : nums) {
            for (int x = 0; x < MAX; x++) {
                if (one[x])
                    two[x ^ val] = true;
            }
            one[val] = true;
        }
     for (int val : nums) {
            for (int x = 0; x < MAX; x++) {
                if (two[x])
                    three[x ^ val] = true;
            }
        }
      int ans = 0;
        for ( bool exists : three)
            ans += exists;
        return ans;
    }
};