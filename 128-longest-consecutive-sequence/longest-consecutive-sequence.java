class Solution {
    public int longestConsecutive(int[] nums) {

        if(nums.length==0) return 0;
        int ans = 0;
        int temp = 1;
        Arrays.sort(nums);

        for(int i=0;i<nums.length-1;i++){
            if(nums[i]+1 == nums[i+1]){
                temp++;
            }
            else if(nums[i]==nums[i+1]) continue;
            else{
                ans = Math.max(ans,temp);
                temp=1;
            }
        }
        ans = Math.max(ans,temp);
        return ans;
    }
}