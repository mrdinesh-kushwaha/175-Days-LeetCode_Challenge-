class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        // int minielement=nums[0];
        // int s=0;
        // int e=nums.size()-1;
        // while(s<=e){
        //     if(minielement+nums[e]==0){
        //         return nums[e];
        //     }
        //     e--;
        //     s++;
        // }
        // return -1;

        //***Using Two Pointer Approach************
        int s=0;
        int e=nums.size()-1;

        while(s<e){
            if(nums[s]+nums[e]==0)
            return nums[e];
            else if(nums[s]+nums[e]>0)
            e--;
            else
            s++;
        }
        return -1;
    }
};