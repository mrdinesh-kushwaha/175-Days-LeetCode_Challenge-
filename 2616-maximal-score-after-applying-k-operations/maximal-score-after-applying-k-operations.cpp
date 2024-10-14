class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        //solve using maxheap
        long long ans=0;
        priority_queue<int>pq(nums.begin(),nums.end()); // at top always max Element

        while(k--){
            int maxEle= pq.top();
            pq.pop();

            ans+=maxEle;
            maxEle= ceil(maxEle/3.0);
            pq.push(maxEle);
        }
        return ans;
    }
};