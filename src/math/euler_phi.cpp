// Euler's phi function
// O(sqrt(n))

#include<bits/stdc++.h>
using namespace std;

int euler_phi(int n){
    int res = n;
    for(int i=2;i*i<=n;i++){
        if(n%i == 0){
            res = res/i * (i-1);
            while(n%i==0) n /= i;
        }
    }
    if(n != 1) res = res/n *(n-1);
    return res;
}

vector<int> euler_table;

// O(n)
void build_euler_phi(int n){
    euler_table.resize(n+1);
    for(int i=0;i<=n;i++) euler_table[i] = i;
    for(int i=2;i<=n;i++){
        if(euler_table[i] == i){
            for(int j=i;j<=n;j+=i){
                euler_table[j] = euler_table[j]/i*(i-1);
            }
        }
    }
}
