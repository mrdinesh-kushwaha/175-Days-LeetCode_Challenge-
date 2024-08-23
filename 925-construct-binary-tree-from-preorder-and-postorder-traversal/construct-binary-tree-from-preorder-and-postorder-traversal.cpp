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
    int position(vector<int>& postorder,int ele,int postStart,int postEnd){

        for(int i= postStart;i<=postEnd;i++){
            if(postorder[i]==ele) return i;
        }
        return -1;
    }

    TreeNode* createTree(vector<int>& preorder,vector<int>& postorder,int& preIndex,int postorderStart,int postorderEnd){

        //base case:
        if(preIndex >= preorder.size() || postorderStart > postorderEnd) return NULL;

        int ele= preorder[preIndex++];
        TreeNode* root= new TreeNode(ele);

        if(postorderStart==postorderEnd) return root;

        int nextele= preorder[preIndex];
        int pos= position(postorder,nextele,postorderStart,postorderEnd);

        root->left= createTree(preorder,postorder,preIndex,postorderStart,pos);
        root->right= createTree(preorder,postorder,preIndex,pos+1,postorderEnd-1);

        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int preIndex=0;
        int postorderStart=0;
        int postorderEnd=postorder.size()-1;

        TreeNode* root= createTree(preorder,postorder,preIndex,postorderStart,postorderEnd);

        return root;
    }
};