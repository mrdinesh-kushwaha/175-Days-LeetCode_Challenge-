class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        int n=gifts.size();
        while(k--){
            int idx = 1;
            int maxi=INT_MIN;
            for(int i=0;i<n;i++){
                if(maxi<=gifts[i]){
                maxi=max(maxi,gifts[i]);
                idx=i;
                }
            }
            gifts[idx]=sqrt(maxi);
        }
        long long sum=0;
        for(auto& i: gifts) sum+=i;

        return sum;
    }
};