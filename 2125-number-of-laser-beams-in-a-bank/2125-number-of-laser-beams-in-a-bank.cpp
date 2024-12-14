class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int res = 0, prev = 0;

        for(int i = 0; i < bank.size(); ++i) {
            int cnt = 0;
            for(auto c : bank[i]) {
                if(c == '1') cnt ++;
            }

            if(cnt > 0) {
                res += cnt * prev; 
                prev = cnt;
            }
        }

        return res; 
    }
};