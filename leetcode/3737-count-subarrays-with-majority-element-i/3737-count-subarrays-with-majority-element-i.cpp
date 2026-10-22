class Solution {
public:
    int  countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {
            int targetCnt = 0;

            for(int j = i; j < n; j++) {
                if(nums[j] == target)
                    targetCnt++;

                int len = j - i + 1;

                if(targetCnt > len / 2)
                    ans++;
            }
        }

        return ans;
    }
};