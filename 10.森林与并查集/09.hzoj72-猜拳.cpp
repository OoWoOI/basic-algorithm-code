/*************************************************************************
	> File Name: 09.hzoj72-猜拳.cpp
	> Author: 
	> Mail: 
	> Created Time: Tue 20 Aug 2024 06:54:51 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;

class WeightedUnionSet{
public :
    WeightedUnionSet(int n) : fa(n + 1), val(n + 1) {
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            val[i] = 0;
        }
    }   

    int get(int x) {
        if (fa[x] == x) return x;
        x = get(fa[x]);
        val[x] = (val[x];
        return fa[x] = x;
    }

    vector<int> fa, val;
};

int main() {
    
    
    return 0;
}
