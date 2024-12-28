class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>result;
        int i=0,j=0;
        //merge both array in 3 steps:
        //step-1
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                result.push_back(nums1[i++]);
            }
            else{
                result.push_back(nums2[j++]);
            }
        }
        while(i<m){
            result.push_back(nums1[i++]);
        }
        while(j<n){
            result.push_back(nums2[j++]);
        }

        nums1.resize(m+n);
        for(int k=0;k<m+n;k++){
            nums1[k]=result[k];
        }
    }
};