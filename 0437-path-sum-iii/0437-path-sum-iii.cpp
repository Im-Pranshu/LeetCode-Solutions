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
    void findPaths(TreeNode* root, int targetSum , int &nPaths, vector<int> path){
        // base case
        if(root == NULL) return;

        path.push_back(root->val);

        // left traverse
        findPaths(root->left, targetSum, nPaths, path);
        // rigth traverse
        findPaths(root->right, targetSum, nPaths, path);

        // check if sum == targetSum then count
        int size = path.size();
        long long sum = 0;
        for(int i = size-1; i>=0; i--){
            sum += path[i];
            if(sum == targetSum)
                nPaths++;
        }
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        vector<int> path;
        int noOfPaths = 0;

        findPaths(root, targetSum , noOfPaths, path);

        return noOfPaths;
    }
};