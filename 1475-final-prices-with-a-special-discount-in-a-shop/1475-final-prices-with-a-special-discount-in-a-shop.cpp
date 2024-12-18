class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n);  
        
        for(int i = 0; i < n; ++i) {
            bool found = false;
            for(int j = i + 1; j < n; ++j) {
                if(prices[i] >= prices[j]) {
                    res[i] = prices[i] - prices[j];
                    found = true;
                    break;
                }
            }
            if(!found) res[i] = prices[i];
        }

        return res; 
    }
};