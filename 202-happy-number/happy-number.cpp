class Solution {
public:
int sumOfSqaureNum(int n){ //for finding sum of sequre of digit 
    int sum = 0;
    while(n>0){
        int digit = n%10;
        sum = sum + digit*digit;
        n = n/10;
    }
    return sum;
}
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(fast!=1){
            slow = sumOfSqaureNum(slow); //1-step
            fast = sumOfSqaureNum(fast);
            fast = sumOfSqaureNum(fast); //2-steps

            if(slow == fast && slow!=1)//means detect cycle and not equal 1
            {
                return false;
            }
        }
        return true;
    }
};