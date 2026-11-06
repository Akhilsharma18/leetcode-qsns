class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
 vector<pair<int, int>> ordered_queries;
        for (int i = 0; i < queries.size(); i++) {
            ordered_queries.push_back({queries[i], i});
        }
        sort(ordered_queries.begin(), ordered_queries.end());
 vector<int> frequency(n + 1, 0);
        vector<int> answer(queries.size());
        int active = 0, left = 0, right = 0;
 for (auto [q, original_index] : ordered_queries) {
            int lower = q - x;
 while (right < logs.size() && logs[right][1] <= q) {
                int server = logs[right][0];
                if (frequency[server] == 0) {
                    active++;
                }
                frequency[server]++;
                right++;
            }
   while (left < right && logs[left][1] < lower) {
                int server = logs[left][0];
                frequency[server]--;
                if (frequency[server] == 0) {
                    active--;
                }
                left++;
            }
answer[original_index] = n - active;
        }
   return answer;
    }
};