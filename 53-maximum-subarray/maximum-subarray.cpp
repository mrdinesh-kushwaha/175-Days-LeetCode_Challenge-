class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     int sum=INT_MIN;
    //     for(int i=0;i<n;i++){
    //         int temp=0;
    //         for(int j=i;j<n;j++){
    //             temp+=nums[j];
    //             sum=max(sum,temp);
    //         }
    //     }
    // return sum;

    //*** Kanden's Algorithm

    int result=INT_MIN;
    int sum=0;

    for(int i=0;i<nums.size();i++){
        //Step-1
        sum+=nums[i];  
        // Step-2
        if(sum > result){
            result=sum;
        }
        //Step-3
        if(sum < 0){
            sum=0;
        }
    }           
    return result;
    }
};