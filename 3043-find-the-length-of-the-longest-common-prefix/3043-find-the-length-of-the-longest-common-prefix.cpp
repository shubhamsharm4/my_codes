class Solution {
public:
    int helper(int n1, int n2) {
        string s1 = to_string(n1);
        string s2 = to_string(n2);
        
        int i = 0;
        while (i < s1.length() && i < s2.length() && s1[i] == s2[i]) {
            i++;
        }
        return i;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int maxi = 0;

        for(int i = 0; i < arr1.size(); ++i) {
            for(int j = 0; j < arr2.size(); ++j) {
                maxi = max(maxi, helper(arr1[i], arr2[j]));
            }
        }

        return maxi;
    }
};