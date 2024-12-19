class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxi = INT_MIN;
        int chunks = 0;

        for(int i = 0; i < arr.size(); ++i) {
            maxi = max(maxi, arr[i]);
            if(maxi == i) {
                chunks += 1;
            }
        }

        return chunks;
    }
};