class Solution {
public:
    int minSwaps(vector<int>& nums) {
        //solve using sliding windows 
        int n=nums.size();
        int ones=0;
        for(int i=0;i<n;i++) ones+=(nums[i]==1);

        int ans=n;
        int i=0,j=0;
        int one=0;
        int p=0;
        for(int i=n;i<2*n;i++){
            nums.push_back(nums[p++]);
        } // for circular
        while(j<2*n){// for given circular array
        one+=(nums[j]==1);
            if(j-i+1==ones)// means 1 windows full
            {
                ans=min(ans,ones-one);
                one-=(nums[i]==1);
                i++;
            }
            j++;
        }
        return (ans==n ? 0:ans);
    }
};