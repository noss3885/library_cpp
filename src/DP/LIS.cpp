/*
LIS 最長増加部分列
O(N^2)
*/
#include <algorithm>
using namespace std;

const int MAX_N = 1000;
int n, a[MAX_N], dp[MAX_N];

void lis() {
    for (int i = 0; i < n; i++) fill(dp[i], dp[i] + n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) dp[i + 1] = max(dp[i + 1], dp[j] + 1);
        }
    }
}