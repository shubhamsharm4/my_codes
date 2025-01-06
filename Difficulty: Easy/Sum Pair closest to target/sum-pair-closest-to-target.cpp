//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int N = arr.size(); 
        vector<int> res;
        
        sort(arr.begin(), arr.end());
        int minDiff = INT_MAX;
        
        int l = 0, r = N-1;
        while(l < r) {
            int s = arr[l] + arr[r];
            
            if(abs(s - target) < minDiff) {
                minDiff = abs(s - target);
                res = {arr[l], arr[r]};
            }
            
            if(s < target) l++;
            else if(s > target) r--;
            else return res; 
        }
        
        return res; 
        
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends