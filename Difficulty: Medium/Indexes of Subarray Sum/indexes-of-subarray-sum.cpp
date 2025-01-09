//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int N = arr.size();
        vector<int> res;
        
        int sum = 0, l = 0, r = 0;
        
        while(r < N) {
            sum += arr[r];
            
            while(sum > target && l <= r) {
                sum -= arr[l];
                l++;
            }
            
            if(sum == target) {
                res.push_back(l+1);
                res.push_back(r+1);
                break;
            }
            
            r++;
        }
        
        return res.empty() ? vector<int>{-1} : res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends