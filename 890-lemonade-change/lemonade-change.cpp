class Solution {
public:
bool lemonadeChange(vector<int>& bills) {
    int five = 0;
    int ten = 0;

    for (auto &bill : bills) {
        if (bill == 5) {
            five++;
        } 
        else if (bill == 10) {
            ten++;
            if (five > 0) { // 5 rupay ka sikka ho tab:
                five--;
            } else {
                return false; // nhi hai to return false :
            }
        } 
        else { // bill = 20
            if (ten > 0 && five > 0) { // 15 rupay return krna hai 10->1 , 5->1
                ten--;
                five--;
            } else if (five >= 3) {  // or 5 ka >=3 ho for return ke liye:
                five -= 3;
            } else {
                return false;
            }
        }
    }

    return true;
   }

};