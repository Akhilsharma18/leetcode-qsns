class Solution {
public:
    bool isSubsequence(string s, string t) {
        int akhil = 0;
        int atul = 0;
        while(akhil<s.length() && atul<t.length()){
            if(s[akhil]== t[atul]){
                akhil++;
            }
            atul++;
        }
        return akhil == s.length();
    }
};