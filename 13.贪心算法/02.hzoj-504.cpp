/*************************************************************************
	> File Name: 02.hzoj-504.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 19 Sep 2024 09:47:52 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#define MAX_N 240
int main() {
    char s[MAX_N + 5] = {0};
    int k;
    cin >> s >> k;
    for (int i = 0; i < k; i++) {
        int j = 0;
        while (s[j + 1] && s[j] <= s[j + 1]) j++;
        while (s[j]) s[j] = s[j + 1], j++;
    }
    for (int i = 0, flag = 1; s[i]; i++) {
        if (s[i] == '0' && flag) continue;
        cout << s[i];
        flag = 0;
    }
    cout << endl;
    return 0;
}
