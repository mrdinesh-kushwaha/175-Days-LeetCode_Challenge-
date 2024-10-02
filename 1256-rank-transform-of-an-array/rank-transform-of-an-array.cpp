class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int>mp;
        set<int>st;

        for(auto& i: arr){
            st.insert(i);
        }
        int rank=1;
        for(auto& i:st){
            mp[i]=rank++;
        }

        for(int i=0;i<arr.size();i++){
            arr[i]=mp[arr[i]];
        }

        return arr;
    }
};