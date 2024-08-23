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
int position(vector<int>&inorder,int ele){
    for(int i=0;i<inorder.size();i++){
        if(inorder[i]==ele) return i;
    }
    return -1;
}

TreeNode* createTree(vector<int>& inorder, vector<int>& postorder,int& postIndex,int inStartIndex,int inEndIndex){

    if(postIndex < 0 || inStartIndex > inEndIndex) return NULL;

    int ele= postorder[postIndex--];
    TreeNode* root= new TreeNode(ele);
    int pos = position(inorder,ele);

    root->right=createTree(inorder,postorder,postIndex,pos+1,inEndIndex);

    root->left= createTree(inorder,postorder,postIndex,inStartIndex,pos-1);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        int postIndex=postorder.size()-1;
        int inIndexEnd=inorder.size()-1;
        TreeNode* root= createTree(inorder,postorder,postIndex,0,inIndexEnd);

        return root;
     }
};