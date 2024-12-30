class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // It's Take n(logN) time complexity need to optimise it:
        // SPace complexity = O(1)
        // int n = nums.size();
        // if(n==0) return 0;
        // sort(begin(nums),end(nums));
        // int cnt=1;
        // int result = INT_MIN;
        // for(int i=0;i<n-1;i++)
        // {
        //     if(nums[i]==nums[i+1]) continue; // used for avoid depliacte:
        //     if((nums[i]+1) == nums[i+1]) cnt++; 
        //     if((nums[i]+1) != nums[i+1]){
        //         result=max(result,cnt);
        //         cnt=1;
        //     }
        // }
        // result=max(cnt,result);  
        // return result;

        // *******Now Optimise Time complexity = O(N)
        // Space complexity = O(N)
        // Now solve using Hash set
        int n = nums.size();
        unordered_set<int>st;
        for(auto i: nums){
            st.insert(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(st.find(nums[i]-1)!=st.end()) continue;
            else{
                int cnt = 0;
                int num = nums[i];
                while(st.find(num)!=st.end()){
                    cnt++;
                    num++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};