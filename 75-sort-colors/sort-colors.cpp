class Solution {
public:
    void sortColors(vector<int>& nums) {
      // Solved using dutch's flag Algorithm
      int n = nums.size();
      int left=0;
      int mid = 0;
      int right = n-1;  

      while(mid<=right){
        //case-1
        if(nums[mid]==0){
            swap(nums[left],nums[mid]);
            left++;
            mid++;
        }
        //Case-2
        else if(nums[mid]==1){
            mid++;
        }
        //Case-3
        else{ // nums[mid]==2
            swap(nums[mid],nums[right]);
            right--;
        }
      }  
    }
};