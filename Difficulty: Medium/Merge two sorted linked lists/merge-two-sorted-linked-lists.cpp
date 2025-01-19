//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << "\n~\n";
}

Node *insertSorted(Node *head, int data) {
    Node *new_node = new Node(data);
    if (!head || head->data >= data) {
        new_node->next = head;
        return new_node;
    }

    Node *current = head;
    while (current->next && current->next->data < data) {
        current = current->next;
    }
    new_node->next = current->next;
    current->next = new_node;
    return head;
}


// } Driver Code Ends
class Solution {
  public:
    Node* sortedMerge(Node* head1, Node* head2) {
        Node* t1 = head1;
        Node* t2 = head2;
        
        Node* dummy = new Node(-1);
        Node* newhead = dummy;
        
        while(t1 && t2) {
            if(t1 -> data > t2 -> data) {
                Node* newnode = new Node(t2 -> data);
                newhead -> next = newnode;
                newhead = newhead -> next; 
                t2 = t2 -> next;
            }
            else {
                Node* newnode = new Node(t1 -> data);
                newhead -> next = newnode;
                newhead = newhead -> next; 
                t1 = t1 -> next;
            }
        }
        
        while(t1) {
            Node* newnode = new Node(t1 -> data);
            newhead -> next = newnode;
            newhead = newhead -> next; 
            t1 = t1 -> next;
        }
        
        while(t2) {
            Node* newnode = new Node(t2 -> data);
            newhead -> next = newnode;
            newhead = newhead -> next; 
            t2 = t2 -> next;
        }
        
        return dummy -> next;
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *head2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            head1 = insertSorted(head1, tmp);
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            head2 = insertSorted(head2, tmp);
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends