class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N);

        for(int i = 0; i < N; ++i) {
            int steps = nums[i];
            int tarIdx = ((i + steps) % N + N) % N;
            res[i] = nums[tarIdx];
        }

        return res; 
    }
};