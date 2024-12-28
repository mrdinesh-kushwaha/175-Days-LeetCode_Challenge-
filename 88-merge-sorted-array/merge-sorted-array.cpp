class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //✅ This Solution Takes T.C=O(m+n) And S.C = O(m+n)extra Space::
        // vector<int>result;
        // int i=0,j=0;
        // //merge both array in 3 steps:
        // //step-1
        // while(i<m && j<n){
        //     if(nums1[i]<nums2[j]){
        //         result.push_back(nums1[i++]);
        //     }
        //     else{
        //         result.push_back(nums2[j++]);
        //     }
        // }
        // //step-2
        // while(i<m){
        //     result.push_back(nums1[i++]);
        // }
        // //step-3
        // while(j<n){
        //     result.push_back(nums2[j++]);
        // }
        // //Now finally push all ele into nums1:
        // nums1.resize(m+n);
        // for(int k=0;k<m+n;k++){
        //     nums1[k]=result[k];
        // }

        // Now solve this in S.c =O(1)
        // basically we are doing in nums1 and insert the element from last(end) to array
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        int mini=min(i,j);
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[k--]=nums1[i--];
            }
            else{
                nums1[k--]=nums2[j--];
            }
        }
    }
};