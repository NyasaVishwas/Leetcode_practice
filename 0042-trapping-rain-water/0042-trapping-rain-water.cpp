class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        vector<int> prefix(n , 0), suffix(n , 0);
        int mx = 0;
        for (int i = 0; i < n; i++){
            mx = max(mx, h[i]);
            prefix[i] = mx;
        }
        mx = 0;
        for (int i = n - 1; i >= 0; i--){
            mx = max(mx, h[i]);
            suffix[i] = mx;
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++){
            int water = min(prefix[i], suffix[i]) - h[i];
            if (water >= 0) ans += water;
        }
        return ans;
    }
};