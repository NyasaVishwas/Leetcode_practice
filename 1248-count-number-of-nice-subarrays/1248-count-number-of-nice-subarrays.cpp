class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int l = 0;
        int cntodd = 0;
        int n = nums.size();
        int ans = 0;
        deque<int> q;//first odd number
        for (int r = 0; r < n; r++){
            if (nums[r] % 2 == 1){
                cntodd++;
                q.push_back(r);
            }
            while(cntodd > k && l <= r){
                if (nums[l] % 2 == 1){
                    cntodd--;
                    if (!q.empty() && q.front() == l) q.pop_front();
                }
                l++;
            }
            if (!q.empty() && cntodd == k)
                ans += q.front() - l + 1;
        }
        return ans;
    }
};