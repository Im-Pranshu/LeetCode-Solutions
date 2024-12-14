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
    void inOrder(TreeNode* root, vector<int> &in){
        // base case
        if(root == NULL){
            return;
        }

        // L
        inOrder(root->left,in);
        // N
        in.push_back(root->val);
        // R
        inOrder(root->right, in);
    }

// convert inorder to Balanced BST
    TreeNode* inorderToBST(vector<int> &in, int s, int e){
        // base case: All nodes are traversed.
        if(s>e) return NULL;
        int mid = s+(e-s)/2;

        // create new node
        TreeNode* newRoot = new TreeNode(in[mid]);
        // attach all smaller node than mid to left
        newRoot->left = inorderToBST(in, s, mid-1);
        // attach all larger node than mid to right
        newRoot->right = inorderToBST(in, mid+1, e);

        return newRoot;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        inOrder(root, inorder);
        int n = inorder.size();

        // return the new root of the Balanced BST
        return inorderToBST(inorder, 0, n-1);
    }
};