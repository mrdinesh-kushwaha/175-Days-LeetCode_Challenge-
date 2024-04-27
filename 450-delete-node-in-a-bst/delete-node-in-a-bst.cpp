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
    int maxVal(TreeNode* root){
     
     if(root==NULL)
     return -1;

     TreeNode* temp=root;
     while(temp->right!=NULL){
        temp=temp->right;
     }
     return temp->val;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
    if(root==NULL)
    return NULL;

    if(root->val==key){
        // 4 cases of deletion:

        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        else if(root->left!=NULL && root->right==NULL){
            TreeNode* child=root->left;
            delete root;
            return child;
        }

        else if(root->left==NULL && root->right!=NULL){
            TreeNode* child=root->right;
            delete root;
            return child;
        }

        else { // means both child exits

            int inOrderPredeccessor=maxVal(root->left);

            root->val=inOrderPredeccessor;

            root->left=deleteNode(root->left,inOrderPredeccessor);

            return root;

        }
    }

    else if(root->val >key){
        root->left=deleteNode(root->left,key);
    }

    else if(root->val <key){
        root->right =deleteNode(root->right,key);
    }
    return root;      
    }
};