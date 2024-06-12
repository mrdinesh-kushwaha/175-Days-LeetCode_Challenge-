class Solution {
public:
    void sortColors(vector<int>& nums) {

        int zeroCnt=0;
        int oneCnt=0;  // inplace sort means: take O(1) extra space:
        int twoCnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) zeroCnt++;
            else if(nums[i]==1) oneCnt++;
            else twoCnt++;
        }
        int s=0;
        while(zeroCnt--) nums[s++]=0;
        while(oneCnt--) nums[s++]=1;
        while(twoCnt--) nums[s++]=2;
        
    }
};