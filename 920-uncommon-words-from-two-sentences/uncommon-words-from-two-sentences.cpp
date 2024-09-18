
#include <sstream>
class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {

    vector<string> res; 
    unordered_map<string,int> mp;
    
    // Concatenate the two sentences
    s1 = s1 + " " + s2; // add or Merge both sentence::: in string s1

    stringstream ss(s1); //use for split in words:
    string word;
    // Split the concatenated string and count the occurrence of each word
    while(ss >> word){ // convert s1 sentence into words::: and store into mp
        mp[word]++;
    }

    // Add words that appear only once to the result
    for (auto i : mp) {
        if (i.second == 1) {
            res.push_back(i.first);
        }
    }
    return res;
    }
};