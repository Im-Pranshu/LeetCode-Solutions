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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL)
            return result;
            
        // applying level order traversal
        queue<TreeNode* > q;
        q.push(root);
        
        bool leftToRight = true;// flag to flip the direction to make zigZag motion
        
        // traverse till q is not empty
        while(!q.empty()){
            int size = q.size();
            
            // vector to store result of 1 level
            vector<int> ans(size);
            
            // level process, extracting values.
            for(int i = 0; i<size; i++){
                TreeNode* frontNode = q.front();
                q.pop();
                
                int index = leftToRight ? i : size - i -1;
                ans[index] = frontNode->val;
                
                if(frontNode->left)
                    q.push(frontNode->left);
                
                if(frontNode->right)
                    q.push(frontNode->right);
            }
            
            
            // store current iteration ans in result
            result.push_back(ans);
            
            // change direction of flow
            leftToRight = !leftToRight;
        }
        
        return result;
    }
};