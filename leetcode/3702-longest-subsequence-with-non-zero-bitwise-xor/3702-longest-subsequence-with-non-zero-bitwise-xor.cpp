class Solution {
public:
int longestSubsequence(vector<int>& nums) {
int totalXOR = 0;
  bool allZero = true;
   for (int x : nums) {
         totalXOR ^= x;
       if (x != 0) allZero = false;
        }
  if (allZero) return 0;                 
  if (totalXOR == 0) return nums.size() - 1;   
  return nums.size();                    
    }
};
