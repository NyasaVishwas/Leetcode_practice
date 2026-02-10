class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0;
        int ans = INT_MIN;
        int max_till_here = INT_MIN;
        for (auto x: nums){
            curr += x;
            max_till_here = max(max_till_here, curr);
            ans = max(ans, max_till_here);
            if (curr < 0) curr = 0;
        }
        return ans;
    }
};