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
int LevelSum(TreeNode* root){

    queue<TreeNode*>q;
    q.push(root);

    vector<int>lvlSum;

    int lvl;

    while(!q.empty()){
        int lvl_sum=0;
        int qsize=q.size();
        for(int i=0;i<qsize;i++){
            TreeNode* currNode = q.front();
            q.pop();

            lvl_sum+=currNode->val;

            if(currNode->left!=NULL)
            q.push(currNode->left);
            if(currNode->right!=NULL)
            q.push(currNode->right);
        }

       lvlSum.push_back(lvl_sum);
    }

    auto maxSum=max_element(lvlSum.begin(),lvlSum.end()); //return the max element in vector:

    lvl=distance(lvlSum.begin(),maxSum)+1; // return index:

    return lvl;

}
    int maxLevelSum(TreeNode* root) {

        return LevelSum(root);
        
    }
};