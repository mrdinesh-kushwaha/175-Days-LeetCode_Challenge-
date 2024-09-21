class Solution {
public:
    // vector<int> lexicalOrder(int n) {
         
    //      // brute force Approach...................

    //     // vector<string>res;
    //     // for(int i=1;i<=n;i++){
    //     //     res.push_back(to_string(i));
    //     // }
    //     // sort(begin(res),end(res)); //sort according to the lexico-graphical order :::

    //     // vector<int>ans;
    //     // for(auto& i:res)
    //     // ans.push_back(stoi(i)); 

    //     // return ans;

    //     //M-2 ..............

    // }
    void solve(int currNum,int& n,vector<int>&ans){
        if(currNum > n) return ; // if CurrNum N se graeter ho jaye then aa jao
        ans.push_back(currNum);

        for(int append=0;append<=9;append++){
            int newNum= currNum*10 + append; // all possible in lexicographical order.....

            if(newNum > n) return; // if newNum Nse greater Ho jaye....
            solve(newNum,n,ans); //Find all possible...........
        }
    }
      vector<int> lexicalOrder(int n) {
         
        vector<int>ans;
        for(int i=1;i<=9;i++){
            solve(i,n,ans);
        }
        return ans;
    }
};