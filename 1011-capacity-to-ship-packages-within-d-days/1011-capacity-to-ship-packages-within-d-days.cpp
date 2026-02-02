class Solution {
public:
    bool helper(int capacity, vector<int> weights, int days){
        int curr = 0, tot = 1;
        for (auto x : weights){
            if (x + curr > capacity){
                tot++;
                curr=0;
            }
            curr+=x;  
        }
        return tot <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lo = *max_element(weights.begin(), weights.end());
        int hi = accumulate(weights.begin(), weights.end(), 0) + 1;
        while (lo < hi){
            int mid = lo + (hi - lo)/2;
            if (helper(mid, weights, days))
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};