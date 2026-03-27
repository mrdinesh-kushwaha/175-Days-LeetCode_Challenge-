class Solution {
public:
    int maximumSum(vector<int>& arr) {
        //I will solve using two cases:
        //1-case: with NoDeletion
        //2-case: with OneDeletion (2 options -> ya to phle del kr chuke ho + arr[i],
        // ya abhi vala del kr do and (nodeDeletion) lelo abhi tak)
        //res = max(NoDeletion, OneDeletion)

    int noDeletion = arr[0];   // no deletion
    int oneDeletion = 0;   // one deletion
    int res = arr[0];

    for(int i = 1; i < arr.size(); i++){
        //oneDeletion phle hi likha jayega because noDeletion phle vala use ho rha hai
        oneDeletion = max(oneDeletion + arr[i], noDeletion);   // (phle del chuke hai, arr[i] del kiya)
        noDeletion = max(arr[i], noDeletion + arr[i]); // normal kadane
        
        res = max(res, max(noDeletion, oneDeletion));
    }
    return res;
    }
};