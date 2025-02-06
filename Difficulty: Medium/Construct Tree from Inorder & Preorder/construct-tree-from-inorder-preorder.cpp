//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    Node* helper(unordered_map<int,int>& mp, vector<int>& preorder, int& index, int left, int right) {
        if(left > right) return nullptr;
        
        int rootVal = preorder[index];
        index++;
        
        Node* root = new Node(rootVal);
        
        int i = mp[rootVal];
        
        root -> left = helper(mp, preorder, index, left, i - 1);
        root -> right = helper(mp, preorder, index, i + 1,  right);
        
        return root; 
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); ++i) mp[inorder[i]] = i;
        
        int index = 0;
        return helper(mp, preorder, index, 0, inorder.size() - 1);
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends