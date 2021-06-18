#include <iostream>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    for (int i=1; i < 10; i++) {
        printf("%d * %d = %d\n", n, i, n * i);
    }
}