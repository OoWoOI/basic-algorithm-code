/*************************************************************************
	> File Name: 12.hzoj244-奶牛围栏.cpp
	> Author: 
	> Mail: 
	> Created Time: Sun 11 Aug 2024 04:19:10 PM CST
 ************************************************************************/

#include<iostream>
#include<algorithm>
using namespace std;

#define MAX_N 500

struct Point {
    int x, y;
} arr[MAX_N + 5];


int tmp[MAX_N + 5];

bool cmp(const Point &a, const Point &b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}


int check_y(Point *arr, int n, int c, int b, int e, int l) {
    int cnt = 0;
    for (int i = b; i <= e; i++) {
        tmp[cnt++] = arr[i].y;
    }
    sort(tmp, tmp + cnt);
    for (int i = c - 1; i < cnt; i++) {
        if (tmp[i] -tmp[i - c + 1] < l) return 1;
    }
    return 0;
}

int check(Point *arr, int n, int C, int l) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        while (arr[i].x - arr[j].x >= l) j += 1;
        if (i - j + 1 < C) continue;
        if (check_y(arr, n, C, j, i, l)) return 1;
    }
    return 0;
}


int bs(int l, int r, Point *arr, int n, int C) {
    int L = 0;
    while (l < r) {
        L = (l + r) / 2;
        if (!check(arr, n, C, L)) {
            l = L + 1;
        } else {
            r = L;
        }
    }
    return l;
}

int main() {
    int C, n;
    cin >> C >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i].x >> arr[i].y;
    }
    sort(arr, arr + n, cmp);
    cout << bs(0, 10000, arr, n, C) << endl;
    
    return 0;
}
