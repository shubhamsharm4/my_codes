class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k > 0){
            auto i = min_element(nums.begin(),nums.end());
            *i *= multiplier;
            k--;
        }
        return nums; 
    }
};