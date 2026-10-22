class Solution {
public:
     string frequencySort(string s) {
        unordered_map<char, int> freqOfChar;
        for(char c : s) {
            freqOfChar[c] ++;
        }
        map<int, string> dupStr;
        for(auto v : freqOfChar) {
            char c = v.first;
            int n = v.second;
            dupStr[n] += string(n, c);
        }
       string res;
        for(auto rit = dupStr.rbegin(); rit != dupStr.rend(); ++rit) {
            res += rit->second;
        }
        return res;
    }
};