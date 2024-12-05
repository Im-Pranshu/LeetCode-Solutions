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
    // mapping values of inorder in map with index
    void createMapping(map<int,int> & mp, vector<int> in, int n){
        for(int i=0; i<n; i++){
            mp[in[i]] = i;
        }
    }

    
    TreeNode* solve(vector<int> inorder, vector<int> preorder, int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> & nodeToIndex){
        // base case
        if(index >= n || inOrderStart > inOrderEnd) {
            return NULL;
        }
        
        // access element and create new node
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        
        int position = nodeToIndex[element];
        // int position = findPosition(inorder, element, inOrderStart, inOrderEnd);

        
        // traverse left and right
        root->left = solve(inorder, preorder, index, inOrderStart, position-1, n, nodeToIndex);
        root->right = solve(inorder, preorder, index, position+1, inOrderEnd, n, nodeToIndex);
        
        return root;
    }   

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderIndex = 0;// this will keep the track of the preorder.

        int n = inorder.size();

        map<int, int> nodeToIndex;
        // create mapping of preorder values with their index
        createMapping(nodeToIndex, inorder, n);

        // create tree with in and pre order
        TreeNode* root = solve(inorder, preorder, preOrderIndex , 0 , n-1, n , nodeToIndex);
        return root;
    }
};