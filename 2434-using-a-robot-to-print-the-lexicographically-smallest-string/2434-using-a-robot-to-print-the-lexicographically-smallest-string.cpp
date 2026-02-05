class Solution {
public:
    string robotWithString(string s) {
        stack<int> t,st;
        string ans="";
        int n = s.size();
        vector<int> suffmin(n);
        char mn = 'z';
        int curr_idx=n-1;
        for(int i = n-1;i>=0;i--){
            if(mn>=s[i]){
                mn = s[i];
                curr_idx = i;
            }
            suffmin[i]=curr_idx; // make suffmin using indices 
            st.push(i); // this so that we can access front
        } 
        int idx=0;
        while(!st.empty()){
            if(!t.empty() && s[t.top()]<=s[suffmin[idx]]){
                ans+=s[t.top()];
                t.pop();
                continue;
            } // check T stack
            while(!st.empty() && st.top()!=suffmin[idx]){
                t.push(st.top());
                st.pop();
                idx++;
            } // pop from s till u dont get minimum possible string
            ans+=s[suffmin[idx]];
            st.pop();
            idx++;
        }
        while(!t.empty()){
            ans+=s[t.top()];
            t.pop();
        }
        return ans;
    }
};