class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> t;
        for(int i = 1; i < nums.size(); ++i) {
            if((nums[i] % 2 == 0 && nums[i-1] % 2 == 0) ||
            (nums[i] % 2 != 0 && nums[i-1] % 2 != 0)) t.push_back(i);
        }

        vector<bool> res;

        for(const auto& q : queries) {
            int from = q[0], to = q[1];
            bool is_special = true;
            
            for(int i : t) {
                if(i > to) break; 

                else if(i > from) {
                    is_special = false;
                    break;
                }
            }
            res.push_back(is_special); 
        }

        return res; 
    }
};