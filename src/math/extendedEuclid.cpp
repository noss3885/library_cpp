/*
拡張ユークリッド互除法
計算量 O(log(m)^2)
ax+by=gcd(a,b) となるx,yを求める
modの逆元を求める
*/

int extgcd(int a, int b, int &x, int &y) {
    int d = a;
    if (b == 0) {
        x = 1;
        y = 0;
    } else {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    }
    return d;
}

int mod_inv(int a, int m) {
    int a_, q;
    extgcd(a, m, a_, q);
    return a_;
}