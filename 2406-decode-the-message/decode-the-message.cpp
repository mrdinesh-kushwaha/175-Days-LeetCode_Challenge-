class Solution {
public:
    string decodeMessage(string key, string message) {

        unordered_map<char,char>mp;
        char ch='a';
        int n=key.length();
        for(int i=0;i<n;i++){  // mapping the key from alphabet:::
            if(key[i]==' ')
            continue;

            if(mp.find(key[i])==mp.end()){
                mp[key[i]]=ch++;
            }
        }

        string ans="";
        for(int i=0;i<message.length();i++){
            if(message[i]==' '){
            ans.push_back(' ');
            }
            else{
                ans.push_back(mp[message[i]]);
            }
        }
        return ans;
    }
};