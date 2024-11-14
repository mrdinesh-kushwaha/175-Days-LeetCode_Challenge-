class Solution {
public:
bool is_possible(vector<int> &q,int n,int mid){
    int count=0;
    for(int i=0;i<q.size();i++){
       int divi=q[i]/mid;
       int mod=q[i]%mid;
       count+=divi;
       if(mod>0) count++;
    }
   return count>n;
}
    int minimizedMaximum(int n, vector<int>& q) {
        int end=*max_element(q.begin(),q.end());
        int start=1;
        // cout<< end<<" "<<sum;
        while(start<end){
            int mid=start+(end-start)/2;
            if(is_possible(q,n,mid)) start=mid+1;
            else end=mid;
        }
        return end;
    }
};