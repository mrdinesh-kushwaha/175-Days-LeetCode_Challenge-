class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        // sort(begin(nums),end(nums));
        // int n=nums.size();
        // int ans=0;
        // for(int i=0;i<n-1;i++){
        //     int num=nums[i];
        //     if(nums[i]==nums[i+1]){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]==nums[j]){ // Brute Force approach give TLE::
        //             nums[j]+=1;
        //             ans++;
        //         }
        //     }
        //     }
        // }
        // return ans;

        int n=nums.size();
        sort(begin(nums),end(nums));

        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                ans+=(nums[i-1]-nums[i])+1 ;
                nums[i]=nums[i-1]+1;
            }
        }
        return ans;
    }
};