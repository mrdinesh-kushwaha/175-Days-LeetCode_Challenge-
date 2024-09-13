class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char>st(allowed.begin(),allowed.end());
        int count=0;
        for(string s:words){
            string temp=s;
            int f=0;
            for(int i=0;i<temp.length();i++){
                if(st.count(temp[i])){
                    f=1;
                }
                else {
                    f=0;
                    break;
                }

            }
            if(f==1) count++;
        }
        return count;
    }
};