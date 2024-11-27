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
    void rightView(TreeNode* root, vector<int> &ans, int lvl){
        // base case
        if(root == NULL) return;

        // entered a new level, so har level ka rightmost store to see rightview
        if(ans.size() == lvl)
            ans.push_back(root->val);

        rightView(root->right, ans, lvl+1);
        rightView(root->left, ans, lvl+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        rightView(root, ans, 0);
        return ans;
    }
};