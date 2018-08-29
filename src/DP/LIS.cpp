/*
LIS 最長増加部分列
O(NlogN)
*/
#include <algorithm>
#include <vector>
using namespace std;

const int IINF = INT_MAX;
int n;
vector<int> a, dp;

int lis() {
    dp.resize(n+1,IINF);
    for (int i = 0; i < n; i++) {
        *lower_bound(dp.begin(),dp.end(),a[i]) = a[i];
    }
    return lower_bound(dp.begin(),dp.end(),IINF) - dp.begin();
}