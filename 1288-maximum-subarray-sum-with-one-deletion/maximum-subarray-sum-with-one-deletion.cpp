class Solution {
public:
    int maximumSum(vector<int>& arr) {
        //I will solve using two cases:
        //1-case: with NoDeletion
        //2-case: with OneDeletion
        //res = max(NoDeletion, OneDeletion)

        // int oneDeletion = INT_MIN; // Initial me koi element nhi hai to
        // int noDeletion = arr[0];
        // int res = arr[0];

        // for(int i=1;i<arr.size();i++){
        //     int prevNoDeletion = noDeletion;
        //     int prevOneDeletion = oneDeletion;

        //     noDeletion = max(arr[i], noDeletion+arr[i]);

        //     int temp;
        //     if(prevOneDeletion==INT_MIN)
        //     temp = arr[i];
        //     else
        //     temp = prevOneDeletion + arr[i];
        //     oneDeletion = max(temp, prevNoDeletion);

        //     res = max(res, max(oneDeletion, noDeletion));
        // }
        // return res;
        
    int keep = arr[0];   // no deletion
    int del = 0;         // one deletion
    int res = arr[0];

    for(int i = 1; i < arr.size(); i++){
        del = max(del + arr[i], keep);   // delete or extend
        keep = max(arr[i], keep + arr[i]); // normal kadane
        
        res = max(res, max(keep, del));
    }
    return res;
    }
};