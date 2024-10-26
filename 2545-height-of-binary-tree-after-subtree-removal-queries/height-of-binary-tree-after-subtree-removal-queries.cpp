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
    unordered_map<int,int> heightofnode;
    unordered_map<int,int> level;
    unordered_map<int,pair<int,int>> max2height;
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        int heightt = max(left,right)+1;
        heightofnode[root->val]=heightt;
        return heightt;
    }
     
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
       int ans1 = height(root);
        queue<TreeNode*> q;
        q.push(root);
        int j = 0;
        while(!q.empty()){
            int size = q.size();
            priority_queue<int> maxheap;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                int temp = heightofnode[node->val];
                maxheap.push(temp);
                level[node->val]=j;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            int maxheight = maxheap.top();
            maxheap.pop();
            if(!maxheap.empty()){
            int secondmaxheight = maxheap.top();
            max2height[j]=make_pair(maxheight,secondmaxheight);
            }
            else{
                max2height[j]=make_pair(maxheight,-1);
            }

            j++;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int node = queries[i];
            int levelofnode = level[node];
            int maxheightfromthatlevel;
            if(max2height[levelofnode].second != -1){
                if(max2height[levelofnode].first == heightofnode[node]){
                    maxheightfromthatlevel = max2height[levelofnode].second ;
                }
                else{
                     maxheightfromthatlevel = max2height[levelofnode].first ;
                }
            }
            else{
                if(max2height[levelofnode].first == heightofnode[node]){
                    maxheightfromthatlevel = 0;
                }
            }
            int temp = maxheightfromthatlevel + (levelofnode - 1);
            ans.push_back(temp);
        }
        return ans;
    }
};