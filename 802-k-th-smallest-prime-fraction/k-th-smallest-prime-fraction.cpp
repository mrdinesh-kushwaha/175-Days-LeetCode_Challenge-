// class Solution {
// public:
//     vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

//         int size=arr.size();
//         priority_queue<vector<double>>pq; // take maxheap 

//         for(int i=0;i<size-1;i++){
//             for(int j=i+1;j<size;j++){
//                 double div = (double)arr[i]/arr[j];
//                 pq.push(vector<double>{div,(double)arr[i],(double)arr[j]});
//                 if(pq.size()>k){
//                 pq.pop();
//                 }              //T.c=O(N^2)
//             }
//         }
//         auto temp=pq.top();
//         vector<int>ans(2);
//         ans[0]=temp[1];
//         ans[1]=temp[2];

//         return ans;
//     }
// };

class Solution {
public:
typedef vector<double> V;
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

        int n=arr.size();
        priority_queue<V,vector<V>,greater<V>> pq; // min heap {fraction,i,j}

        for(int i=0;i<n;i++){
            pq.push({(double)arr[i]/arr[n-1],(double)i,(double)n-1});
        }

        int smallest=1;
        while(smallest<k){
            
            V temp=pq.top();
            pq.pop();

            int i=temp[1]; //index
            int j=temp[2]-1; //index

            pq.push({(double)arr[i]/arr[j],(double)i,(double)j});

            smallest++;
        }
        V temp=pq.top();
        int i=temp[1];
        int j=temp[2];

        return {arr[i],arr[j]};

    }

};