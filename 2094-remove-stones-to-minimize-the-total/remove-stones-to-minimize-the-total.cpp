class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {

        priority_queue<int>pq; // max queue

        //insert all element in pq
        for(int i=0;i<piles.size();i++){
            pq.push(piles[i]);
        }

        while(k--){
            int maxele=pq.top();
            pq.pop();
            maxele=maxele-floor(maxele/2);
            pq.push(maxele);
        }

        int sum=0;
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            sum+=ele;
        }
        return sum;
    }
};