class Solution {
public:
    int maxArea(vector<int>& height) {
        int storeWater = INT_MIN;
        int left=0;
        int right=height.size()-1;

        while(left<right){
            int area = (min(height[left],height[right])*(right-left)); //length*width
            if(height[left]<height[right]) left++;
            else right--;

            storeWater = max(storeWater,area);
        }
        return storeWater;
    }
};