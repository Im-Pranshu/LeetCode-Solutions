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
    TreeNode* maxVal(TreeNode* root){
        if(root==NULL) return NULL;
        TreeNode* temp = root;
        while(temp->right!=NULL){
            temp = temp->right;
        }
        return temp;
    }

    TreeNode* solve(TreeNode* root, int key){
        // base case
        if(root == NULL)
            return root;

        if(root->val == key){
            // 0 child
            if(root->left == NULL && root->right == NULL){
                delete root;
                return NULL;
            }
            // 1 child
            // left child
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp = root->left;
                delete root;
                return temp;
            }
            // right child
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp = root->right;
                delete root;
                return temp;
            }

            // 2 child
            if(root->left!=NULL && root->right!=NULL){
                int maxi = maxVal(root->left) -> val;
                root->val = maxi;
                root->left = solve(root->left, maxi);
                return root;
            }
        }
        else if(root->val > key){
            // left jao waha hai value
            root->left =  solve(root->left,key);
        }
        else{
            // right jao waha hai value
            root->right = solve(root->right, key);
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        return solve(root,key);
    }
};