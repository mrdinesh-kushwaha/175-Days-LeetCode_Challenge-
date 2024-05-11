class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {

        int n=quality.size();
        double ans=INT_MAX;
        double sum=0;

        vector<pair<double,int>>details;

        for(int i=0;i<n;i++){
            details.push_back({(double)wage[i]/quality[i],quality[i]});
        }
        sort(details.begin(),details.end());


        priority_queue<int>pq; // max heap
        for(int i=0;i<n;i++){

            pq.push(details[i].second);
            sum+=details[i].second;

            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans=min(ans,sum*details[i].first);
            } 
        }
        return ans;       
    }
};