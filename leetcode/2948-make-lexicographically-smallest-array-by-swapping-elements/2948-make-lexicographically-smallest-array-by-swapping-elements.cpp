class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int>sorted = nums;
        sort(sorted.begin(),sorted.end());
   unordered_map<int,int>group;
        unordered_map<int,int>j_idx;
        vector<int>ans;
 int grp = 0;
        group[sorted[0]] = grp;
        j_idx[grp] = 0;
  for(int i=1;i<n;i++){
            if(sorted[i]-sorted[i-1] > limit){
                grp++;
                j_idx[grp] = i;
            }
            group[sorted[i]] = grp;
        }
   int i = 0;
        while(i < n){
            int currgrp = group[nums[i]];
            int j = j_idx[currgrp];

            ans.push_back(sorted[j]);
            j_idx[currgrp]++;
            i++;
        }
 return ans;
    }
};