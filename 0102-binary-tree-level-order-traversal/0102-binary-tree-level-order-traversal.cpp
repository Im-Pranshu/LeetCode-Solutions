/*
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        // if tree is empty
        if(root == NULL)
            return {};
        
        vector<vector<int>> result;
        
        // queue will store the data of one level
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size = q.size();
            // data of queue will be stored and it'll get empty to store data of next level
            vector<int> oneIteration(size);

            // processing the level by tranfering data of each level in queue
            for(int i=0; i<size; i++){
                TreeNode* temp = q.front();
                q.pop();

                oneIteration[i] = temp->val;

                // if left is not NULL
                if (temp->left){
                    q.push(temp->left);
                }
                
                // if right is not NULL
                if (temp->right){
                    q.push(temp->right);
                }
            }

            // store current iteration ans in result
            result.push_back(oneIteration);

        }

        return result;
    }
};