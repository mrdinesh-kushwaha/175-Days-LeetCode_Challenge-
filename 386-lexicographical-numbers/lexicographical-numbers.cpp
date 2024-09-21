class Solution {
public:
    vector<int> lexicalOrder(int n) {
        
        vector<string>res;
        for(int i=1;i<=n;i++){
            res.push_back(to_string(i));
        }
        sort(begin(res),end(res)); //sort according to the lexico-graphical order :::

        vector<int>ans;
        for(auto& i:res)
        ans.push_back(stoi(i)); 

        return ans;
    }
};