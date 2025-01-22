//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
class Solution {
  public:
    Node* revNodes(Node* head) {
        Node* curr = head, *prev = nullptr, *front = nullptr;
        
        while(curr) {
            front = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
    
    Node* addTwoLists(Node* num1, Node* num2) {
        Node* t1 = num1;
        while(t1 -> data == 0) t1 = t1 -> next;
        
        Node* t2 = num2;
        while(t2 -> data == 0) t2 = t2 -> next;
    
        t1 = revNodes(t1);
        t2 = revNodes(t2);
        
        Node* dummy = new Node(-1);
        Node* newhead = dummy;
        
        int carry = 0;
        while(t1 && t2) {
            int value = t1 -> data + t2 -> data + carry;
            int sum = value % 10;
            carry = value / 10;
            
            Node* newnode = new Node(sum);
            newhead -> next = newnode;
            newhead = newhead -> next;
            
            t1 = t1 -> next;
            t2 = t2 -> next;
        }
        
        if(t1) {
            while(t1) {
                int value = t1 -> data + carry;
                int sum = value % 10;
                carry = value / 10; 
                
                Node* newnode = new Node(sum);
                newhead -> next = newnode;
                newhead = newhead -> next;
                
                t1 = t1 -> next;
            }
        }
        
        if(t2) {
            while(t2) {
                int value = t2 -> data + carry;
                int sum = value % 10;
                carry = value / 10; 
                
                Node* newnode = new Node(sum);
                newhead -> next = newnode;
                newhead = newhead -> next;
                
                t2 = t2 -> next;
            }
        }
        
        if(carry > 0) {
            Node* newnode = new Node(carry);
            newhead -> next = newnode;
            newhead = newhead -> next;
        }
        
        return revNodes(dummy -> next); 
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends