class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long res = 0;

        multiset<int>ms (gifts.begin(), gifts.end());

        while(k > 0) {
            auto it = prev(ms.end());
            int t = *it;

            ms.erase(it);

            t = floor(sqrt(t));
            ms.insert(t);

            k--;
        }

        for(int i : ms) {
            res += i;
        }

        return res;
    }
};