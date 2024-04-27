/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool solve(TreeNode* root , long long int lb, long long int ub){
    //     if(root==NULL){
    //         return true;
    //     }

    //     if(root->val >lb && root->val <ub){

    //         bool leftAns=solve(root->left,lb,root->val);// left me range upper se less hoga
    //         bool rightAns=solve(root->right,root->val,ub);// right me lb change hogaa

    //         return leftAns&&rightAns;
    //     }
    //     else{
    //         return false;
    //     }

        
    // }
    // bool isValidBST(TreeNode* root) {

    //     long long int lowerBound=-4294967296; // range bcz given INT_MIN or INT_MAX ke equal bhi ho skta hai
    //     long long int upperBound=4294967296;

    //     bool ans=solve(root,lowerBound,upperBound);

    //     return ans;

    //***M--2 USING SORTED METHOD:::
    void inOrder(TreeNode* root,vector<int>&ans){
        if(root==NULL){
            return;
        }

        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
     
    }
    bool isValidBST(TreeNode* root) {
        //M-2 using Sorting Method:
        vector<int>ans;
        inOrder(root,ans);

        // check inorder Sorted hai ya NHI::if hai the valid BST
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]>=ans[i+1]){
                return false;
            }
        }
        return true;
    }
};