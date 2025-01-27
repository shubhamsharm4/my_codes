//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class LRUCache {
  private:
    struct Node {
        int key;    
        int val;
        Node* next;
        Node* prev;
        
        Node(int key, int val) {
            this -> key = key;
            this -> val = val;
            next = nullptr;
            prev = nullptr;
        }
    };
    
  public:
    int size;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
    
    LRUCache(int cap) {
        this -> size = cap;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head -> next = tail;
        tail -> prev = head;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        
        else {
            Node* node = mp[key];
            remove(node);
            add(node);
            return node -> val;
        }
    }

    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            Node* oldNode = mp[key];
            remove(oldNode);
        }   
        
        Node* newnode = new Node(key, value); 
        mp[key] = newnode;
        add(newnode);
        
        if(mp.size() > size) {
            Node* toDel = tail -> prev; 
            remove(toDel);
            mp.erase(toDel -> key);
        }
    }
    
    void add(Node* node) {
        Node* nextNode = head -> next;
        head -> next = node;
        node -> prev = head;
        node -> next = nextNode;
        nextNode -> prev = node;
    }
    
    void remove(Node* node) {
        Node* nextNode = node -> next;
        Node* prevNode = node -> prev;
        prevNode -> next = nextNode;
        nextNode -> prev = prevNode;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends