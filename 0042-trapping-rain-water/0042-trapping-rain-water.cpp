class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        stack<int> s;
        int ans = 0;
        for (int i = n-1; i >= 0; i--){
            while (!s.empty() && h[s.top()] < h[i]){
                int mid = s.top();
                s.pop();
                if (s.empty()) continue;
                int left = h[i];
                int right = h[s.top()];
                int width = s.top() - i - 1;
                ans += (min(left, right) - h[mid]) * width;
            }
            s.push(i);
        }   
        return ans;
    }
};