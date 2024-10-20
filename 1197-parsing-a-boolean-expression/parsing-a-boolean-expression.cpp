class Solution {
public:
    char solveOp(vector<char> exp,char op){
        // for '!'
        if(op=='!'){
            if(exp[0]=='t') return 'f';
            else return 't';
        }
        // for AND
        if(op=='&'){
            for(auto& ch:exp){
                if(ch=='f') return 'f';
            }
            return 't';
        }
        // for OR
        if(op=='|'){
            for(auto& ch : exp){
                if(ch=='t') return 't';
            }
            return 'f';
        }
        return true; // never will come here
    }
    bool parseBoolExpr(string expression) {
        stack<char>st;
        int n = expression.length();
        for(int i=0;i<n;i++){

            if(expression[i]==',') continue; // do nothing

            if(expression[i]==')'){
                vector<char>exp;
                while(st.top()!='('){
                    exp.push_back(st.top());
                    st.pop();
                }
                st.pop(); // pop '(' also
                char op=st.top(); // find operator
                st.pop(); // remove op also

                st.push(solveOp(exp,op));
            }
            else{
                st.push(expression[i]);
            }
        }
        return st.top()=='t'? true:false;
    }
};