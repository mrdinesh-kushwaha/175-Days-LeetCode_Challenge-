class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        // int sum=0;
        // int curr=0;
        // int n=arr.size();
        // int k=3; // given three consecutive 
        // for(int i=0;i<k;i++){
        //     curr+=arr[i];
        // }
        // sum=curr;
        // if(sum % 2!=0) return true;
        // for(int i=k;i<n;i++){
        //     sum-=arr[i-k];
        //     sum+=arr[i];
        //     if(sum % 2 !=0) return true;
        // }
        // return false;

        int n= arr.size();
        int count=0;
        int k=3;
        for(int i=0;i<n;i++){
            if(arr[i] % 2!=0){
                count++;
            }
            else{
                count=0;
            }
            if(count==k) return true;
        }
        return false;
    }
};