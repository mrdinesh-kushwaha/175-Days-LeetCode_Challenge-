class Solution {
public:
    bool judgeSquareSum(int c) {
        
        // long long i=1;
        // while( c- i*i >= 0){
        //     if(c-i*i==1||c-i*i==0) return true;
        //     i++;
        //     if(c-i*i < 0) break;   // brute force approach
        // }
        // return false;

        // using two pointer Approach

        long long start=0;
        long long end=sqrt(c);

        while(start<=end){
            
            long long prod= (start*start + end*end);
            if(prod==c) return true;

            if(prod < c) start++;
            else end--;
        }
        return false;
    }
};