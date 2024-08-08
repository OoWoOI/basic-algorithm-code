/*************************************************************************
	> File Name: 15.hzoj251-士兵.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Aug 2024 05:56:10 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
#define MAX_N 100000
int X[MAX_N + 5], Y[MAX_N + 5];
int n;


int select_mid_one(int *arr) {
    int mid = arr[n / 2];
    return mid;
}

int solve() {

    int x = 0, y = 0;
    
    //sort two arr
    sort(X, X + n);
    for (int i = 0; i < n; i++) X[i] -= i;

    sort(X, X + n);
    //X mid one
    int mid_x = select_mid_one(X);
    for (int i = 0; i < n; i++) x += abs(X[i] - mid_x);

    sort(Y, Y + n);
    //Y mid one
    int mid_y = select_mid_one(Y);
    for (int i = 0; i < n; i++) y += abs(Y[i] - mid_y);
    
    return x + y;
} 

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }
    cout << solve() << endl;

    return 0;
}
