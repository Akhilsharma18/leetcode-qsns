class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
  vector<int> count(maxVal - minVal + 1, 0);
 for (int num : nums)
            count[num - minVal]++;
 int index = 0;
        for (int i = 0; i < count.size(); i++) {
            while (count[i]--) {
                nums[index++] = i + minVal;
            }
        }
  return nums;
    }
};