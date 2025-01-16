class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>myXor;
        // for(int i=0;i<nums1.size();i++){
        //     int temp=0;
        //     for(int j=0;j<nums2.size();j++){
        //         temp = nums1[i]^nums2[j];
        //         myXor.push_back(temp);
        //     }
        // }
        // int ans=0;
        // for(int i=0;i<myXor.size();i++){
        //     ans^=myXor[i];
        // }
        // return ans;

        int m=nums1.size();
        int n=nums2.size();

        unordered_map<int,long>mp;

        for(auto& num : nums1){
            mp[num]+=n;
        }
        for(auto& num: nums2){
            mp[num]+=m;
        }
        int result=0;
        for(auto it : mp){
            int num=it.first;
            int freq=it.second;
            if(freq%2 != 0){
                result^=num;
            }
        }
        return result;
    }
};