#define pii pair<int, int>
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.size()<=k) return points;
        sort(
            points.begin(),
            points.end(),
            [](vector<int> a, vector<int> b){
                int dA = a[0]*a[0] + a[1]*a[1];
                int dB = b[0]*b[0] + b[1]*b[1];
                return dA <= dB;
            }
        );
        vector<vector<int>> ans;
        for (int i = 0; i < k; i++) ans.push_back(points[i]);
        return ans;
    }
};