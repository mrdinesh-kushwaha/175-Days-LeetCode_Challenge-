class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int ans = INT_MIN;
        int left = 0;
        unordered_map<int, int>mp;

        for(int right=0;right<n;right++){
            mp[fruits[right]]++;

            while(mp.size()>2){
                mp[fruits[left]]--;

                if(mp[fruits[left]]==0)
                mp.erase(fruits[left]);

                left++;
            }
            ans = max(ans,right-left+1);
        }
        return ans;
    }
};