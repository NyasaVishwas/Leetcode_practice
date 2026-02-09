typedef pair<int, int> pii;
class Compare{
public:
    bool operator()(pii a, pii b){
        return a.first >= b.first;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        for (auto x: nums) mp[x]++;
        priority_queue<pii, vector<pii>, Compare> pq;
        for (auto [x, freq]: mp){
            pq.push({freq, x});
            if (pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            auto[f,x] = pq.top();
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};