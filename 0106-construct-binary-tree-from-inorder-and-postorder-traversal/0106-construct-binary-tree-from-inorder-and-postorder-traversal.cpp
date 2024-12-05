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

    TreeNode* solve(vector<int> inorder, vector<int> postorder, int &index, int inOrderStart, int inOrderEnd, int n, map<int,int> & nodeToIndex){
        // base case
        if(index < 0 || inOrderStart > inOrderEnd) {
            return NULL;
        }
        
        // access element and create new node
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        
        int position = nodeToIndex[element];
        
        // traverse right and left
        root->right = solve(inorder, postorder, index, position+1, inOrderEnd, n, nodeToIndex);
        root->left = solve(inorder, postorder, index, inOrderStart, position-1, n, nodeToIndex);
        
        return root;
    } 

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        
        int postOrderIndex = n-1;// this will keep the track of the postorder index

        map<int, int> nodeToIndex;
        // create mapping of postorder values with their index
        createMapping(nodeToIndex, inorder, n);

        // create tree with in and post order
        TreeNode* root = solve(inorder, postorder, postOrderIndex , 0 , n-1, n , nodeToIndex);
        return root; 
    }
};