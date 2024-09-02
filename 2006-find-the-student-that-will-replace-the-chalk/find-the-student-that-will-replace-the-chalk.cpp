class Solution {
public:
 int chalkReplacer(vector<int>& chalk, int k) {
    long long total = 0;
    for (int c : chalk) {
        total += c;
    }
    
    k %= total; // Reduce k to the remainder when divided by total chalk
    
    for (int i = 0; i < chalk.size(); i++) {
        if (k < chalk[i]) {
            return i;
        }
        k -= chalk[i];
    }   
    return 0; // This line should never be reached
   }
};