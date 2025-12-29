class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int ansLength=0;
        int idx=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[idx]){
                idx++;
                nums[idx]=nums[j];
            }
        }
        nums.resize(idx+1);
        return idx+1;
    }
};