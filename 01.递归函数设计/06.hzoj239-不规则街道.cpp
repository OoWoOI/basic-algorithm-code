/*************************************************************************
	> File Name: 06.hzoj239-不规则街道.cpp
	> Author: 
	> Mail: 
	> Created Time: Fri 28 Jun 2024 12:33:27 AM CST
 ************************************************************************/

#include<iostream>
#include<cmath>

using namespace std;

#define P(a) ((a) * (a))

void func(long long n, long long m, long long &x, long long &y) {
    
    if (n == 1) {
        if (m == 1) x = 0, y = 0;
        else if (m == 2) x = 0, y = 1;
        else if (m == 3) x = 1, y = 1;
        else x = 1, y = 0;
        return ;
    }
    
    long long xx, yy;
    long long L = 1LL << (n - 1);
    long long block = L * L;
    
    if (m <= block) {
        /*第一区域：(x, y) => (y, x)*/
        func(n - 1, m, xx, yy);
        x = yy, y = xx;
    } else if (m <= 2 * block) {
        /*第二区域：*/
        func(n - 1, m - block, xx, yy);
        //TODO: 坐标更新
        x = xx, y = yy + L;
    } else if (m <= 3 * block) {
        /*第三区域：*/
        func(n - 1, m - 2 * block, xx, yy);
        x = xx + L, y = yy + L;
    } else {
        /*第四区域：*/
        func(n - 1, m - 3 * block, xx, yy);
        //TODO: 坐标更新
        x = 2 * L - yy - 1, y = L - xx - 1;
    }

    return ;
}

int main() {
    /*需求：根据给定编号计算两个地点的直线距离*/
    long long t, n ,s, d;
    scanf("%lld", &t);
    
    while (t--) {
        scanf("%lld%lld%lld", &n, &s, &d);
        long long sx, sy, dx, dy;
        func(n, s, sx, sy);
        func(n, d, dx, dy);
        printf("%.0lf\n", 10 * sqrt(P(sx - dx) + P(sy - dy)));
    }
    
    
    return 0;
}
