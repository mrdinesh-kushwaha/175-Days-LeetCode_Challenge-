class Solution {
public:
    int possibleToMake(vector<int>& bloomDay,int mid,int k){
        int no_Bouquets=0; // Guldaste
        int adjacent =0;

        for(int i=0;i<bloomDay.size();i++){
            if(bloomDay[i]<=mid){
                adjacent++;
            }
            else{
                adjacent=0;
            }
            if(adjacent==k){
                no_Bouquets++;
                adjacent=0;
            }
        }
        return no_Bouquets;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {

        int start_Days= 0;
        int end_Days = *max_element(begin(bloomDay),end(bloomDay));

        int minDays=-1;

        while(start_Days <= end_Days){
            int mid= (start_Days + end_Days)/2;

            if(possibleToMake(bloomDay,mid,k)>=m){
                minDays=mid;
                end_Days= mid-1;
            }
            else{
                start_Days= mid+1;
            }
        }
    return minDays;
    }
};