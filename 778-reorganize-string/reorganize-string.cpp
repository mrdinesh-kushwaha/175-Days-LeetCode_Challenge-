class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        // Count occurrences of each character
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

    
        priority_queue<pair<int, char>> pq; // Changed to sort by count first
        for (auto i : mp) {
            pq.push(make_pair(i.second, i.first)); // Changed to count first
        }

        string ans;

        // Build the result string
        while (pq.size() > 1) {
            auto temp1 = pq.top();
            pq.pop();
            auto temp2 = pq.top();
            pq.pop();

            char first = temp1.second;
            char second = temp2.second;

            ans += first;
            ans += second;

            if (--temp1.first >
                0) { // Decrease count and push back if count > 0
                pq.push(temp1);
            }
            if (--temp2.first >
                0) { // Decrease count and push back if count > 0
                pq.push(temp2);
            }
        }

        // Add the last character if any
        if (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();

            if (temp.first >
                1) { // If count is more than 1, return empty string
                return "";
            }
            ans += temp.second; // Add the last character to the result string
        }

        return ans;
    }
};