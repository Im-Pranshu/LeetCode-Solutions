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
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        // flatten BTree into LL
        while(curr != NULL){
            if(curr->left){
                // find predecessor
                TreeNode* pred = curr->left;
                while(pred->right)
                    pred = pred->right;

                // flatten current node and pred node.
                pred->right = curr->right;
                curr->right = curr->left;

                // break link of curr left
                curr->left = NULL;
            }
            else{
                // next node pe jao
                curr = curr->right;
            }
        }
    }
};