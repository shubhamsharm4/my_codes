//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<
            pair<int,vector<int>>, 
            vector<pair<int,vector<int>>>, 
            greater<pair<int,vector<int>>>
        >pq;
        
        int x0 = 0, y0 = 0;
        for(auto it : points) {
            int x1 = it[0], y1 = it[1];
            int d = (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0);
            pq.push({d, it});
        }
        
        vector<vector<int>> res; 
        while(k > 0) {
            res.push_back(pq.top().second);
            pq.pop();
            k--; 
        }
        
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        int n;
        cin >> n;
        vector<vector<int>> points(n, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> points[i][0] >> points[i][1];
        }
        Solution ob;
        vector<vector<int>> ans = ob.kClosest(points, k);
        sort(ans.begin(), ans.end());
        for (const vector<int>& point : ans) {
            cout << point[0] << " " << point[1] << endl;
        }
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends