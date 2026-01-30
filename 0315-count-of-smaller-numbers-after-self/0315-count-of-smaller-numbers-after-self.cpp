class Solution {
public:
    vector<int> countSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);
        vector<int> seen;

        for(int i = n - 1; i >= 0; i--) {
            int pos = lower_bound(seen.begin(), seen.end(), arr[i]) - seen.begin();
            res[i] = pos;     
            seen.insert(seen.begin() + pos, arr[i]);
        }

        return res;
    }
};