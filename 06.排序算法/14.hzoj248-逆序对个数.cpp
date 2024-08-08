/*************************************************************************
	> File Name: 14.hzoj248-逆序对个数.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Aug 2024 05:32:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAX_N 500000
int arr[MAX_N + 5];
int temp[MAX_N + 5];

typedef long long ll;

ll merge_sort(int *arr, int l, int r) {
    if (r - l <= 1) return 0;
    int mid = (l + r) / 2;
    ll a = merge_sort(arr, l, mid);
    ll b = merge_sort(arr, mid, r);
    ll c = 0, p1 = l, p2 = mid, k = 0;
    while (p1 < mid || p2 < r) {
        if (p2 == r || (p1 < mid && arr[p1] <= arr[p2])) {
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
            c += (mid - p1);
        }
    }
    for (int i = 0; i < k; i++) arr[i + l] = temp[i]; 
    return a + b + c;
}

void solve(int n) {
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    printf("%lld\n", merge_sort(arr, 0, n));
    return ;
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        solve(n);
    }
    
    return 0;
}
