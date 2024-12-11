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
    TreeNode* searchBST(TreeNode* root, int val) {
        // iterative approach
        TreeNode* temp = root;
        // search for the value
        while(temp != NULL){
            // val found
            if(temp->val == val) return temp;
            else if(temp->val < val) temp = temp->right;
            else temp = temp->left;
        }
        // not found val
        return NULL;
    }
};