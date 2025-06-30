class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numIndex;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numIndex.find(complement) != numIndex.end()) {
                return {numIndex[complement], i};
            }
            numIndex[nums[i]] = i;
        }
        return {};
    }
};
