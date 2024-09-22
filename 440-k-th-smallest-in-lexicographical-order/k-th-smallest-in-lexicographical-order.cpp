class Solution {
public:
    // int findKthNumber(int n, int k) {
    //     vector<string>ans;
    //     for(int i=1;i<=n;i++){
    //         ans.push_back(to_string(i)); // it's Brute force approach:::
    //     }
    //     sort(begin(ans),end(ans));
    //     vector<int>res;
    //     for(auto &i: ans){
    //         res.push_back(stoi(i));
    //     }
    //     if(k>=1) return res[k-1];
    // }

    int findKthNumber(int n, int k) {
        long curr = 1; // Start with the smallest lexicographical number
        k--; // Decrement k since we are starting from index 0
        
        while (k > 0) {
            int count = countNumbers(curr, n); // Count how many numbers start with 'curr'
            if (k >= count) { // If k is larger than count, go to next prefix
                k -= count; 
                curr++; // Move to the next prefix
            } else { // If k is within count, go deeper into the current prefix
                curr *= 10; // Go one level deeper (append '0')
                k--; // One number found
            }
        }
        return (int)curr; // Return the kth number
    }

private:
    int countNumbers(long curr, long n) {
        long next = curr + 1;
        int count = 0;
        
        while (curr <= n) {
            count += min(n + 1, next) - curr; // Count numbers in this range
            curr *= 10; // Move to the next level
            next *= 10; // Update next for the new range
        }
        
        return count; // Return total count of numbers starting with 'curr'
    }

};