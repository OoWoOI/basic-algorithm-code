/*************************************************************************
	> File Name: 01.selection_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Jul 2024 09:03:09 PM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "./00.sort_test.h"


void selection_sort(int *arr, int l, int r) {
    for (int i = l; i < r; i++) {
        int ind = i;
        for (int j = i; j < r; j++) {
            if (arr[ind] > arr[j]) ind = j;
        }
        if (ind != i) SWAP(arr[i], arr[ind]);
    }
    return ;
}


int main() {
    int *arr = getRandomArr(BIG_DATA_NUM);
    TEST(selection_sort, arr, BIG_DATA_NUM);
    
    return 0;
}
