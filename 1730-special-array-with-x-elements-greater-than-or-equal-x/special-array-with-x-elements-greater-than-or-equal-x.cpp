class Solution {
public:
    int specialArray(vector<int>& nums) {
        
        int n=nums.size();
        int x=0;
        for(int i=0;i<=nums.size();i++){
            x=i;
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]> x || nums[j]==x){
                    count++;
                }
            }
            if(x==count) return x;

        }
        return -1;
    }
};