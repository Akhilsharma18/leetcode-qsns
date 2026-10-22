class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>a;
     int maxi = 0;
    for(int i:nums){
            a[i]++;
        }
    for(int i:nums){
            if(a[i-1] || a[i+1]){
       maxi = max({maxi, a[i] + a[i-1], a[i] + a[i+1]});
            }
        }
        return maxi;
    }
};