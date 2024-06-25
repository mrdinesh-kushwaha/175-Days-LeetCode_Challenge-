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
    void inorder(TreeNode* root,vector<int>&arr){
        //base case:
        if(root==NULL) return ;

        // left call
        inorder(root->left,arr);
        //store
        arr.push_back(root->val);
        //right call
        inorder(root->right,arr);
    }
    TreeNode* solve(TreeNode* root,vector<int>&arr){

        if(root==NULL) return NULL;
            int temp=0;
           for(int i=0;i<arr.size();i++){ // for root node
            if(root->val <arr[i]){
                temp+=arr[i];
            }
          }
        root->val+=temp;

        solve(root->left,arr); // go left
        solve(root->right,arr); // go right
        return root;
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int>arr;
        inorder(root,arr);

        return solve(root,arr);
    }
};