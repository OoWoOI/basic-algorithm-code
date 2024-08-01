/*************************************************************************
	> File Name: 04.bubble_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Jul 2024 09:52:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"./00.sort_test.h"

void bubble_sort(int *arr, int l, int r) {
    for (int i = l; i < r; i++) {
        int flag = 0;
        for (int j = l; j < r - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                SWAP(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) break; 
    } 
    return ;
}

int main() {
    int *arr = getRandomArr(BIG_DATA_NUM);
    TEST(bubble_sort, arr, BIG_DATA_NUM);
    return 0;
}
