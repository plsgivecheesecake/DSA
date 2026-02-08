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
    pair<bool, int> maxDepth(TreeNode* node, int height) {
        if (!node) return {true, height};
        pair<bool, int> left = maxDepth(node->left, height + 1);
        pair<bool, int> right = maxDepth(node->right, height + 1);
        return {
            left.first && right.first && std::abs(left.second - right.second) <= 1,
            std::max(left.second, right.second)
        };
    }
    bool isBalanced(TreeNode* root) {
        pair<bool, int> result = maxDepth(root, 0);
        return result.first;
    }
};