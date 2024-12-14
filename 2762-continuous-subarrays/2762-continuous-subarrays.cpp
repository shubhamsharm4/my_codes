class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long res = 0;
        multiset<int> m;
        int j = 0;

        for(int i = 0; i < nums.size(); ++i) {
            m.insert(nums[i]);

            while(*m.rbegin() - *m.begin() > 2) {
                m.erase(m.find(nums[j]));
                j++;
            }

            res += (i - j + 1);
        }

        return res; 
    }
};