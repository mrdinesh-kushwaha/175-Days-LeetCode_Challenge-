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

long long LevelSum(TreeNode* root, int k) {
    queue<TreeNode*> q;
    q.push(root);

    vector<long long> lvlSum;

    while (!q.empty()) {
        long long lvl_sum = 0;
        long long qsize = q.size();
        for (long long i = 0; i < qsize; i++) {
            TreeNode* currNode = q.front();
            q.pop();

            lvl_sum += currNode->val;

            if (currNode->left != NULL)
                q.push(currNode->left);
            if (currNode->right != NULL)
                q.push(currNode->right);
        }

        lvlSum.push_back(lvl_sum);
    }

    sort(rbegin(lvlSum), rend(lvlSum));

    if (lvlSum.size() < k) return -1;

    return lvlSum[k - 1];
}

long long kthLargestLevelSum(TreeNode* root, int k) {
    return LevelSum(root, k);
   }
};