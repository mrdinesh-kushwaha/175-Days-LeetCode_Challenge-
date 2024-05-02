class Solution {
public:
    int findMaxK(vector<int>& nums) {

        // sort(nums.begin(),nums.end());
        // //***Using Two Pointer Approach************
        // int s=0;
        // int e=nums.size()-1;

        // while(s<e){
        //     if(nums[s]+nums[e]==0)     T.C=O(nlogn)
        //     return nums[e];
        //     else if(nums[s]+nums[e]>0)
        //     e--;
        //     else
        //     s++;
        // }
        // return -1;

        //M-2 Using Hash_map:::

        unordered_set<int>st(nums.begin(),nums.end());//insert all element in set
        int ans=-1;
        for(auto &num:nums){
            if(st.find(-num)!=st.end())
            ans=max(ans,num);
        }
        return ans;
    }
};