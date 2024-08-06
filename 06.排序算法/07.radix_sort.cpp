/*************************************************************************
	> File Name: 07.radix_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 06 Aug 2024 09:43:39 AM CST
 ************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"./00.sort_test.h"

void radix_sort(int *arr, int l, int r) {
#define K 65536
    int *cnt = (int *)malloc(sizeof(int) * K);
    int *tmp = (int *)malloc(sizeof(int) * (r- l));
    //round1
    memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] % K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = r - 1; i >= l; i--) tmp[--cnt[arr[i] % K]] = arr[i];
    memcpy(arr + l, tmp, sizeof(int) * (r - l));
    //round2
     memset(cnt, 0, sizeof(int) * K);
    for (int i = l; i < r; i++) cnt[arr[i] / K] += 1;
    for (int i = 1; i < K; i++) cnt[i] += cnt[i - 1];
    for (int i = r - 1; i >= l; i--) tmp[--cnt[arr[i] / K]] = arr[i];
    memcpy(arr + l, tmp, sizeof(int) * (r - l));
    free(tmp);
    free(cnt);
    return ;
}

int main() {
    int *arr1 = getRandomArr(SMALL_DATA_NUM); 
    int *arr2 = getRandomArr(BIG_DATA_NUM);
    TEST(radix_sort, arr1, SMALL_DATA_NUM);
    TEST(radix_sort, arr2, BIG_DATA_NUM);
    free(arr1);
    free(arr2);
    return 0;
}
