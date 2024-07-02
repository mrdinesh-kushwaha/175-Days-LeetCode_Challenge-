class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int>ans;
        int m=nums1.size();
        int n=nums2.size();

        // for(int i=0;i<m;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         if(nums1[i]==nums2[j]){
        //         ans.push_back(nums2[j]);
        //         nums2[j]=-1;
        //         nums1[i]=-2;
                
        //         }
             
        //     }
        // }
        // return ans;

        // M-2 Using Two pointer Approach:
        sort(begin(nums1),end(nums1));
        sort(begin(nums2),end(nums2));
        int i=0;
        int j=0;

        while(i<m && j<n){
        
            if(nums1[i]<nums2[j]) i++;
            else if(nums1[i]>nums2[j]) j++;
            else {
                ans.push_back(nums1[i]);
                i++,j++;
            }
        }
        return ans;
    }
};