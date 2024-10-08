class Solution {
public:
    int minAddToMakeValid(string s) {
        
        stack<char>st;
        int n= s.length();
        for(int i=0;i<n;i++){
            char ch= s[i];
            if(ch=='(' || st.empty()){
                st.push(ch);
            }
            else if(s[i]==')' && st.top()=='('){
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
        return st.size();
    }
};