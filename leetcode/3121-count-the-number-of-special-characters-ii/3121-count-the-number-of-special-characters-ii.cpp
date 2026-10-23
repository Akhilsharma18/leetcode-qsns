class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int>mpl(26 , -1);
        vector<int>mpu(26 , -1);
        int n = word.size(); 
        for(int i = 0 ; i < n ; i++){
            char a = word[i]; 
            if(islower(a)){
                mpl[a-'a'] = i ; 
            }else{
                if(mpu[a-'A'] != -1){
                    continue ;
                }else{
                    mpu[a-'A'] = i; 
                }
            }
        }
        int ans = 0 ; 
        for(int i = 0 ; i < 26 ; i++){
            if(mpu[i] != -1 && mpl[i] != -1){
                if(mpl[i] < mpu[i]) ans++; 
                else continue ; 
            }
        }
        return ans;
    }
};