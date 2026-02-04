class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (auto x : s){
            if (x == ')'){
                if (stk.empty()) return false;
                if (stk.top() != '(') return false;
                stk.pop();
                continue;
            }
            else if (x == ']'){
                if (stk.empty()) return false;
                if (stk.top() != '[') return false;
                stk.pop();
                continue;
            }
            else if (x == '}'){
                if (stk.empty()) return false;
                if (stk.top() != '{') return false;
                stk.pop();
                continue;
            }
            stk.push(x);
        }
        return stk.empty();

        // stack<int> stk;
        // map<char, char> mp;
    }
};