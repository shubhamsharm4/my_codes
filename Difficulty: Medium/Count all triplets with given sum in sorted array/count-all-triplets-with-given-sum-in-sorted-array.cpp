//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int N = arr.size();
        int res = 0;
    
        for (int i = 0; i < N - 2; ++i) {
            int j = i + 1, k = N - 1;
    
            while (j < k) {
                int s = arr[i] + arr[j] + arr[k];
    
                if (s < target) j++;
                else if (s > target) k--;
                else if (s == target) {
                    int ele1 = arr[j], ele2 = arr[k];
                    int cnt1 = 0, cnt2 = 0;
    
                    while (j <= k && arr[j] == ele1) {
                        j++, cnt1++;
                    }
                    while (j <= k && arr[k] == ele2) {
                        k--, cnt2++;
                    }
    
                    if (ele1 == ele2) res += (cnt1 * (cnt1 - 1)) / 2;  
    
                    else res += cnt1 * cnt2;
                }
            }
        }
    
        return res;
    }

};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends