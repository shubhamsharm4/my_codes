class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;

        for(int i : nums) {
            if(i != 0) {
                nums[idx] = i;
                idx += 1;
            }
        }

        while(idx < nums.size()) {
            nums[idx] = 0;
            idx += 1; 
        }
    }
};