class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {

        vector<int>nums;
        int n=customers.size();
        int finis=0;
        int start=0;
        int temp=0;
        for(int i=0;i<n;i++){
            finis=max(finis,customers[i][0]);
            finis=finis+customers[i][1];
            int ans= finis-customers[i][0];
          nums.push_back(ans);
        }
        double res=0;
        int size=nums.size();
        for(int i=0;i<n;i++){
            res+=nums[i];
        }
        return res / size;
    }
};