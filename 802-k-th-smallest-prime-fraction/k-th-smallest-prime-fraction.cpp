class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        int size=arr.size();
        priority_queue<vector<double>>pq; // take maxheap 

        for(int i=0;i<size-1;i++){
            for(int j=i+1;j<size;j++){
                double div = (double)arr[i]/arr[j];
                pq.push(vector<double>{div,(double)arr[i],(double)arr[j]});
                if(pq.size()>k){
                pq.pop();
                }
            }
        }
        auto temp=pq.top();
        vector<int>ans(2);
        ans[0]=temp[1];
        ans[1]=temp[2];

        return ans;
    }
};