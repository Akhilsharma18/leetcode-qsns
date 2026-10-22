class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
   unordered_map<int, int> rankMap;
      vector<int> sortedArray = arr;
        sort(sortedArray.begin(), sortedArray.end());
        int rank = 1;
        for (int x : sortedArray) {
            if (!rankMap.count(x)) {
        rankMap[x] = rank;
                rank++;
            }
        }
        vector<int> result;
        for (int x : arr) {
    result.push_back(rankMap[x]);
        }
        return result;
    }
};