class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> prefix;
        // store all prefix of anyone array
        for(auto& val:arr1){
            int num = val;
            while(num>0){
                prefix[num]++; // 1000 -> 1000/10 = 100 -> 100/10 = 10 -> 10/10 = 1
                num /= 10;
            }
        }

        // max length variable mx
        int mx = INT_MIN;

        // instead of creating other map we can check prefix at moment
        for(auto& val:arr2){
            int num = val;
            // count no. of digits in num
            int len = log10(num)+1;

            // again generate all prefix
            while(num>0){
                // if prefix found simply break
                if(prefix.find(num)!=prefix.end()){
                    break;
                }
                num /= 10;
                // decrease digit as we decreased prefix
                len--;
            }

            mx = max(mx, len);
        }

        return mx;
    }
};