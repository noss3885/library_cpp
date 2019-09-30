/*
Fast Fourier Transform
O(NlogN)
*/

#include <bits/stdc++.h>
using namespace std;

using Real = double;
//using Complex = complex<Real>;

struct Complex{
    Real x, y;
    Complex():x(0),y(0){};
    Complex(Real x, Real y):x(x),y(y){};
};

inline Complex conj(Complex a){
    return Complex(a.x, -a.y);
}
inline Complex operator+(Complex a, Complex b){
    return Complex(a.x+b.x, a.y+b.y);
}
inline Complex operator-(Complex a, Complex b){
    return Complex(a.x-b.x, a.y-b.y);
}
inline Complex operator*(Complex a, Complex b){
    return Complex(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);
}
inline Complex operator/(Complex a, Complex b){
    Complex tmp = a*conj(b);
    return Complex(tmp.x/(b.x*b.x+b.y*b.y), tmp.y/(b.x*b.x+b.y*b.y));
}

const Real PI = acos(-1);

/*
vector<Complex> DFT(vector<Complex> &a){
    int n = a.size();
    if(n == 1) return a;

    vector<Complex> a0(n>>1), a1(n>>1);

    // 偶奇で分ける
    for(int i=0;i<n;i++){
        if(i&1) a1[i>>1] = a[i];
        else a0[i>>1] = a[i];
    }
    // 分割統治
    auto inversed_a0 = DFT(a0);
    auto inversed_a1 = DFT(a1);

    // f(x) = f0(x^2) + x*f1(x^2)
    vector<Complex> inversed_a(n);
    for(int i=0;i<n;i++){
        Real theta = 2*PI*i/n;
        Complex zeta_n_i = Complex(cos(theta), sin(theta));
        inversed_a[i] = inversed_a0[i%(n>>1)] + zeta_n_i * inversed_a1[i%(n>>1)];
    }
    return inversed_a;
}

vector<Complex> IDFT(vector<Complex> &inversed_a){
    int n = inversed_a.size();

    auto arranged = DFT(inversed_a);

    // 係数を入れ替えてnで割る
    vector<Complex> a(n);
    for(int i=0;i<n;i++){
        a[i] = arranged[(n-i)%n]/Complex(n,0);
    }
    return a;
}
*/

vector<Complex> FFT(vector<Complex> a, bool rev = false){
    int n = a.size();
    int h = 0;
    for(int i=0;1<<i<n;i++) h++;
    // bitを逆転させ対応する位置とswap
    for(int i=0;i<n;i++){
        int j = 0;
        for(int k=0;k<h;k++){
            j |= (i>>k&1) << (h-1-k);
        }
        if(i<j) swap(a[i], a[j]);
    }
    for(int i=1;i<n;i<<=1){
        for(int j=0;j<i;j++){
            Real theta = 2*PI/(i*2)*(rev?-1:1)*j;
            Complex w = Complex(cos(theta), sin(theta));
            for(int k=0;k<n;k+=i*2){
                Complex s = a[j+k+0];
                Complex t = a[j+k+i]*w;
                a[j+k+0] = s+t;
                a[j+k+i] = s-t;
            }
        }
    }
    if(rev) for(int i=0;i<n;i++) a[i] = a[i]/Complex(n,0);
    return a;
}

vector<Complex> convolute(vector<Complex> &a, vector<Complex> &b){
    int deg = int(a.size() + b.size()) - 1;
    int n = 1;
    while(n < deg) n <<= 1;
    a.resize(n); b.resize(n);

    vector<Complex> inversed_a = FFT(a);
    vector<Complex> inversed_b = FFT(b);
    vector<Complex> inversed_c(n);

    for(int i=0;i<n;i++){
        inversed_c[i] = inversed_a[i] * inversed_b[i];
    }
    vector<Complex> c = FFT(inversed_c, true);
    return c;
}


// TEST
// https://atcoder.jp/contests/atc001/tasks/fft_c
int main(){
    int n;
    scanf("%d",&n);
    vector<Complex> a(n+1), b(n+1), c(n+1);
    for(int i=1;i<=n;i++){
        double ai, bi;
        scanf("%lf",&ai);
        scanf("%lf",&bi);
        a[i] = Complex(ai,0);
        b[i] = Complex(bi,0);
    }
    c = convolute(a,b);
    for(int i=1;i<=n*2;i++){
        printf("%d\n",int(c[i].x+.1));
    }
    return 0;
}