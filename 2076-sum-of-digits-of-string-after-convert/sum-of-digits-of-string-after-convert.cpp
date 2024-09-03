class Solution {
public:
    int getLucky(string s, int k) {

        string temp="";
        for(int i=0;i<s.length();i++){
            int num=s[i]-'a'+1; // map a->1 , b->2 , .....
            temp+=to_string(num);
        }
    
        while(k--){
           int ans=0;
           for(int i=0;i<temp.length();i++){
            ans+=temp[i]-'0'; // string to integer:::
           }
           temp=to_string(ans); // convert integer to string
        }
        return stoi(temp);
    }
};