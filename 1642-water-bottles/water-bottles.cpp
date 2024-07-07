class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

    int total_drunk = 0;
    while (numBottles >= numExchange) {
        int new_full_bottles = numBottles / numExchange;
        int remaining_empty_bottles = numBottles % numExchange;
        total_drunk += numBottles - remaining_empty_bottles; // Drink all full bottles except the ones left as remainder
        numBottles = new_full_bottles + remaining_empty_bottles;
    }
    // Add the remaining bottles that cannot be exchanged but can still be drunk
    total_drunk += numBottles;

    return total_drunk;
    }
};