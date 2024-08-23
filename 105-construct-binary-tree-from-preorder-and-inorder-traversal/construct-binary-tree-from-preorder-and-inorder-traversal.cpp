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
    int position(vector<int>&postorder,int ele){
        for(int i=0;i<postorder.size();i++){
            if(postorder[i]==ele) return i;
        }
        return -1;
    }
    TreeNode* createTree(vector<int>& preorder,vector<int>& postorder,int& preIndex,int postStart,int postEnd){
        if(preIndex >= preorder.size()||postStart>postEnd) return NULL;

        int ele= preorder[preIndex++];
        TreeNode* root= new TreeNode(ele);
        int pos = position(postorder,ele);

        root->left= createTree(preorder,postorder,preIndex,postStart,pos-1);
        root->right= createTree(preorder,postorder,preIndex,pos+1,postEnd);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        int preIndex=0;
    return createTree(preorder,inorder,preIndex,0,inorder.size()-1);
    }
};