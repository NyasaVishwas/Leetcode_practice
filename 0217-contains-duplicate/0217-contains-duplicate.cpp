class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto x: nums){
            if (us.count(x)) return true;
            us.insert(x);
        }
        return false;
    }
};