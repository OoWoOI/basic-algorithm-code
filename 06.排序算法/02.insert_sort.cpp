/*************************************************************************
	> File Name: 02.insert_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Jul 2024 09:15:45 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"00.sort_test.h"

void insert_sort(int *arr, int l, int r) {
    
    for (int i = l + 1; i < r; i++) {
        int ind = i;
        while (l < ind && arr[ind - 1] > arr[ind]) {
            SWAP(arr[ind], arr[ind - 1]);
            ind -= 1;
        }
    }
    return ;
}

void unguarded_insert_sort(int *arr, int l, int r) {
    int ind = l;
    //找到最小值元素
    for (int i = l + 1; i < r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    //将最小值元素移动到首位
    while (l < ind) {
        SWAP(arr[ind], arr[ind - 1]);
        ind -= 1;
    }
    //插入排序
    for (int i = l + 1; i < r; i++) {
        int ind = i;
        while (arr[ind] < arr[ind - 1]) {
            SWAP(arr[ind], arr[ind - 1]);
            ind -= 1;
        }
    }
    return ;
}



int main() {
    int *arr = getRandomArr(BIG_DATA_NUM);
    TEST(insert_sort, arr, BIG_DATA_NUM);
    TEST(unguarded_insert_sort, arr, BIG_DATA_NUM);
    
    return 0;
}
