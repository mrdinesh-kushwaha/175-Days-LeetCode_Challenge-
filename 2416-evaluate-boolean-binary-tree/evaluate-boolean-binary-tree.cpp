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
    bool evaluateTree(TreeNode* root) {

        if(root->left==NULL ||root->right==NULL){
            if(root->val==0){
                return false;
            }
            else if(root->val==1){
                return true;
            }      
        }

        bool leftAns=evaluateTree(root->left);
        bool rightAns=evaluateTree(root->right);
        if(root->val==2){
            return leftAns||rightAns;
        }
        if(root->val==3){
            return leftAns && rightAns;
        }




        return leftAns||rightAns;
        
    }
};