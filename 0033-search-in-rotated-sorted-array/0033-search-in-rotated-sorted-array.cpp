class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi = n;
        while (lo < hi){
            int mid = lo + (hi - lo)/2;
            if (nums[mid] < nums[0])
                hi = mid;
            else lo = mid + 1;
        }
        int pivot = lo;
        if (target >= nums[0])
            lo = 0, hi = pivot;
        else lo = pivot, hi = n;
        while (lo < hi){
            int mid = lo + (hi - lo)/2;
            if (nums[mid] >= target)
                hi = mid;
            else lo = mid + 1;
        }
        if (lo >= n || nums[lo] != target) return -1;
        return lo;
    }
};
