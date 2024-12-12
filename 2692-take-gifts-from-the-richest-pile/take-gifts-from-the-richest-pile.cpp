class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        // while(k--){
        //     int idx = 1;
        //     int maxi=INT_MIN;
        //     for(int i=0;i<n;i++){                   // T.C= O(k*N), S.C=O(1)
        //         if(maxi<=gifts[i]){
        //         maxi=max(maxi,gifts[i]);
        //         idx=i;
        //         }
        //     }
        //     gifts[idx]=sqrt(maxi);
        // }

        //  while(k--){
            

        // }
        // long long sum=0;
        // for(auto& i: gifts) sum+=i;

        // return sum;

        //************** optimise T.C = O(k) , S.C = O(N)

        priority_queue<long long>pq;

        for(auto& i:gifts){ // insert all ele in pariority queue
            pq.push(i);
        }

        while(k--){
            int maxi=pq.top();
            pq.pop();
            pq.push(sqrt(maxi));
        }

        long long ans=0;
        while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
        }

        return ans;
    }
};