/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        while(temp != NULL){
            // LCA exist in right
            if(temp->val < p->val && temp->val < q->val){
                temp = temp->right;
            }
            // LCA exist in left
            else if(temp->val > p->val && temp->val > q->val){
                temp = temp->left;
            }
            else{ // currrent node is LCA
                // two case
                // 1. a and b lies of different side left and right
                            // or
                // 2. a or b == current node , so either a or b is LCA of itself.
                return temp;
            }
        }
        // LCA not exist
        return NULL;
    }
};