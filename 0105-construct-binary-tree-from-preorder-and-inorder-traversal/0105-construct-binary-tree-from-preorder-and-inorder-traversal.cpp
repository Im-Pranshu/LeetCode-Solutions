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

    int findPosition(vector<int> &inorder, int element, int inOrderStart, int inOrderEnd) {
        // int idx;
        for (int i = inOrderStart; i <= inOrderEnd; i++) {
            if (inorder[i] == element) {
                return i;
            }
        }
        return -1; // Element not found (should not happen in a valid input)
    }

    
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int &index, int inOrderStart, int inOrderEnd, int n){
        // base case
        if(index >= n || inOrderStart > inOrderEnd) {
            return NULL;
        }
        
        // access element and create new node
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        
        // int position = findPosition(inorder, element, n);
        int position = findPosition(inorder, element, inOrderStart, inOrderEnd);

        
        root->left = solve(inorder, preorder, index, inOrderStart, position-1, n);
        root->right = solve(inorder, preorder, index, position+1, inOrderEnd, n);
        
        return root;
    }   

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;
        int n = inorder.size();
        TreeNode* root = solve(inorder, preorder, preOrderIndex , 0 , n-1, n );
        return root;
    }
};