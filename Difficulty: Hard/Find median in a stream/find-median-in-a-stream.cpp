//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> res; 
        priority_queue<int> maxHeap; //store smaller elements;
        priority_queue<int, vector<int>, greater<int>> minHeap; //store larger ele
        
        for(int i : arr) {
            if(minHeap.empty() || i < maxHeap.top()) {
                maxHeap.push(i);
            }
            else minHeap.push(i);
        
            if(maxHeap.size() > minHeap.size() + 1) { //+ 1 for the odd size
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else if(minHeap.size() > maxHeap.size()) {
                maxHeap.push(minHeap.top()); 
                minHeap.pop();
            }
            
            if(maxHeap.size() > minHeap.size()) {
                res.push_back(maxHeap.top());
            } else {
                res.push_back((maxHeap.top() + minHeap.top()) / 2.0);
            }
        }
        return res; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends