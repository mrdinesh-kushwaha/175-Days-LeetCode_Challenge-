class Solution {
public:
    int minOperations(vector<string>& logs) {
        int res=0;
        int i=0;
        while(i<logs.size()){
            if(logs[i]=="../"){
                if(res!=0) res--;
                i++;
            }
            else if(logs[i]=="./"){
                i++;
            }
            else{
            i++;
            res++;
            }
        }
    return res;     
    }
};