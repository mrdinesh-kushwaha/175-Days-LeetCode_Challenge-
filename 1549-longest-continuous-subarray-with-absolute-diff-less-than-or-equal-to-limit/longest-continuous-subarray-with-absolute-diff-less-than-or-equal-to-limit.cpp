// class Solution {
// public:
//     int longestSubarray(vector<int>& nums, int limit) {

    //  int n = nums.size();
    // int ans = 1;

    // for (int i = 0; i < n; i++) {
    //     int temp = 0;
    //     int minVal = nums[i];
    //     int maxVal = nums[i];
        
    //     for (int j = i; j < n; j++) {      // Give TLE::::::::::
    //         minVal = min(minVal, nums[j]);
    //         maxVal = max(maxVal, nums[j]);
            
    //         if (maxVal - minVal <= limit) {
    //             temp = j - i + 1;
    //         } else {
    //             break;
    //         }
    //     }       
    //     ans = max(ans, temp);
    // }
    // return ans;



    // Now optimise this code : Using sliding Windows
    class Solution {
    public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int>s1;
          int i,j=0,n=nums.size(),ans=1;
        
          for(i=0;i<n;i++)
          {
            s1.insert(nums[i]);
        
             while(abs(*s1.rbegin()-*s1.begin())>limit)
             {
                s1.erase(s1.find(nums[j]));
                
                j++;
             }
             ans = max(ans, i - j + 1);
          }
          return ans;
    }
};
