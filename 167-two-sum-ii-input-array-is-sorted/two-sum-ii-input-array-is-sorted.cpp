class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;

        int n = numbers.size();
        int left=0;
        int right=n-1;

        while(left<right){
            int sum = numbers[left]+numbers[right];

            if(sum == target) {
                res.push_back(left+1);
                res.push_back(right+1);
                return res;
            }
            else if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }
        return {};
    }
};