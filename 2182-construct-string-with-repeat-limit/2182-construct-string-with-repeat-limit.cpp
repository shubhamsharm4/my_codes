class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string res = "";
        sort(s.rbegin(), s.rend());

        int freq = 1;
        int pointer = 0;

        for(int i = 0; i < s.length(); ++i) {
            if(!res.empty() && res.back() == s[i]) {
                if(freq < repeatLimit) {
                    res += s[i];
                    freq++;
                }
                else {
                    pointer = max(pointer, i + 1);
                    while(pointer < s.length() && s[pointer] == s[i]) {
                        pointer++;
                    }
                    if(pointer < s.length()) {
                        res += s[pointer];
                        swap(s[i], s[pointer]);
                        freq = 1;
                    }
                    else break;
                }
            }
            else {
                res += s[i];
                freq = 1;
            }
        }

        return res; 
    }
};