class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = n-1; i >= 2; i--){
            if (i < n-1 && nums[i] == nums[i+1]) continue;
            int l = 0, r = i-1;
            while(l<r) {
                int curr = nums[l] + nums[r];
                if (curr == (-nums[i])){
                    ans.push_back({nums[l], nums[r], nums[i]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) l++;
                    while (l < r && nums[r] == nums[r + 1]) r--;
                }
                else if (curr > (-nums[i])){
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};