/*
拡張ユークリッド互除法
計算量 O(log(m)^2)
ax+by=gcd(a,b) となるx,yを求める
modの逆元を求める
*/

int extgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    } else {
        int d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return d;
    }
}

int mod_inv(int a, int m) {  // a^-1 mod m
    int a_, q;
    extgcd(a, m, a_, q);
    if (a_ < 0) {
        a_ += m;
    }
    return a_;
}