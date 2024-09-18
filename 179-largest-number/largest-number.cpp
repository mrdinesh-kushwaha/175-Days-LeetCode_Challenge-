class Solution {
public:
    string largestNumber(vector<int>& nums) {

        auto myComparator=[](int& a,int& b){ // custom comparator:: for sorting 
            string s1=to_string(a);
            string s2=to_string(b);

            if(s1+s2 > s2+s1) // then sorting::[a,b]
            return true;

            return false; // [b,a]
        };
        sort(begin(nums),end(nums),myComparator);
        if(nums[0]==0){
            return "0";
        }
        string res="";
        for(auto&  i: nums){
            res+=to_string(i);
        }

        return res;
    }
};