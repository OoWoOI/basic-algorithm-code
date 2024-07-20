/*************************************************************************
	> File Name: 04.haffchar.cpp
	> Author: 
	> Mail: 
	> Created Time: Wed 17 Jul 2024 10:26:36 AM CST
 ************************************************************************/

#include<iostream>
#include<time.h>
using namespace std;
int main() {
    srand(time(0));
    printf("26\n");

    for (int i = 0; i < 26; i++) {
        printf("%c %d\n", i + 'a', rand() % 10000);
    }
    return 0;
}
