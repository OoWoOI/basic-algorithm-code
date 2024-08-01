/*************************************************************************
	> File Name: 0.sort_test.h
	> Author: 
	> Mail: 
	> Created Time: Wed 31 Jul 2024 08:49:33 PM CST
 ************************************************************************/

#ifndef _00_SORT_TEST_H
#define _00_SORT_TEST_H

#include<string.h>

#define CMP >
#define SMALL_DATA_NUM 5000
#define BIG_DATA_NUM 10000
#define SWAP(a, b) {\
    __typeof((a)) __c = (a);\
    (a) = (b);\
    (b) = __c;\
}

__attribute__((constructor))
void __init_rand() {
    printf("init rand\n");
    srand(time(0));
    return ;
}

int *getRandomArr(int n) {
    int *tmp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) tmp[i] = rand() % n;
    return tmp;
}

bool check(int *arr, int n) {
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] CMP arr[i]) return false;
    }
    return true;
}

#define TEST(func, arr, n) {\
    printf("TEST : %s", #func);\
    int *tmp = (int *)malloc(sizeof(int) * n);\
    memcpy(tmp, arr, sizeof(int) * n);\
    long long start = clock();\
    func(tmp, 0, n);\
    if (check(tmp, n)) {\
        printf("\tOK ");\
    } else {\
        printf("FAILE ");\
    }\
    long long end = clock();\
    printf("%ditems %lldms done!\n", n, 1000 * (end - start) / CLOCKS_PER_SEC);\
    free(tmp);\
}

#endif
