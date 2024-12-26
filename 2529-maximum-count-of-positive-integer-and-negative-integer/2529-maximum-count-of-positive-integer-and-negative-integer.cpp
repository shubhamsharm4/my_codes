    class Solution {
    public:
        int maximumCount(vector<int>& nums) {
            int x = 0, y = 0; 
            for(int i : nums) {
                if(i == 0) continue;
                if(i < 0) x++;
                else y++;
            }
            return x > y ? x : y; 
        }
    };