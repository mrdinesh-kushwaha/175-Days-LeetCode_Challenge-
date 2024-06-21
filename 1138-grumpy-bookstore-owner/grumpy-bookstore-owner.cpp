class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int n= customers.size();
        int maxUnsat =0;
        int currUnsat =0;

        for(int i=0;i<minutes;i++){ // sliding Windows problem
            currUnsat += customers[i]*grumpy[i];
        }

        maxUnsat = currUnsat;
        int i=0;
        int j= minutes;

        while(j<n){
            currUnsat+= customers[j]*grumpy[j]; // increase / add the next element in windows
            currUnsat-= customers[i]*grumpy[i]; // decrease windows / subtract previous element in windows

            maxUnsat= max(maxUnsat,currUnsat);
            i++,j++;
        }

        // maxUnsat is maximum unsatisfied , we can satisfied using given secret technique: given

        // now add+ in satisfied customers :
        int ans=maxUnsat;
        for(int i=0;i<n;i++){
            if(grumpy[i]==0) // means which are satisfied cutomers:
            ans+=customers[i];
        }
    return ans;
    }
};