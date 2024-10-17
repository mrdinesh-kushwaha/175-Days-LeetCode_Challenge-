class Solution {
public:
    int maximumSwap(int num) {
      string s = to_string(num);
      int n= s.length();
      int maxNum= num;
      for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            swap(s[i],s[j]);
            maxNum=max(maxNum,stoi(s));
            swap(s[i],s[j]);
        }
      }  
      return maxNum;
    }
};