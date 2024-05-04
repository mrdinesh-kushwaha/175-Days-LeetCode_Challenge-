class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(),people.end());
        // Solve Using Two Pointer Approach::: T.C=O(N)
        int s=0;
        int e=people.size()-1;
        int countBoat=0;

        while(s<=e){
            if(people[s]+people[e]<=limit){
                s++;
                e--;
                countBoat++;
            }
            else{
                e--;
                countBoat++;
            }
        }
        return countBoat;
    }
};