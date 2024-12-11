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
    int find(TreeNode* root, int k , int &i){
        if (root == NULL) return -1;

        // L - Traverse left
        int left = find(root->left, k , i);

        if(left!= -1){
            return left;
        }

        // N - process node
        i++;
        if(i == k)
            return root->val;

        // R - traverse right and continue
        return find(root->right, k ,i);
    }
    int kthSmallest(TreeNode* root, int k) {
        int i = 0;// counter of the node
        // traverse in order and get kth smallest in kth node visit
        return find(root, k , i);
    }
};