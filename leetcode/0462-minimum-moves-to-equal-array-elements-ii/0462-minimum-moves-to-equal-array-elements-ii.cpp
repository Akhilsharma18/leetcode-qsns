class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int sum=0;
        int i=0;
        int j=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(i<j){
            sum+=abs(nums[i]-nums[j]);
            i++;
            j--;
        }
        return sum;
    }
};