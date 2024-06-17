class Solution {
public:
    bool isPerfectSquare(int num) {
    
        long long i=1;
        if(num==1) return true;
        while(i*i <= num){
            
            if( i*i == num) return true;
            if( i*i > num) break;
            i++;
        }
        return false;
    }
};