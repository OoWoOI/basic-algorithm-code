/*************************************************************************
	> File Name: 06.merge_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Mon 05 Aug 2024 03:52:57 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"./00.sort_test.h"


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

int main() {
    int *arr = getRandomArr(BIG_DATA_NUM);
    buff = (int *)malloc(sizeof(int) * BIG_DATA_NUM);
    TEST(merge_sort, arr, BIG_DATA_NUM);
    free(buff);
    return 0;
}
