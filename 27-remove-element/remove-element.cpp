class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int idx=0;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=val){
                nums[idx]=nums[i];
                idx++;
            }
        }
        nums.resize(idx);
        return idx;
    }
};