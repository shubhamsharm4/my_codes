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
    stack<int>st;
    vector<int> res;    
    void helper(TreeNode* node) {
        if(node == nullptr) return;
        st.push(node -> val);
        helper(node -> right);
        helper(node -> left);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return res;
        helper(root);
        while(!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res; 
    }
};