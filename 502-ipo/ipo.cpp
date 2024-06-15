class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        // step-1 take vector pair of capital and profit
        vector<pair<int,int>>vec(n);

        for(int i=0;i<n;i++){
            vec[i]={capital[i],profits[i]}; 
        }  
        // step-2 sort the vec based on capital
        sort(begin(vec),end(vec));

        // step-3 take max-heap for store the profit
        priority_queue<int>pq;
        int i=0;
        while(k--){

            while(i<n && vec[i].first <= w){
                pq.push(vec[i].second);
                i++;
            }

            if(pq.empty()) break;
            w+=pq.top();
            pq.pop();
        }
      return w; // maximum capital  
    }
};