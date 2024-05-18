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
    int solve(TreeNode* root, int &moves){

        if(!root){ // root==NULL
            return 0;
        }

        int l=solve(root->left,moves);
        int r=solve(root->right,moves);

        moves+=abs(l)+abs(r);

        return (l+r+root->val)-1 ;
    }
    int distributeCoins(TreeNode* root) {
        int moves=0;
        solve(root,moves);

        return moves;
        
    }
};