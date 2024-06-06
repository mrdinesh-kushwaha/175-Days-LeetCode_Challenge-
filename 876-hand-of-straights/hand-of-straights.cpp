class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n %  groupSize) return false; // odd hai element divisble not possible

        map<int,int>mp;
        for(auto i:hand) mp[i]++;

        while(!mp.empty()){
            int curr= mp.begin()->first;

            for(int i=0;i<groupSize;i++){
                if(mp[curr+i]==0)return false; // means freq is Zero ele not present

                mp[curr+i]--;
                if(mp[curr+i]<1) mp.erase(curr+i); // erase freq-> 0
            }
        }
    return true;
    }
};