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
    int helper(vector<int>& arr) {
        int swaps = 0; 
        unordered_map<int,int> m1;
        for(int i = 0; i < arr.size(); ++i) {
            m1[arr[i]] = i;
        }

        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        for(int i = 0; i < arr.size(); ++i) {
            if(arr[i] != temp[i]) {
                swaps += 1;

                int currIdx = m1[temp[i]];
                m1[arr[i]] = currIdx;
                swap(arr[currIdx], arr[i]);
            }
        }

        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        int ops = 0;
        if(root == nullptr) return ops;
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> arr;
            for(int i = 0; i < size; ++i) {
                TreeNode* temp = q.front();
                q.pop(); 
                if(temp -> left) q.push(temp -> left); 
                if(temp -> right) q.push(temp -> right);
                arr.push_back(temp -> val);
            }
            ops += helper(arr); 
        }
        return ops;
    }
};