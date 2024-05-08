class Solution {
public:
    vector<string> solve(vector<int>& score,vector<string>&ans){
        
        priority_queue<pair<int,int >>pq;
        for(int i=0;i<score.size();i++){
            pq.push({score[i],i});
        }
        if(!pq.empty()){ // 1st rank 
        int first=pq.top().second;
        ans[first]="Gold Medal";
        pq.pop();
        }
        if(!pq.empty()){ //2nd rank 
        int second=pq.top().second;
        ans[second]="Silver Medal";
        pq.pop();
        }
        if(!pq.empty()){ //3rd rank
        int third=pq.top().second;
        ans[third]="Bronze Medal";
        pq.pop();
        }
        int i=4;  //after 3rd rank insert 
        while(!pq.empty()){
            ans[pq.top().second]=to_string(i);
            i++;
            pq.pop();
        }
        return ans;
    }
    vector<string> findRelativeRanks(vector<int>& score) {
        
        vector<string>ans(score.size());
        return solve(score,ans);
    }
};