class Solution {
public:
vector<string> commonChars(vector<string>& words) {
    vector<int>minFreq(26,INT_MAX);
    vector<string>ans;

    for(auto word: words){
        vector<int>minChar(26,0);
        for(char ch: word){
            minChar[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            minFreq[i]= min(minFreq[i],minChar[i]);
        }
    } // yaha tak all common char mil chuke honge::
    // which have >0 that is my answer::
    for(int i=0;i<26;i++){
    while(minFreq[i]-- >0){
        ans.push_back(string(1,i+'a'));
    }
   }
   return ans; 

  }

};