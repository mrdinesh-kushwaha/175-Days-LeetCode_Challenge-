class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int x=0;
        for(int i=0;i<=nums.size();i++){
            x=i;
            int idx=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            // int count=0;
            // for(int j=0;j<n;j++){
            //     if(nums[j]> x || nums[j]==x){
            //         count++;
            //     }
            // }
            int count=n-idx;
            if(x==count) return x;

        }
        return -1;
    }
};