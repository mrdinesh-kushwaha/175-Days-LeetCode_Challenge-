class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string>s1; // create two vectors
        vector<string>s2;
        string x;
        stringstream sep(sentence1);
            while(sep>>x)            //divide sentence into words
               s1.push_back(x);
        string y;
        stringstream sep1(sentence2);
            while(sep1>>y)
                 s2.push_back(y);
        int start1 = 0 , start2 = 0 , end1 = s1.size() - 1 , end2 = s2.size() - 1 ;
        while(start1<=end1&&start2<=end2)
        {
            if(s1[start1]==s2[start2]) 
            {
                start1++; start2++;
            }
            else if(s1[end1]==s2[end2]) 
            {
                end1--; end2--;
            }
            else  return false;
        }
        return true;
    }
        
};