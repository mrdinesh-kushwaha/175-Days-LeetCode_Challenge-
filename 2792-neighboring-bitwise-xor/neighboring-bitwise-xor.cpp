class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = derived[0];
        for(int i = 1; i < derived.size(); i++) {
            x ^= derived[i];
        }
        return x == 0;
    }
};