class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<bool> prime(mx+1,true);
        prime[0]=false;
        prime[1]=false;

//precompute all the non prime number between 2 and maximum number in input array
        for(int i=2;i<=sqrt(mx);i++){
            for(int j=i*i;j<=mx;j+=i)
            prime[j]=false;
        } 
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                for(int j=2;j<nums[i];j++){
                    if(prime[j] && (nums[i]-j) < nums[i+1]){
                    nums[i]-=j;
                    break;
                    }
                }
                if(nums[i]>=nums[i+1]) return false;
            }
        }
        return true;
    }
};