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
    void deleteNode(TreeNode* &root,vector<TreeNode*>&ans,unordered_map<int,int>&mpp){
        if(root==NULL) return;
        if(root->left) deleteNode(root->left,ans,mpp);
        if(root->right) deleteNode(root->right,ans,mpp);
        if(mpp.find(root->val)!=mpp.end()){
            if(root->left) ans.push_back(root->left);
            if(root->right) ans.push_back(root->right);
            root=NULL;
        }
    }
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*>ans;
        int n=to_delete.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[to_delete[i]]++;
        }
        deleteNode(root,ans,mpp);
        if(root) ans.push_back(root);
        return ans;
    }
};