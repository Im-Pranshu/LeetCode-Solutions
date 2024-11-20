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
private: 
    void preOrder(TreeNode* root, vector<int> &preorder){
        if(root == NULL)
            return;
        
        // NLR
        preorder.push_back(root->val);
        preOrder(root->left, preorder);
        preOrder(root->right, preorder);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;

        preOrder(root,preorder);

        return preorder;
    }
};