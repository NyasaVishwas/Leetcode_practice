class Solution {
public:
    bool helper(vector<int>& B, int day, int m, int k){
        int curr = 0;
        int n = B.size();
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (B[i] > day){
                curr = 0; //not bloomed
            }
            else{
                curr++;
            }
            if (curr == k){
                ans++;
                curr -= k;
            }
        }
        return ans >= m;
    }
    int minDays(vector<int>& B, int m, int k) {
        long long int n = B.size();
        if (n/m < k) return -1;
        int lo = *min_element(B.begin(), B.end());
        int hi = *max_element(B.begin(), B.end());
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if (helper(B, mid, m, k))
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};