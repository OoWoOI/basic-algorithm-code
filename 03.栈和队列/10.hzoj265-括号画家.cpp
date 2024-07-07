/*************************************************************************
	> File Name: 10.hzoj265-括号画家.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 07 Jul 2024 01:54:33 PM CST
 ************************************************************************/

#include<iostream>
#include<stack>
#include<string>
using namespace std;

#define MAX_N 10000

char str[MAX_N + 5];
int match[MAX_N + 5];

int func(char *str) {
    stack<int> stk;
    for (int i = 1; str[i]; i++) {
        switch(str[i]) {
            case '(':
            case '[':
            case '{': {
                stk.push(i);
            } break;
            case ')': {
                if (!stk.empty() && str[stk.top()] == '(') {
                    match[stk.top()] = i;
                    stk.pop();
                } else {
                    stk.push(i);
                }
            } break;
            case ']': {
                if (!stk.empty() && str[stk.top()] == '[') {
                    match[stk.top()] = i;
                    stk.pop();
                } else {
                    stk.push(i);
                } 
            } break;
            case '}': {
                if (!stk.empty() && str[stk.top()] == '{') {
                    match[stk.top()] = i;
                    stk.pop();
                } else {
                    stk.push(i);
                }   
            } break;
        }
    }

    int temp_ans = 0, ans = 0;
    for (int i = 1; str[i]; ) {
        //cout << i << " " << match[i] << endl;
        if (match[i]) {
            temp_ans += (match[i] - i) + 1;
            i = match[i] + 1;
        } else {
            temp_ans = 0;
            i++;
        }
        if (temp_ans > ans) ans = temp_ans;
    }
    return ans;
}

int main() {
    cin >> (str + 1);
    cout << func(str) << endl;
    return 0;
}
