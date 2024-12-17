class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int len=s.length();
        vector<int>count(26,0);
        for(auto& i:s){
            count[i-'a']++;
        }
        string ans;
        int i=25;
        while(i>=0){
            if(count[i]==0){
                i--;
                continue;
            }
            char ch = 'a'+i;
            int freq= min(count[i],repeatLimit);

            ans.append(freq,ch);
            count[i]-=freq;

            if(count[i] > 0){
                int j = i-1;
                while(j>=0 && count[j]==0){
                    j--;
                }
                if(j<0) break;

                ans.push_back('a'+j);
                count[j]--;
            }
        }
        return ans;
    }
};