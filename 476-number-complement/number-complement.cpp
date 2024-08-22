class Solution {
public:
// int findComplement(int num) {
    // if (num == 1)
    //     return 0;
    // if (num == 0)
    //     return 1;

    // long long binary = 0;
    // long long multiplier = 1;

    // // Convert num to binary (stored as an integer)
    // while (num != 0) {
    //     int rem = num % 2;
    //     binary = binary + rem * multiplier;
    //     multiplier *= 10;
    //     num /= 2;
    // }

    // // Convert binary to complement
    // long long complement = 0;
    // multiplier = 1;

    // while (binary != 0) {
    //     int rem = binary % 10;
    //     if (rem == 1)
    //         rem = 0;
    //     else
    //         rem = 1;

    //     complement += rem * multiplier;
    //     multiplier *= 10;

    //     binary /= 10;
    // }

    // // Convert complement binary back to decimal
    // int ans = 0;
    // int i = 0;
    // while (complement != 0) {
    //     int rem = complement % 10;
    //     ans += rem * pow(2, i);
    //     complement /= 10;
    //     i++;
    // }

    // return ans;

 int findComplement(int num) {
    // Edge case: if num is 0, its complement is 1
    if (num == 0)
        return 1;

    unsigned mask = ~0; // Start with all bits set to 1
    while (num & mask) {
        mask <<= 1;
    }

    // XOR num with the mask to flip all bits up to the highest set bit
    return ~num & ~mask;

   }

};