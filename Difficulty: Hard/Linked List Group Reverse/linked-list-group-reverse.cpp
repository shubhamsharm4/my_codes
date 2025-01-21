//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* Function to print linked list */
void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
class Solution {
  public:
    Node* helper(Node* head) {
        if(!head) return nullptr;
        Node* curr = head;
        Node* prev = nullptr;
        Node* front = nullptr;
        
        while(curr) {
            front = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = front;
        }
        
        return prev;
    }

    Node *reverseKGroup(Node *head, int k) {
        if(!head || k <= 1) return head;
        Node* t = head;
        int N = 1;
        
        while(t -> next) {
            t = t -> next;
            N += 1;
        }
        
        Node* dummy = new Node(-1);
        Node* newhead = dummy;
        
        t = head;
        for(int i = 0; i + k < N; i += k) {
            Node* temp = new Node(-1);
            Node* tempH = temp;
            
            for(int j = 0; j < k; ++j) {
                Node* newnode = new Node(t -> data);
                tempH -> next = newnode;
                tempH = tempH -> next;
                t = t -> next;
            }
            
            temp -> next = helper(temp -> next);
            newhead -> next = temp -> next;
            while(newhead -> next) newhead = newhead -> next;
        }
        
        if(t) {
            Node* temp = new Node(-1);
            Node* tHead = temp;
            
            while(t) {
                Node* newnode = new Node(t -> data);
                tHead -> next = newnode;
                tHead = tHead -> next;
                t = t -> next;
            }
            temp -> next = helper(temp -> next);
            newhead -> next = temp -> next;
        }
        
        return dummy -> next; 
    }
};


//{ Driver Code Starts.

/* Driver program to test above function*/
int main(void) {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        Node* head = new Node(data);
        Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.reverseKGroup(head, k);
        printList(head);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends