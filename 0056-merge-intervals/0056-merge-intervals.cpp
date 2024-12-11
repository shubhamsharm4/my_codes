class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        vector<vector<int>>res;
        
        sort(arr.begin(), arr.end());
        
        for(int i = 0; i < n; ++i) {
            int start = arr[i][0], end = arr[i][1];
            if(!res.empty() && res.back()[1] >= end) continue;
            
            for(int j = i + 1; j < n; ++j) {
                if(arr[j][0] <= end) {
                    end = max(end, arr[j][1]);
                }
            }
            
            res.push_back({start, end});
        }
        
        return res;
    }
};