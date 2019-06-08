/*
繰り返し二乗法
計算量 O(logN)
x^n べき乗を求める
*/
#include<bits/stdc++.h>

int64_t power(int64_t x, int n) { 
	int64_t ans = 1;
	while (n > 0) {
		if ((n & 1) == 1) {
			ans = ans * x;
		}
		x = x * x; //一周する度にx, x^2, x^4, x^8となる
		n >>= 1; //桁をずらす n = n >> 1
	}
	return ans;
}