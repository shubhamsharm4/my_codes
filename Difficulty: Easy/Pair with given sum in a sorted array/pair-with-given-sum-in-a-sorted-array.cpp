//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        int N = arr.size();
        int cnt = 0;
        int l = 0, r = N-1;
        
        while(l < r) {
            int s = arr[l] + arr[r];
        
            if(s < target) l++;
            else if(s > target) r--;
            
            else {
                int cnt1 = 0, cnt2 = 0; 
                int ele1 = arr[l], ele2 = arr[r];
                
                while(l <= r && arr[l] == ele1) l++, cnt1++;
                while(l <= r && arr[r] == ele2) r--, cnt2++;
                
                if(ele1 == ele2) {
                    cnt += (cnt1 * (cnt1-1)) / 2;
                }
                else cnt += cnt1 * cnt2;
            }   
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
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends