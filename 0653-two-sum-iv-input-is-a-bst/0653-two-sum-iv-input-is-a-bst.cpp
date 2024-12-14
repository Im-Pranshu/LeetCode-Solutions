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
    void in(TreeNode* root, vector<int> &ino){
        // base case
        if(root == NULL){
            return;
        }

        // L
        in(root->left,ino);
        // N
        ino.push_back(root->val);
        // R
        in(root->right, ino);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int> inorder;
        in(root,inorder);
        int n = inorder.size();

        // two pointer approach
    int s=0, e=inorder.size()-1;
    int mid = s + (e-s)/2;
    
        while(s<e){
            int sum = inorder[s]+inorder[e];
            // found the nodes
            if(sum == k){
                return true;
            }
            else if(sum < k){
                s++;
            }
            else{
                e--;
            }
        }

        return false;
    }
};