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
    void postOrder(TreeNode* root, vector<int> &postorder){
        if(root == NULL) return;

        // LRN
        postOrder(root->left, postorder);
        postOrder(root->right, postorder);
        postorder.push_back(root->val);

    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;

        postOrder(root, postorder);

        return postorder;
    }
};