

class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        int open = 0;  
        for(char c : s) {
            if(c == '(') {
                if(open > 0) res += c; 
                open++;  
            } else {
                open--; 
                if(open > 0) res += c;
            }
        }

        return res;
    }
};
