class Solution {
public:
    // Function to process the string and calculate the score for pairs of characters
    int removeSolve(string& s, char first, char second, int points) {
        int score = 0; // Initialize score to zero
        int i = 0; // Overwriting index

        // Iterate through each character in the string using the reading index j
        for(int j = 0; j < s.size(); j++) {
            s[i] = s[j]; // Overwrite character at index i with character at index j
            i++; // Increment the overwriting index

            // Check if the last two characters form the specified pair (first, second)
            if(i >= 2 && s[i-2] == first && s[i-1] == second) {
                score += points; // Add points to the score
                i = i - 2; // Remove the last two characters forming the pair
            }
        }

        s = s.substr(0, i); // Truncate the string to the valid length after processing
        return score; // Return the total score
    }

    // Function to calculate the maximum possible score
    int maximumGain(string s, int x, int y) {
        int score = 0; // Initialize total score to zero

        // Choose the order of operations based on which operation (x or y) has higher points
        if(x < y) {
            score += removeSolve(s, 'b', 'a', y);
            score += removeSolve(s, 'a', 'b', x);
        } else {
            score += removeSolve(s, 'a', 'b', x);
            score += removeSolve(s, 'b', 'a', y);
        }

        return score; // Return the maximum possible score
    }
};