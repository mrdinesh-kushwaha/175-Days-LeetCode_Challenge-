class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {

     sort(happiness.begin(),happiness.end());
     int n=happiness.size();
     int e=n-1;
     long long ans=happiness[e];
     e--;
     k=k-1;
     int i=1;
     while(k--){
      long long temp=happiness[e]-i;
      if(temp>0){
        ans+=temp;
       }
       i++;
       e--;
     }   
    return ans;
        
    }
};