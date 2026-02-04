class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int> stk;
        for(int i=0;i<n;i++){
            if(!stk.empty() && s[i]==')' && s[stk.top()]=='('){
                stk.pop();
                continue;
            }
            stk.push(i);
        }
        int ans = 0;
        int last_idx = n;
        while(!stk.empty()){
            int current_idx = stk.top();
            stk.pop();
            ans = max(ans, last_idx - current_idx - 1);
            last_idx = current_idx;
        }
        ans = max(ans, last_idx);
        return ans;
    }
};