#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;


bool is_valid(vector<int> &num) {
    
    stack<int> stk;
    int p = 1;
    for (int i = 0; i < num.size(); i++) {
        while (p <= num[i]) {
            stk.push(p);
            p++;
        }

        if (!stk.empty() && stk.top() == num[i]) {
            stk.pop();
        }
    }
    
    return stk.empty();
}

int main() {
    int n;

    cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++) num[i] = i + 1;

    int cnt = 0;
    do {
        if (is_valid(num)) {
            for (auto x : num) {
                cout << x;
            }
            cout << endl;
            cnt++;
        }
    } while (next_permutation(num.begin(), num.end()) && cnt < 20);
    

    return 0;
}
