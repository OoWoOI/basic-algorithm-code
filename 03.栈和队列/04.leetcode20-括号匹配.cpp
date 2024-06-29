class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; s[i]; i++) {
            switch (s[i]) {
                case ')': 
                case '}':
                case ']': {
                    if (stk.empty()) return false;
                    if (
                        (stk.top() == '(' && s[i] == ')') || 
                        (stk.top() == '{' && s[i] == '}') ||
                        (stk.top() == '[' && s[i] == ']')
                    ) {
                        stk.pop();
                    } else {
                        stk.push(s[i]);
                    }
                    
                } break;
                default : {stk.push(s[i]);} break;
            }
        }
        return stk.empty();
    }
};
