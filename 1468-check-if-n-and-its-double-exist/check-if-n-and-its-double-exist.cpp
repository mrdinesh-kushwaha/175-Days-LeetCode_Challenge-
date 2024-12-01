class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<n-1;i++){
            int num=arr[i];
            for(int j=i+1;j<n;j++){
                if(num*2==arr[j] || num==2*arr[j]){ // no need to check i!=j because already start j=i+1
                    return true;
                }  
            }
        }
        return false;
    }
};