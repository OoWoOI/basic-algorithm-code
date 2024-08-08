/*************************************************************************
	> File Name: 01.binary_search.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Aug 2024 10:17:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void output(int *arr, int size, int ind) {
    int len = 0;
    for (int i = 0; i < size; i++) {
        len +=printf("%4d", arr[i]);
    }
    printf("\n");
    for (int i = 0; i < len; i++) printf("-");
    printf("\n");
    for (int i = 0; i < size; i++) {
        if (i == ind) printf("\033[1;32m");
        printf("%4d", arr[i]);
        if (i == ind) printf("\033[0m");
    }
    printf("\n");
    return ;
}

int binary_search(int *arr, int size, int x) {
    int l = 0, r = size - 1, mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

void test_binary_search(int n) {
    //make rand val up arrary
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = rand() % 100;
    for (int i = 1; i < n; i++) arr[i] = (arr[i - 1] + rand() % 100);
    //output rand up arrary
    output(arr, n, n);
    //begin find x
    int x;
    while (~scanf("%d", &x)) {
        int ind = binary_search(arr, n, x);
        output(arr, n, ind);
    }
    return ;
}

int main() {
    srand(time(0));
    int n;
    scanf("%d", &n);
    test_binary_search(n);
    
    return 0;
}
