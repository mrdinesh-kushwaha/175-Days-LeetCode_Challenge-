class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>ans;
        int row=queries.size();
        for(int i=0;i<row;i++){
            int left=queries[i][0];
            int right=queries[i][1];
            int temp=arr[left];
            // find xor in given left and right intervals
                while(left<right){
                if(left+1<=right){
                    temp=temp^arr[left+1];
                }
                left++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};