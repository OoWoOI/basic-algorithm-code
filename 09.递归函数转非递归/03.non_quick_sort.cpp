/*************************************************************************
	> File Name: 05.quick_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Jul 2024 10:08:56 PM CST
 ************************************************************************/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stack>
#include"00.sort_test.h"
using namespace std;


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

struct Data{
    Data(int *arr, int l, int r) : arr(arr), l(l), r(r), code(0) {}
    int *arr, l, r;
    int x;
    int code;
};

void non_quick_sort(int *arr, int l, int r) {
    stack<Data> s;
    Data d(arr, l, r);
    s.push(d);
    while (!s.empty()) {
        Data &cur = s.top();
        switch(cur.code) {
            case 0: {
                if (cur.r - cur.l <= 2) {
                    if (cur.r - cur.l <= 1) {
                        s.pop();
                    } else {
                        if (cur.arr[cur.l] > cur.arr[cur.l + 1]) {
                            SWAP(cur.arr[cur.l], cur.arr[cur.l + 1]);
                        }
                        s.pop();
                    }
                } else {
                    cur.code = 1;
                }   
            } break;
            case 1: {
                int x = cur.l, y = cur.r - 1, z = cur.arr[cur.l];
                while (x < y) {
                    while (x < y && z <= cur.arr[y]) --y;
                    if (x < y) cur.arr[x++] = cur.arr[y];
                    while (x < y && z >= cur.arr[x]) ++x;
                    if (x < y) cur.arr[y--] = cur.arr[x];
                }
                cur.arr[x] = z;
                cur.x = x;
                cur.code = 2;
            } break;
            case 2: {
                Data d(cur.arr, cur.l, cur.x);
                cur.code = 3;
                s.push(d);
            } break;
            case 3: {
                Data d(cur.arr, cur.x + 1, cur.r);
                cur.code = 4;
                s.push(d);
            } break;
            case 4: {
                s.pop();
            } break;
        }
    }
    
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
    TEST(quick_sort    , arr2, BIG_DATA_NUM);
    TEST(non_quick_sort, arr2, BIG_DATA_NUM);
    TEST(quick_sort_v1 , arr2, BIG_DATA_NUM);
    TEST(quick_sort_v2 , arr2, BIG_DATA_NUM);
    TEST(quick_sort_v3 , arr2, BIG_DATA_NUM);
    TEST(quick_sort_v4 , arr2, BIG_DATA_NUM);
    return 0;
}
