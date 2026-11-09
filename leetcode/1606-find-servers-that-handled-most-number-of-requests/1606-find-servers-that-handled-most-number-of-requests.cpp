class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n=arrival.size();
        set<int> a;
        for(int i=0;i<k;i++) a.insert(i);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>> pq;
        vector<int> cnt(k,0),ans;
        for(int i=0;i<n;i++){
            while(!pq.empty() && pq.top().first<=arrival[i]){
                a.insert(pq.top().second);
                pq.pop();
            }
            if(a.empty()) continue;
            auto it=a.lower_bound(i%k);
            if(it==a.end()) it=a.begin();
            int x=*it;
            a.erase(it);
            cnt[x]++;
            pq.push({(long long)arrival[i]+load[i],x});
        }
        int mx=*max_element(cnt.begin(),cnt.end());
        for(int i=0;i<k;i++){
            if(cnt[i]==mx) ans.push_back(i);
        }
        return ans;
    }
};