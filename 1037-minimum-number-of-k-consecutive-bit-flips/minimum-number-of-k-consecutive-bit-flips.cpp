// class Solution {
// public:
//     int minKBitFlips(vector<int>& nums, int k) {
        
        // int n= nums.size();  
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         for(int j=i;j<k+i && (k+i)<=n;j++){ // This pass 101 test cases :
        //             if(nums[j]==0) nums[j]=1;
        //             else nums[j]=0;
        //         }
        //         count++;
        //     }
        // }
        // int countOne=0;
        //     for(int i=0;i<n;i++) {
        //         if(nums[i]==1) countOne++;
        //     }
        // if(countOne==n) return count;
        // else return -1;
//     }
//};

// now optimised:

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {

     int n= nums.size();

     vector<bool>isFliped(n,false);

     int currFlipCount=0;
     int ans=0;

     for(int i=0;i<n;i++){

        if(i>=k && isFliped[i-k]==true){
            currFlipCount--;
        }
        if(currFlipCount % 2==nums[i]){

            if(i+k > n) return -1;

            currFlipCount++;
            ans++;
            isFliped[i]=true;
        }
     }   
    return ans;
    }
};