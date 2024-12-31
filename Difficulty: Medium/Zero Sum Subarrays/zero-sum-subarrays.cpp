//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        int k = 0;
        unordered_map<int,int> mp;
        int cnt = 0, prefix = 0;
        
        for(int i : arr) {
            prefix += i;
            if(prefix == k) cnt++;
            if(mp.find(prefix - k) != mp.end()) {
                cnt += mp[prefix - k];
            }
            mp[prefix]++;
        }
        
        return cnt; 
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.findSubarray(arr) << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends