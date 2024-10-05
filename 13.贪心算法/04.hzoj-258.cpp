/*************************************************************************
	> File Name: 04.hzoj-258.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 20 Sep 2024 01:28:20 PM CST
 ************************************************************************/

#include<iostream>
#include<cinttypes>
using namespace std;

#define MAX_N 100
int N;
int arr[MAX_N + 5][MAX_N + 5];

int main() {
    cin >> N; 
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            arr[i][j] += arr[i - 1][j];
        }
    }

    int ans = INT32_MIN;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            int S = 0;
            for (int k = 1; k <= N; k++) {
                int a = arr[j][k] - arr[i - 1][k];
                if (S >= 0) S += a;
                else S = a;
                if (ans < S) ans = S;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
