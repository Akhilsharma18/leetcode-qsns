class Solution {
public:
    int largestAltitude(vector<int>& gain) {
 int altitude = 0;
  int maxAlt = 0;
    for (int x : gain) {
         altitude += x;
     maxAlt = max(maxAlt, altitude);
        }
     return maxAlt;
    }
};