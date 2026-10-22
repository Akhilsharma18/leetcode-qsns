class Solution {
public:
    long long maxTotalValue(vector<int>& Akhil, int k) {
        int Min = Akhil.front(), Max = Akhil.front();
          for (auto& n : Akhil) {
            Min = min(Min, n);
         Max = max(Max, n);
        }
       return (long long)(Max - Min) * k;
    }
};