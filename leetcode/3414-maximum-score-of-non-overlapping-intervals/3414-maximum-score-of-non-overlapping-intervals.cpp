class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& a) {
        int n = a.size();
     for(int i=0;i<n;i++) a[i].push_back(i);
  sort(a.begin(),a.end(),[](auto &x,auto &y){
            return x[1] < y[1];
        });
 vector<int> r(n),p(n);
      for(int i=0;i<n;i++) r[i]=a[i][1];
 for(int i=0;i<n;i++)
            p[i]=lower_bound(r.begin(),r.begin()+i,a[i][0])-r.begin();
    vector<vector<pair<long long,vector<int>>>> dp(
            n+1, vector<pair<long long,vector<int>>>(5)
        );
        for(int i=1;i<=n;i++){
            for(int k=1;k<=4;k++){
           auto x=dp[i-1][k];
                auto y=dp[p[i-1]][k-1];
   y.first+=a[i-1][2];
                y.second.push_back(a[i-1][3]);
                sort(y.second.begin(),y.second.end());
     if(y.first>x.first ||
                  (y.first==x.first && y.second<x.second))
                    dp[i][k]=y;
                else
                    dp[i][k]=x;
            }
        }
 return dp[n][4].second;
    }
};