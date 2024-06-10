class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int>temp(heights.size());
        temp=heights;// compy all element into temp:

        // for(int i=0;i<heights.size();i++){
        //     temp[i]=heights[i];
        // }

        sort(heights.begin(),heights.end());

        int ans=0;
        for(int i=0;i<temp.size();i++){
            if(temp[i]!=heights[i]) ans++;
        }
        return ans;
    }
};