#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> ops(n), s;
    string target;
    for (int i = 0; i < n; i++) cin >> ops[i];
    cin >> target;
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (ops[i] == target) {
            s.push_back(ops[i]);
            flag = 1;
            break;
        }
        if (ops[i] == "return") {
            s.pop_back();
        } else {
            s.push_back(ops[i]);
        }
    }

    if (flag) {
        for (int i = 0; i < s.size(); i++) {
            if (i) cout << "->";
            cout << s[i];
        }
    } else {
        cout << "NOT REFERENCED";
    }

    cout << endl;
    return 0;
}
