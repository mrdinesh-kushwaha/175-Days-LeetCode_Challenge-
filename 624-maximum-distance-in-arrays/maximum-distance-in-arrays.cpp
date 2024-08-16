class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

    int minElement = arrays[0].front(); // Minimum element from the first array
    int maxElement = arrays[0].back();  // Maximum element from the first array
    int maxDistance = 0;

    for (int i = 1; i < arrays.size(); ++i) {
        const auto& array = arrays[i];
        
        // Compute the distance with the current minimum and maximum elements
        maxDistance = max(maxDistance, abs(array.back() - minElement));
        maxDistance = max(maxDistance, abs(maxElement - array.front()));
        
        // Update minElement and maxElement
        minElement = min(minElement, array.front());
        maxElement = max(maxElement, array.back());
    }
    
    return maxDistance;

    }
}; 