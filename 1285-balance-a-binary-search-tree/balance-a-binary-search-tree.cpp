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
    // Helper function to perform in-order traversal and store values in a vector
    void inOrderTraversal(TreeNode* root, vector<int>& vals) {
        if (root == NULL) return;
        inOrderTraversal(root->left, vals);
        vals.push_back(root->val);
        inOrderTraversal(root->right, vals);
    }

    // Helper function to construct a balanced BST from sorted values
    TreeNode* constructBalancedBST(vector<int>& vals, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left = constructBalancedBST(vals, start, mid - 1);
        node->right = constructBalancedBST(vals, mid + 1, end);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inOrderTraversal(root, vals); // Collect values in sorted order
        return constructBalancedBST(vals, 0, vals.size() - 1); // Construct balanced BST
    }

};