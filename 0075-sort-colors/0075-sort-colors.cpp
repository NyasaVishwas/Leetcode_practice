class Solution {
public:
    void sortColors(vector<int>& v) {
        int n = v.size();
        int ptr2 = n - 1;
        int ptr0 = 0;       

        for (int i = 0; i <= ptr2; i++) {
            while (v[i] == 2 && i < ptr2) {
                swap(v[i], v[ptr2]);
                ptr2--;
            }
            while (v[i] == 0 && i > ptr0) {
                swap(v[i], v[ptr0]);
                ptr0++;
            }
        }
        
    }
};