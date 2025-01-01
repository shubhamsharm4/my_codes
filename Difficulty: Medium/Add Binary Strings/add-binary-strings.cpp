//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string res = "";
        
        int idx = 0;
        while(idx < s1.length() && s1[idx] != '1') idx++;
        s1 = s1.substr(idx);
        
        idx = 0;
        while(idx < s2.length() && s2[idx] != '1') idx++;
        s2 = s2.substr(idx);
        
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
    
        int carry = 0;
        int i = 0, j = 0;
    
        while (i < s1.length() && j < s2.length()) {
            int sum = (s1[i] - '0') + (s2[j] - '0') + carry;
            res += to_string(sum % 2); 
            carry = sum / 2;      
            i++, j++;
        }
    
        while (i < s1.length()) {
            int sum = (s1[i] - '0') + carry;
            res += to_string(sum % 2);
            carry = sum / 2;
            i++;
        }
    
        while (j < s2.length()) {
            int sum = (s2[j] - '0') + carry;
            res += to_string(sum % 2);
            carry = sum / 2;
            j++;
        }
    
        if (carry > 0) res += '1';
    
        reverse(res.begin(), res.end());
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends