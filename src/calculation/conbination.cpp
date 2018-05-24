/*
組み合わせ数計算 (再帰)
計算量O(N)
*/

long long ncr(int n, int r){
    if(r==0)
        return 1;
    else
        return ncr(n,r-1)*(n-r+1)/r;
}