class Solution {
public:
int numSteps(string s) {
    int steps = 0;
    int carry = 0;

    for (int i = s.length() - 1; i > 0; --i) {
        if ((s[i] - '0') + carry == 1) {
            // If the current bit with carry is 1, we need to add 1 (making it 0) and then divide
            steps += 2;
            carry = 1; // There will be a carry to the next higher bit
        } else {
            // If the current bit with carry is 0, just divide
            steps += 1;
        }
    }

    // Add the final step if there is a carry from the most significant bit
    steps += carry;

    return steps;
    }
};