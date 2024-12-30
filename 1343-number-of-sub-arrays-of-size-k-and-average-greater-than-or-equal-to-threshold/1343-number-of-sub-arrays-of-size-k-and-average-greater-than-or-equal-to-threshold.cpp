class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int N = arr.size();
        int cnt = 0;
        int prefixSum = 0, l = 0, r = 0;

        while(r < N) {
            prefixSum += arr[r];

            if(r - l + 1 == k) {
                if(prefixSum / k >= threshold) cnt += 1;
                prefixSum -= arr[l];
                l++;
            }
            r++;
        }

        return cnt; 
    }
};