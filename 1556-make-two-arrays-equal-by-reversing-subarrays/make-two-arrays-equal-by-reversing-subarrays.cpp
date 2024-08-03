class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> mp1, mp2;
    for(auto i : target) {
        mp1[i]++;
    }    
    for(auto i : arr) {
        mp2[i]++;
    }
    return mp1 == mp2;
  }
};