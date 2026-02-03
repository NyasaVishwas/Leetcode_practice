class Solution {
public:
    int search(vector<int> arr, int target){
        int lo = 0, hi = arr.size();
        while (lo < hi){
            int mid = lo + (hi - lo)/2;
            if (arr[mid] >= target)
                hi = mid;
            else lo = mid + 1;
        } 
        return lo;
    }

    int search2(vector<int> arr, int target){
        int lo = 0, hi = arr.size();
        while (lo < hi){
            int mid = lo + (hi - lo)/2;
            if (arr[mid] > target || arr[mid] == target && (mid == arr.size() - 1 || arr[mid + 1] > target))
                hi = mid;
            else lo = mid + 1;
        } 
        return lo;
    }

    vector<int> searchRange(vector<int>& arr, int target) {
        int first = search(arr, target);
        if (first==arr.size() || arr[first] != target) return {-1,-1};
        int last = search2(arr, target);
        return {first, last};
    }
};