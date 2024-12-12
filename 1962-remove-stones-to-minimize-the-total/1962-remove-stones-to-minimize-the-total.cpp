class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int cnt = 0;

        priority_queue<int> maxHeap(piles.begin(), piles.end());

        while(k > 0) {
            int t = maxHeap.top();
            maxHeap.pop();

            t -= floor(t/2);

            maxHeap.push(t);

            k--;
        }   

        while (!maxHeap.empty()) {
            cnt += maxHeap.top();
            maxHeap.pop();
        }

        return cnt;
    }
};