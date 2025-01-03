class Solution(object):
    def waysToSplitArray(self, nums):
        total_sum = sum(nums)
        n=len(nums)
        currSum=0
        count=0
        for i in range(0,n-1):
            currSum+=nums[i]
            if(currSum >= total_sum - currSum):
                count+=1
        return count
        