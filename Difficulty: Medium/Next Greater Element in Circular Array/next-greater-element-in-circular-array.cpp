//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> res(n, -1);
        
        int i = 0;
        while(i < n) {
            int j = (i + 1) % n;
            while(j != i) {
                if(arr[j] > arr[i]) {
                    res[i] = arr[j];
                    break;
                }
                j = (j + 1) % n;
            }
            i++;
        }
    
        return res; 
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    
cout << "~" << "\n";
}
	return 0;
}

// } Driver Code Ends