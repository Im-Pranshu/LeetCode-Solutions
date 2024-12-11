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
    // Base case: If the root is NULL, the value is not found in the BST.
    if(root == NULL) return NULL;

    // If the current node's value matches the target value, return the current node.
    if(root->val == val) {
        return root;
    }

    // If the target value is smaller than the current node's value,
    // recursively search in the left subtree (as per BST properties).
    if(root->val > val) {
        return search(root->left, val);
    }
    else {
        // If the target value is greater than the current node's value,
        // recursively search in the right subtree (as per BST properties).
        return search(root->right, val);
    }
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        // Wrapper function that calls the recursive `search` function.
        // Returns the result of the search for the target value in the BST.
        return search(root, val);
    }

};