class Solution {
public:
    int helper(vector<int>& nums, int capacity, int k){
        int sum = 0;
         int cnt = 1;
         for (auto x : nums){
            if (sum + x > capacity){
                cnt++;
                sum = x;
            }
            else sum += x;
         }
         return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = *max_element(nums.begin(), nums.end());
        int hi = accumulate(nums.begin(), nums.end(), 0) + 1;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if (helper(nums, mid, k))
                hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};