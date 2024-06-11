class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // brute force approach:
        vector<int>ans;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<arr1.size();j++){
                if(arr2[i]==arr1[j]){
                    ans.push_back(arr1[j]); // store 
                    arr1[j]=-1; // marking 
                }
            }
        }
        sort(arr1.begin(),arr1.end()); // soring bcz not in arr2 :

        for(int i=0;i<arr1.size();i++){ // which are not in arr2 then push 
            if(arr1[i]!=-1) ans.push_back(arr1[i]);
        }

        return ans;
        
    }
};