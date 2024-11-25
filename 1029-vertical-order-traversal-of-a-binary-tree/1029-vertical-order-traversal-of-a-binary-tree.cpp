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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int , vector<int> > > nodes;
        queue< pair<TreeNode* , pair<int , int> > > q;
        vector< vector<int> >  ans;

        if(root == NULL) return ans;

        q.push(make_pair(root, make_pair(0,1)));

        while(!q.empty()){
            pair<TreeNode*, pair<int,int> > temp = q.front();
            q.pop();

             TreeNode* frontNode = temp.first;
            int hd = temp.second.first;  // Horizontal distance
            int lvl = temp.second.second; // Level

            // Store the current node value in the map at hd and lvl
            nodes[hd][lvl].push_back(frontNode->val);

            // If left child exists, push it into the queue with updated hd and level
            if (frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd - 1, lvl + 1)));

            // If right child exists, push it into the queue with updated hd and level
            if (frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd + 1, lvl + 1)));
        }

        // Loop through horizontal distances
        for (auto i : nodes) {
            vector<int> temp; // Temporary vector for this horizontal distance

            // Loop through levels in this horizontal distance
            for (auto j : i.second) {
                // Sort nodes at the same level for consistent output
                sort(j.second.begin(), j.second.end());
                temp.insert(temp.end(), j.second.begin(), j.second.end());
            }

            // Add the collected nodes for this horizontal distance to the result
            ans.push_back(temp);
        }

        return ans;
    }
};