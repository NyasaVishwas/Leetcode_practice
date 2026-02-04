class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse(n, -1);
        vector<int> pse(n, -1);
        stack<int> sn, sp;
        for (int i = n - 1; i >= 0; i--){
            while (!sn.empty() && heights[sn.top()] >= heights[i]){
                sn.pop();
            }
            nse[i] = sn.empty() ? n : sn.top();
            sn.push(i);
        }

        for (int i = 0; i < n; i++){
            while (!sp.empty() && heights[sp.top()] >= heights[i]){
                sp.pop();
            }
            pse[i] = sp.empty() ? -1 : sp.top();
            sp.push(i);
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, heights[i]*(nse[i] - pse[i] - 1));
        }
        return ans;
    }
};