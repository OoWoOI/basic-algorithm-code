/*************************************************************************
	> File Name: 05.hzoj-511.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Sep 2024 02:24:02 PM CST
 ************************************************************************/

#include<iostream>
using namespace std;
int main() {
    
    long long a, b, k;
    cin >> a >> b >> k;

    if (k == 0) {
        if (b != 0) cout << (b - a) << endl;
        else cout << !!(a) << endl;
        return 0;
    }

    if (k == 1) {
        cout << b - a << endl;
        return 0;
    }


    long long ans = 0;
    while (1) {
        if (a * k <= b) {
            ans += (1 + b % k);
            b /= k;
        } else {
            ans += (b - a);
            break;
        }
    }

    cout << ans << endl;

    return 0;
}
