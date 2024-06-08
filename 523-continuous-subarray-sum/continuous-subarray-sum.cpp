class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        /// brute  force approach using two loop
        // int n=nums.size();
        // for(int i=0;i<n-1;i++){
        //     int sum=nums[i];
        //     for(int j=i+1;j<n;j++){
        //         sum+=nums[j];
        //         if(sum % k == 0) return true;
        //     }
        // }
        // return false;

        int n=nums.size();
        unordered_map<int,int>mp; // reminder, index store:
        mp[0]= -1; // default case::
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(mp.find(rem)!=mp.end()){
                if(i-mp[rem] >= 2)// length >=2 hona chahiye
                return true;
            }
            else{
                mp[rem]=i;
            }
        }
        return false;
    }
};