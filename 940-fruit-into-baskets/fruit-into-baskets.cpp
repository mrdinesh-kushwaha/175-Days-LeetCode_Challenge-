class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int>freq;

        int low=0, high=0;
        int ans = INT_MIN;
        while(high<n){
            freq[fruits[high]]++;

            // shrinking process
            while(freq.size()>2)  // maximum i can get 2 basket
            {
                freq[fruits[low]]--;
                if(freq[fruits[low]]==0){
                    freq.erase(fruits[low]);
                }
                low++;
            }

            int len = high-low+1;
            ans = max(ans, len);
            high++;
        }

        return ans;
    }
};