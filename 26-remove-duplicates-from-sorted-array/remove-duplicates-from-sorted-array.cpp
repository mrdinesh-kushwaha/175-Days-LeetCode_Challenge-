class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Using Two Pointer Approach

        int n = nums.size();
        int j=1; // Denote as unique element
        for(int i=1;i<n;i++){
            if(nums[j-1]!=nums[i]){
                nums[j]=nums[i];
                j++;
            }
        }
        return j;
    }
};