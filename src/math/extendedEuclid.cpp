/*
拡張ユークリッド互除法
計算量
ax+by=gcd(a,b) となるx,yを求める
*/
int extgcd(int a, int b, int &x, int &y)
{
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