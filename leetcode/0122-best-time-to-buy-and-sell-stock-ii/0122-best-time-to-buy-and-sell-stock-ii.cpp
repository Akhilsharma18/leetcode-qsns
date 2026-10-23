class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprof = 0;
        for(int i = 1;i<prices.size();i++){
            maxprof += max(prices[i]- prices[i-1],0);
        }
        return maxprof;
    }
};