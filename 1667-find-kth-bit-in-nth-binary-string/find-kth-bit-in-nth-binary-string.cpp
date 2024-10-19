class Solution {
public:
    string revInv(string prevStr){
        string str = prevStr;
        for(auto& ch : str){ // invert 
            ch = ((ch =='0') ? '1' : '0');
        }
        reverse(str.begin(),str.end()); // Reverse 
        return str;
    }
    string findSn(int n){
        // Base case:
        if(n==1) return "0";

        string prevStr = findSn(n-1);

        return prevStr + "1" + revInv(prevStr); // add sn-1 + "1" + reverse(invert(sn-1))
    }
    char findKthBit(int n, int k) {
        // Approaches::
        // find s i-1 +
        // find invert of si-1 +
        // find reverse of si-1 
        string s = findSn(n);
        return s[k-1];
    }
};