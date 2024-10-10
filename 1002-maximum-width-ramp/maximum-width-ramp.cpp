class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
    vector<pair<int, int>> num_indices;
    for (int i = 0; i < nums.size(); ++i) {
        num_indices.push_back({nums[i], i});
    }
    sort(num_indices.begin(), num_indices.end());
    
    int res = 0;
    int min_index = num_indices[0].second;
    
    for (int i = 1; i < num_indices.size(); ++i) {
        res = max(res, num_indices[i].second - min_index);
        min_index = min(min_index, num_indices[i].second);
    }
    
    return res;

    }
};