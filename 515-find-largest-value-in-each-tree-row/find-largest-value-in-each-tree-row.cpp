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

    vector<int> levelOrder(TreeNode* &root,vector<int>&ans){
        if(root==NULL)
        return ans;

        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int temp=INT_MIN; // for find maxi value:::
        while(!q.empty()){
            TreeNode* frontNode=q.front();
            q.pop();

            if(frontNode==NULL){
                if(!q.empty()){ // last val maxi element nhi aayega bcz vaha pr q empty ho jayega
                    q.push(NULL);
                    ans.push_back(temp);
                    temp=INT_MIN;
                }
            }

            else{
                temp=max(temp,frontNode->val);

                if(frontNode->left)
                q.push(frontNode->left);

                if(frontNode->right)
                q.push(frontNode->right);
            }
        }
        ans.push_back(temp);
        return ans;
    }
    vector<int> largestValues(TreeNode* root) {

        vector<int>ans;
        return levelOrder(root,ans);
        
    }
};