class Solution {
public:
    int appendCharacters(string s, string t) {
        int ans= t.length();
        int i=0;
        int k=0;
        while(k<t.length() && i<s.length()){
            if(s[i]==t[k]){
                ans--;
                i++; k++;
            }
            else
            i++;
        }
        return ans;
    }
};
// take input output faster and enahanced the overall performances 
auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
