/*************************************************************************
	> File Name: 02.monotonic_stack.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 23 Aug 2024 02:41:22 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;


//TODO : 单调栈代码演示
void output(vector<int> &arr) {
    int len = 0;
    for (auto x : arr) {
        len += printf("%3d", x);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");

    return ;
} 

int main () {
    int n;
    cin >> n;
    vector<int> arr, l(n + 1), r(n + 1);
    stack<int> s;
    arr.push_back(-1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    arr.push_back(-1);
    
    output(arr); 

    //right
    for (int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] > arr[i]) {
            r[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty()) s.pop();

    //left
    for (int i = arr.size() - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] > arr[i]) {
            l[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    for (int i = 0; i <= n; i++) {
          printf("arr[%d] = %d, right : arr[%d] = %d, left : arr[%d] = %d\n",
            i, arr[i],
            r[i], arr[r[i]],
            l[i], arr[l[i]]
        );
    }

    return 0;
}
