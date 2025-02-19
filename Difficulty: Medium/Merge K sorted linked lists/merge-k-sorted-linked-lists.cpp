//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print nodes in a given linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    Node* mergeKLists(vector<Node*>& arr) {
        int N = arr.size();
        
        Node* dummy = new Node(-1);
        Node* head = dummy;
        
        //make n-sorted list into one list
        for(int i = 0; i < N; ++i) {
            Node* currH = arr[i];
            while(currH) {
                head -> next = currH;
                head = head -> next;
                currH = currH -> next;
            }
        }
        
        //now question boils down to sort the list
        //there are 2 ways to do it : transfer it into an array or
        //or do it using merge sort 
        
        vector<int> temp;
        Node* t = dummy -> next;
        while(t) {
            temp.push_back(t -> data);
            t = t -> next;
        }
        
        sort(temp.begin(), temp.end());
        
        Node* newDummy = new Node(-1);
        Node* resHead = newDummy;
        
        for(int i = 0; i < temp.size(); ++i) {
            Node* newnode = new Node(temp[i]);
            resHead -> next = newnode;
            resHead = resHead -> next; 
        }
        
        return newDummy -> next; 
    }
};


//{ Driver Code Starts.

// Driver program to test the above functions
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();

        vector<Node*> v(n);

        for (int i = 0; i < n; i++) {
            string line;
            getline(cin, line);
            stringstream ss(line);

            Node* head = new Node(0);
            Node* temp = head;
            int x;
            while (ss >> x) {
                Node* newNode = new Node(x);
                temp->next = newNode;
                temp = temp->next;
            }
            v[i] = head->next;
        }

        Solution ob;
        Node* head = ob.mergeKLists(v);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends