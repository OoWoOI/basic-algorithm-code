/*************************************************************************
	> File Name: 05.quick_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Jul 2024 10:08:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"00.sort_test.h"

void quick_sort(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l == 2 && arr[l] CMP arr[l + 1]) {
            SWAP(arr[l], arr[l + 1]);
        }
        return ;
    }
    int x = l, y = r - 1, z = arr[l];
    while (x < y) {
        while (x < y && arr[y] >= z) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] <= z) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = z;
    quick_sort(arr, l, x);
    quick_sort(arr, x + 1, r);
    return ;
}

void quick_sort_v1(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l == 2 && arr[l] CMP arr[l + 1]) {
            SWAP(arr[l], arr[l + 1]);
        }
        return ;
    }
    int x = l, y = r - 1, z = arr[l];
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) {
            SWAP(arr[x], arr[y]);
            x++;
            y--;
        }
    } while (x <= y);
    arr[x] = z;
    quick_sort_v1(arr, l, y + 1);
    quick_sort_v1(arr, x, r);
    return ;
}

int three_point_select(int a, int b, int c) {
    if (a > b) SWAP(a, b);
    if (a > c) SWAP(a, c);
    if (b > c) SWAP(b, c)
    return b;
}

void quick_sort_v2(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l == 2 && arr[l] CMP arr[l + 1]) {
            SWAP(arr[l], arr[l + 1]);
        }
        return ;
    }
    int x = l, y = r - 1, z = three_point_select(
        arr[l],
        arr[r - 1],
        arr[(r + l) >> 1]);
    do {
        while (arr[x] < z) ++x;
        while (arr[y] > z) --y;
        if (x <= y) {
            SWAP(arr[x], arr[y]);
            x++;
            y--;
        }
    } while (x <= y);
    arr[x] = z;
    quick_sort_v2(arr, l, y + 1);
    quick_sort_v2(arr, x, r);
    return ;
}

void quick_sort_v3(int *arr, int l, int r) {
    if (r - l <= 2) {
        if (r - l == 2 && arr[l] CMP arr[l + 1]) {
           SWAP(arr[l], arr[l + 1]);
        }
        return ;
    }
    while (l < r) {
   
        int x = l, y = r - 1, z = three_point_select(
            arr[l],
            arr[r - 1],
            arr[(r + l) >> 1]);
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                SWAP(arr[x], arr[y]);
                x++;
                y--;
            }
        } while (x <= y);
        arr[x] = z;
        quick_sort_v3(arr, l, y + 1);
        l = x;
    }
    return ;
}

#define thresholds 16

void __quick_sort_v4(int *arr, int l, int r) {
    
    while (r - l > thresholds) {
        int x = l, y = r - 1, z = three_point_select(
            arr[l],
            arr[r - 1],
            arr[(r + l) >> 1]);
        do {
            while (arr[x] < z) ++x;
            while (arr[y] > z) --y;
            if (x <= y) {
                SWAP(arr[x], arr[y]);
                x++;
                y--;
            }
        } while (x <= y);
        arr[x] = z;
        __quick_sort_v4(arr, l, y + 1);
        l = x;
    }
    return ;
}

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i < r; i++) {
        if (arr[ind] > arr[i]) ind = i;
    }

    while (ind > l) {
        SWAP(arr[ind], arr[ind - 1]);
        ind -= 1;
    } 

    for (int i = l + 1; i < r; i++) {
        int j = i;
        while (arr[j - 1] > arr[j]) {
            SWAP(arr[j - 1], arr[j]);
            j -= 1;
        }
    }

    return ;
}

void quick_sort_v4(int *arr, int l, int r) {
    __quick_sort_v4(arr, l, r);
    unguarded_insert_sort(arr, l, r); 
    return ;
}


int main() {
    int *arr1 = getRandomArr(SMALL_DATA_NUM);
    TEST(quick_sort   , arr1, SMALL_DATA_NUM);
    free(arr1);
    int *arr2 = getRandomArr(BIG_DATA_NUM);
    TEST(quick_sort   , arr2, BIG_DATA_NUM);
    TEST(quick_sort_v1, arr2, BIG_DATA_NUM);
    TEST(quick_sort_v2, arr2, BIG_DATA_NUM);
    TEST(quick_sort_v3, arr2, BIG_DATA_NUM);
    TEST(quick_sort_v4, arr2, BIG_DATA_NUM);
    return 0;
}
