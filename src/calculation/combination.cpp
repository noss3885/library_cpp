/*
組み合わせ数計算 (再帰)
計算量O(N)
*/

typedef long long ll;

ll nCk(ll n, ll k) {
    if (k == 0)
        return 1;
    else
        return nCk(n, k - 1) * (n - k + 1) / k;
}