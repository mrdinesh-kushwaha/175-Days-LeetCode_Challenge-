class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {

    //  string ans;
    //  sort(s.begin(),s.end());
    //  int n= s.size();
    //  string first=s[0],last=s[n-1];
    //  for(int i=0;i<min(first.length(),last.length());i++)
    //  {
    //      if(first[i]!=last[i])
    //      return ans;

    //      ans+=first[i];
    //  }
    //   return ans;

    string ans="";
    bool match=true;

    for(int i=0;i<s[0].length();i++){
        char ch=s[0][i];  // first string ke char ko point kr rha hai::

        for(int j=1;j<s.size();j++){
            if(ch!=s[j][i]){
                match=false;
               break;
            }
        }
        if(match!=true)
        break;
        else
        ans+=ch;
    }
    return ans;
    }
};