class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //method-1 (nlongn)
        // for(int i=0;i<nums.size();i++){
        //     nums[i]= pow(nums[i],2);
        // }
        // sort(nums.begin(),nums.end());

        // return nums;

        //method-2 O(N)
        
     
        
        int left = 0;
        int size= nums.size();
        int right = size-1;
        int k = size-1;

        vector<int>ans(size); // extra space 

        while(left<=right){
          if(abs(nums[left]) > abs(nums[right])){
            ans[k] = nums[left]*nums[left];
            left++;
          }
          else{
            ans[k] = nums[right]*nums[right];
            right--;
          }
          k--;
        }
        return ans;
    }
};