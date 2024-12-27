class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) { 
        int res = INT_MIN;
        int prefix = values[0];

        for(int i = 1; i < values.size(); ++i) {
            res = max(res, prefix + values[i] - i);
            prefix = max(prefix, values[i] + i);
        }

        return res; 
    }
};