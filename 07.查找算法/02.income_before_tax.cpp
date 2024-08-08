/*************************************************************************
	> File Name: 02.income_before_tax.cpp
	> Author: 
	> Mail: 
	> Created Time: Thu 08 Aug 2024 11:20:12 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define EXP 1e-7
#define MAX_N 1000000
#define min(a, b) ((a) > (b) ? (b) : (a))

double f(double x) {
    if (x >= 0) x -= min(x, 3000) * 0.03;
    if (x > 3000) x -= (min(x, 12000) - 3000) * 0.1;
    if (x > 12000) x -= (min(x, 25000) - 12000) * 0.2;
    if (x > 25000) x -= (min(x, 35000) - 25000) * 0.25;
    if (x > 35000) x -= (min(x, 55000) - 35000) * 0.3;
    if (x > 55000) x -= (min(x, 80000) - 55000) * 0.35;
    if (x > 80000) x -= (x - 80000) * 0.45;

    return x;
}

double binary_search_algorithm(double x) {
    double head = 0, tail = MAX_N, mid;

    while (tail - head >= EXP) {
        mid = (tail + head) / 2.0;
        if (f(mid) < x) {
            head = mid;
        } else {
            tail = mid;
        }
    }
    return head;
}


void test_binary_search_algorithm() {
    double x;
    while (scanf("%lf", &x)) {
        double money = binary_search_algorithm(x);
        printf("f(%0.6lf) = %lf\n", money, x);
    }
    return ;
}

int main() {
    test_binary_search_algorithm();
    return 0;
}
