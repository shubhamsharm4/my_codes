class Solution {
public:
    bool helper(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' ||c == 'I' ||c == 'O' ||c == 'U') return true;

        return false;
    }

    string sortVowels(string s) {
        vector<char> v;
        for(char c : s) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' ||c == 'I' ||c == 'O' ||c == 'U') v.push_back(c);
        }

        sort(v.begin(), v.end());
        int idx = 0;

        string t = "";
        for(char c : s) {
            if(helper(c)) {
                t += v[idx];
                idx++;
            }
            else t += c;
        }

        return t; 
    }
};