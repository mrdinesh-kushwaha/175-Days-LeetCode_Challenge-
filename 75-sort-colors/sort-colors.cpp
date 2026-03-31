class Solution {
public:
    void sortColors(vector<int>& nums) {
    // Solved using dutch's flag Algorithm
    int left = 0;
    int mid = 0;
    int right = nums.size()-1;
    while(mid<=right){
        //only 3 case possible
        if(nums[mid]==0){
            swap(nums[left],nums[mid]);
            left++;
            mid++;
        }
        else if(nums[mid]==1) mid++;
        else { //nums[mid]==2
            swap(nums[mid],nums[right]);
            right--;
        }
    }
    }
};