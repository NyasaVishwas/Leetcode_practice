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
        int ans=0;
        int curr=n;
        while(!stk.empty()){
            int currLen=curr-stk.top()-1;
            curr=stk.top();
            stk.pop();
            if(ans<currLen){
                ans=currLen;
            }
           
        }
        if(curr>ans)ans=curr;
        return ans;
    }
};