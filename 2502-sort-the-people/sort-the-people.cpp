class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {

        unordered_map<int,string>mp;
        for(int i=0;i<heights.size();i++){
            mp[heights[i]]=names[i];
        }
        sort(heights.rbegin(),heights.rend());
        vector<string>ans;
        
        for(int i=0;i<heights.size();i++){
            ans.push_back(mp[heights[i]]);
        }
        return ans;
    }
};