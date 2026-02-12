class Solution {
public:
    bool check(string s, int l, int r){
        while (l < r && s[l] == s[r]){
            l++;
            r--;
        }
        return (l == r || l > r);
    }
    
    bool validPalindrome(string s) {
        int n = s.size();
        int l = 0;
        int r = n - 1;
        while (l < r && s[l] == s[r]){
            l++;
            r--;
        }
        if (l > r || l == r) return true;
        return check(s, l + 1, r) || check(s, l, r - 1);
    }
};