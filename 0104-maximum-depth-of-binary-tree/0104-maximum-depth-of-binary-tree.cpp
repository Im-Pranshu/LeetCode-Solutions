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

    int height(TreeNode* root){
        // yani leaf node ka child
        if(root == NULL) return 0;

        // left jate jao 
        int left = height(root->left);
        // fir right jate jao
        int right = height(root->right);

        // left+right+1 karke particular node ki height nikal lo
        int ans = max(left,right) + 1;
        return ans;
    }

    int maxDepth(TreeNode* root) {
        return height(root);
    }
};