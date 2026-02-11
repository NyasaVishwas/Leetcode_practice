class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++){
            int left = i + 1;
            int right = n - i;
            int tot = left*right;
            int oddcnt = (tot + 1)/2;
            ans += oddcnt * arr[i];
        }
        return ans;
    }
};