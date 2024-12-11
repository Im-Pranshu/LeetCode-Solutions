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
    TreeNode* search(TreeNode* root, int val) {
    // Base case
    if(root == NULL || root->val == val) {
        return root; // Return root if NULL or value matches.
    }

    // Recursively search left or right subtree based on comparison.
    return (val < root->val) ? search(root->left, val) : search(root->right, val);
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        // Wrapper function that calls the recursive `search` function.
        // Returns the result of the search for the target value in the BST.
        return search(root, val);
    }

};