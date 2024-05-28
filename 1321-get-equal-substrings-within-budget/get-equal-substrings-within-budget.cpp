// class Solution {
// public:
//     int equalSubstring(string s, string t, int maxCost) {

//         int ans=0;
//         int mxcost = maxCost;
//         for(int i=0;i<s.length();i++){
//             if(abs(s[i]-t[i])<=mxcost){
//                 ans++;
//                 mxcost = mxcost-abs(s[i]-t[i]);
//             }
//         }
//         if(ans!=0) 
//         return ans;
//         else
//         return 0;
//     }
// };


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int i = 0, j = 0;
        int ans = 0, cost = 0, n = s.size();
        while(j<n)
        {
            cost += abs(s[j] - t[j++]);
            while(cost > maxCost) cost -= abs(s[i] - t[i++]);
            ans = max(ans, j-i);
        }
        return ans;
    }
};