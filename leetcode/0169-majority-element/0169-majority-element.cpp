class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int el = 0;

        for(int i = 0;i<n;i++){
            if(count == 0){
                el = arr[i];
                count = 1;

            }else if 
               ( arr[i] == el){
                count++;
            }else{
                count--;
            }
        }
            count = 0;
            for(int i =0;i<n;i++){
                if(arr[i]==el){
                count++;
                }
            }
        if(count>n/2)
        return el;
        return-1;
    }
};