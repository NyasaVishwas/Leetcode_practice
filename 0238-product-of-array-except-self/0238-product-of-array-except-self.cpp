class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n, 1), suffix(n, 1), answer;
        for (int i = 0; i < n; i++){
            int prev = 1;
            if (i > 0) prev = prefix[i - 1];
            prefix[i] = prev*nums[i];
        }
        for (int i = n - 1; i >= 0; i--){
            int prev = 1;
            if (i < n - 1) prev = suffix[i + 1];
            suffix[i] = prev*nums[i];
        }
        for (int i = 0; i < n; i++){
            int prev = 1;
            if (i > 0) prev = prefix[i - 1];
            int after = 1;
            if (i < n - 1) after = suffix[i + 1];
            answer.push_back(prev*after);
        }
        return answer;
        
    }
};