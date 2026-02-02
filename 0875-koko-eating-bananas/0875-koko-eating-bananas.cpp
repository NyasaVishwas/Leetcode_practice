class Solution {
public:
    bool helper(long long int k, vector<int> piles, int h){
        long long int sm = 0;
        for (auto x : piles){
            sm += (x+k-1)/k;
        }
        return sm <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        long long int lo = 1, hi = *max_element(piles.begin(), piles.end())+1;
        while(lo < hi){
            long long int mid = lo + (hi - lo)/2;
            if (helper(mid, piles, h))
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};