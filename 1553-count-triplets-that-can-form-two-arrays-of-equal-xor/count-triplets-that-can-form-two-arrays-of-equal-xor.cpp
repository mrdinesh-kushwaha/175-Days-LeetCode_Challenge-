class Solution {
public:
int xour(vector<int>&arr,int start,int end) {
    int ans=0;
    for(int i=start;i<=end;i++){
        ans^=arr[i];
    }
    return ans;
}
    int countTriplets(vector<int>& arr) {
       int count=0;
       int n=arr.size();
       for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int a=xour(arr,i,j-1);
            for(int k=j;k<n;k++){
            int b=xour(arr,j,k);
            if(a==b) count++;
            }
          }   
       } 
     return count;   
    }
};