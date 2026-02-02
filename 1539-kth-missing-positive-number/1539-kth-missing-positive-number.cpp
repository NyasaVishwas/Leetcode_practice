class Solution {
public:
int missingCount(int mid, vector<int> arr){
    return arr[mid]-mid-1;
}
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0]) return k;
        int n = arr.size();
        int lo = 0, hi = n;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if (missingCount(mid, arr) >= k)
                hi = mid;
            else lo = mid + 1;
        }
        int rem = k - missingCount(lo - 1, arr);
        return arr[lo - 1] + rem;
    }
};