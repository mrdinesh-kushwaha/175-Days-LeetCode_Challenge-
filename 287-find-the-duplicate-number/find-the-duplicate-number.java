class Solution {
    public int findDuplicate(int[] nums) {
        //Using cycle detection technique
        int slow = nums[0]; 
        int fast = nums[0];

        while(true){
            slow = nums[slow]; // 1-step denoting index
            fast = nums[nums[fast]]; //2- steps
            
            if(fast == slow) // means cycle detected
            {
                slow = nums[0];
                while(slow!=fast){
                    slow = nums[slow]; // 1- step
                    fast = nums[fast]; // 1- step
                }
                return slow;
            }
        }
    }
}