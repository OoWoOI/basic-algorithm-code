/*************************************************************************
	> File Name: 02.heap_sort.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 23 Jul 2024 02:23:50 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define ROOT 1
#define CMP >
#define FATHER(i) ((i) / 2)
#define LEFT(i) ((i) * 2)
#define RIGHT(i) ((i) * 2 + 1)

#define SWAP(a, b) {\
    __typeof((a)) __c = (a);\
    (a) = (b);\
    (b) = __c;\
}

#define TEST(func, arr, n) {\
    printf("%s : ", #func);\
    int *tmp = (int *)malloc(sizeof(int) * n);\
    memcpy(tmp, arr, sizeof(int) * n);\
    long long s = clock();\
    func(tmp - 1, n);\
    long long e = clock();\
    if (check(tmp, n)) {\
        printf("NO ");\
    } else {\
        printf("YES ");\
    }\
    printf("%lld ms\n", 1000 * (e - s) / CLOCKS_PER_SEC);\
    free(tmp);\
}

int *getRandomArr(int size) {
    int *arr = (int *)malloc(sizeof(int) * size);
    arr = arr - ROOT;
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % size;
    }
    return arr;
}

int check(int *arr, int n) {
    for (int i = 2; i < n; i++) {
        if (arr[i - 1] CMP arr[i]) return 1;
    }
    return 0;
}


inline void up_maintain(int *arr, int i) {
    while (i CMP 1 && arr[i] CMP arr[FATHER(i)]) {
        SWAP(arr[i], arr[FATHER(i)]);
        i = FATHER(i);
    }
    return ;
}

inline void down_maintain(int *arr, int i, int n) {
    while (LEFT(i) <= n) {
        int ind = i, l = LEFT(i), r = RIGHT(i);
        if (l <= n && arr[l] CMP arr[ind]) ind = l;
        if (r <= n && arr[r] CMP arr[ind]) ind = r;
        if (ind == i) break;
        SWAP(arr[ind], arr[i]);
        i = ind;
    }
    return ;
}

inline void normal_heap_build(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        up_maintain(arr, i);
    }
    return ;
}

inline void liner_heap_build(int *arr, int n) {
    for (int i = n / 2; i > 1; i--) {
        down_maintain(arr, i, n);
    }
    return ;
}


void heap_sort_final(int *arr, int n) {
    for (int i = n; i > 1; i--) {
        SWAP(arr[1], arr[i]);
        down_maintain(arr, 1, i - 1);
    }
    return ;
}

void normal_heap_sort(int *arr, int n) {
    normal_heap_build(arr, n);//build;
    heap_sort_final(arr, n);//final
    return ;
}

void liner_heap_sort(int *arr, int n) {
    liner_heap_build(arr, n);//build
    heap_sort_final(arr, n);//final
    return ;
}

int main() {
    srand(time(0));
#define MAX_NUM 10000000
    int *arr = getRandomArr(MAX_NUM);
    TEST(normal_heap_sort, arr, MAX_NUM);
    TEST(liner_heap_sort, arr, MAX_NUM);
    return 0;
}
