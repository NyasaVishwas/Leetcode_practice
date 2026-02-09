class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> mnpq;
    int findKthLargest(vector<int>& nums, int k) {
        for (auto x: nums){
            mnpq.push(x);
        }
        while(mnpq.size()>k){
            mnpq.pop();
        }
        return mnpq.top();
    }
};