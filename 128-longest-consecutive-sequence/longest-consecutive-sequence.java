class Solution {

    public int bruteForce(int[] nums){
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

    public int optimiseSolution(int[] nums){
        
    if (nums.length == 0) return 0;
    Set<Integer> set = new HashSet<>();
    for (int num : nums) set.add(num);

    int longest = 0;

    for (int num : set) {

        // start of sequence = previous number does NOT exist
        if (!set.contains(num - 1)) {

            int current = num;
            int count = 1;

            while (set.contains(current + 1)) {
                current++;
                count++;
            }

            longest = Math.max(longest, count);
        }
    }

    return longest;
    }
    public int longestConsecutive(int[] nums) {

        //return bruteForce(nums);

        return optimiseSolution(nums);
    }
}