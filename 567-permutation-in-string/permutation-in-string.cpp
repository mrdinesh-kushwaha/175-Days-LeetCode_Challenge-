class Solution {
public:
    bool solve(string s,string s1){
        sort(s.begin(),s.end());
        sort(s1.begin(),s1.end());
        return s==s1;
    }
    bool checkInclusion(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        if(n1>n2) return 0;
        int i=0;
        while(i<=n2-n1){
            string s=s2.substr(i,s1.size());
            if(solve(s,s1)) return 1;
            i++;
        }
        return 0;
    }
};