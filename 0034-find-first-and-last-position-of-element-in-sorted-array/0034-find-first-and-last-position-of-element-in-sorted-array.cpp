class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n;
        vector<int> v;
        int fa=-1;
        int la=-1;
        while(low<high){
            int mid=(low+high)/2;
            if(nums[mid]>=target){
                high=mid;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }
            else{low=-1;}
        }
        fa=low;
        v.push_back(fa);
        int l=0,h=n;
        while(l<h){
            int mid=(l+h)/2;
            if(nums[mid]>target){
                h=mid;
            }
            else if(nums[mid]<=target){
                l=mid+1;
            }
            else{
                l=-1;
            }
        }
        la=l;
        if(fa==la)return{-1,-1};
        v.push_back(la-1);
        return v;

    }
};