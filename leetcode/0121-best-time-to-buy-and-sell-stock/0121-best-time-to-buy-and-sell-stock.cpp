class Solution {
public:
    int maxProfit(vector<int>& prices) {
   int mini = prices[0];
   int maxprofit = 0;
   for(int i = 0;i<prices.size();i++){
        maxprofit = max(maxprofit , prices[i]-mini);
        mini = min(mini , prices[i]);
   }
   return maxprofit;
    }
};