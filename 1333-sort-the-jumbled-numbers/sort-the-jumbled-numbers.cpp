class Solution {
public:
    string getMapped(string& num,vector<int>&mapping){
        string mappedStr="";
        for(int i=0;i<num.length();i++){
            char ch=  num[i];
            int intch= ch - '0';
            mappedStr+=to_string(mapping[intch]);
        }
        return mappedStr;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        int n=nums.size();
        vector<pair<int,int>>vec;

        for(int i=0;i<nums.size();i++){
            string numStr=to_string(nums[i]); // convert integer to String:

            string mappedNum=getMapped(numStr,mapping);

            int mappedNumInt=stoi(mappedNum); // convert string to integer:
            vec.push_back({mappedNumInt,i});
        }
        sort(begin(vec),end(vec));
        vector<int>ans;
        for(auto &i:vec){
            int index=i.second;
            ans.push_back(nums[index]);
        }
        return ans;
    }
};