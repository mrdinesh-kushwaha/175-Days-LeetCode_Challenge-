class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {

        unordered_map<string,int>mp;
        for(auto i:arr) mp[i]++;
        int count=0;
        for(auto s:arr){
            if(mp[s]==1) //value of mp distinct
            {
                count++;
                if(count==k) return s;
            }
        }
        return "";
    }
};