class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int cnt = 0;       
        int currSum = 0;   
        
        for (int num = 1; num <= n; ++num) {
            if (find(banned.begin(), banned.end(), num) == banned.end() && currSum + num <= maxSum) {
                cnt++;          
                currSum += num; 
            }
        }

        return cnt; 
    }
};