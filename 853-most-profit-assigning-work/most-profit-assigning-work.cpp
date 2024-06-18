class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        //step-1 take a pair of difficulty and profit:
        vector<pair<int,int>>vec;
        for(int i=0;i<difficulty.size();i++){
            vec.push_back({difficulty[i],profit[i]}); 
        }
        //now sort based on difficulty :
        sort(begin(vec),end(vec));
        //step-2 sort worker:
        sort(begin(worker),end(worker));

        int max_profit=0;
        int max_profit_curr= 0;

        int i=0;

        for(auto w : worker){
            while(i< worker.size() && w>= vec[i].first){
                max_profit_curr= max(max_profit_curr,vec[i].second);
                i++;
            }
            max_profit += max_profit_curr;
        }
    return max_profit;
    }
};