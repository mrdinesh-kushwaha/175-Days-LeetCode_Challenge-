class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    // unordered_map<int,int>mp;
    // for(int i=0;i<nums.size();i++){  // T.C =O(N) , S.C = O(N)
    //     int num = target-nums[i];
    //     if(mp.find(num)!=mp.end()){
    //         return {i,mp[num]};
    //     }
    //     mp[nums[i]]=i;
    // }
    // return {};
    // }

    //****Optimise Space Complexity -> O(1)

    vector<pair<int,int>>num;
    for(int i=0;i<nums.size();i++){
        num.push_back({nums[i],i});
    }
    sort(begin(num),end(num));

    int i=0;
    int j=num.size()-1;
    while(i<j){
        int sum = num[i].first+num[j].first;
        if(sum==target) return {num[i].second,num[j].second};
        else if(sum > target) j--;
        else i++;
    }
    return {};
    }
};