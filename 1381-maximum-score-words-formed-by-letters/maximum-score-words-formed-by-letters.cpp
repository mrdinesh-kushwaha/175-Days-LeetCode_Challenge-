class Solution {
public:

    void solve(vector<int>& freq,vector<int>&score,vector<string>& words,int i,int n,int currScore,int& ans){
        ans=max(ans,currScore);
        if(i>=n){
            return ;
        }
        int j=0;
        int tempScore=0;
        vector<int>tempFreq=freq;
        while(j< words[i].length()){
            char ch = words[i][j];
            tempFreq[ch-'a']--;
            tempScore+=score[ch-'a'];

            if(tempFreq[ch-'a']<0){
                break;
            }
            j++;
        }
        if(j== words[i].length()){
            //take option::
            solve(tempFreq,score,words,i+1,n,currScore+tempScore,ans);
        }
        //no take::
        solve(freq,score,words,i+1,n,currScore,ans);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>freq(26,0);

        for(char &ch : letters){
            freq[ch-'a']++;
        }
        int ans=INT_MIN;
        int n=words.size();
        solve(freq,score,words,0,n,0,ans);

        return ans;

    }
};