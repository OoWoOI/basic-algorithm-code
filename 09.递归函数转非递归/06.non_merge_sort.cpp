/*************************************************************************
	> File Name: 06.merge_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 05 Aug 2024 03:52:57 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"./00.sort_test.h"
using namespace std;


int *buff;

void merge_sort(int *arr, int l, int r) {
    if (r - l <= 1) return ;
    
    int mid = (r + l) / 2, k = 0;
    int x = 0, y = mid;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid, r);
    
    while (x < mid || y < r) {
        if (y >= r || (x < mid && arr[x] < arr[y])) {
            buff[k++] = arr[x++];
        } else {
            buff[k++] = arr[y++];
        }
    }
    
    for (int i = l; i < r; i++) arr[i] = buff[i - l];
    
    return ;
}

struct Data {
    Data(int l, int r) : l(l), r(r) {}
    int l, r;
};

void merge_arr_once(int *arr, int l, int r) {
    int mid = (l + r) / 2;
    int p1 = l, p2 = mid, k = l;

    while (p1 < mid || p2 < r) {
        if (p2 >= r || (p1 < mid && arr[p1] < arr[p2])) {
            buff[k++] = arr[p1++];
        } else {
            buff[k++] = arr[p2++]; 
        }
    }

    for (int i = l; i < r; i++) arr[i] = buff[i];
    return ;
}

void non_merge_sort(int *arr, int l, int r) {
    Data init_d(l, r);
    vector<Data> d_arr;
    d_arr.push_back(init_d);

    for (int i = 0; i < d_arr.size(); i++) {
        int ll = d_arr[i].l, rr = d_arr[i].r;
        int mid = (ll + rr) / 2;
        if ((mid - ll) >= 2) {
            d_arr.push_back({ll, mid});
        } 

        if ((rr - mid) >= 2) {
            d_arr.push_back({mid, rr});
        }
    }
    
    for (int i = d_arr.size() - 1; i >= 0; i--) {
        merge_arr_once(arr, d_arr[i].l, d_arr[i].r);
    }

    return ;
}


int main() {
    int *arr = getRandomArr(BIG_DATA_NUM);
    buff = (int *)malloc(sizeof(int) * BIG_DATA_NUM);
    TEST(merge_sort, arr, BIG_DATA_NUM);
    TEST(non_merge_sort, arr, BIG_DATA_NUM);
    free(buff);
    return 0;
}
