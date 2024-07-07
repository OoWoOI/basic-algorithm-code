class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        for (int i = 0, j = 0; i < popped.size(); i++) {
            if (stk.empty() || stk.top() != popped[i]) {
                while (j < pushed.size() && pushed[j] != popped[i]) {
                    stk.push(pushed[j]);
                    j++;
                }
                if (j == pushed.size()) return false;
                stk.push(pushed[j]);
                j++;
            }
            stk.pop();
        }
        return stk.empty();
    }
};
