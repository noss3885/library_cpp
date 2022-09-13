#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2991"
#include <iostream>
#include "../../src/graphs/strongly_connected_components.cpp"

int main(){
    int N, X, A, O;
    std::cin >> N >> X >> A >> O;
    if(X == 0){
        std::cout << "No" << std::endl;
        return 0;
    }
    TwoSAT ts(1<<(N+1));
    for(int i=0;i<(1<<(N+1));i++){
        ts.add_nand(i,i^X);
        ts.add_or(i,i^X);
    }
    for(int i=0;i<(1<<(N+1));i++){
        if((i&A) == A){
            int j = i^((1<<(N+1))-1), k = j;
            while(1){
                ts.add_nand(i, k|A);
                if(k==0) break;
                k = (k-1)&j;
            }
        }
    }
    for(int i=0;i<(1<<(N+1));i++){
        if((i|O) == O){
            int j = i, k = j;
            while(1){
                ts.add_nand(i,k^((1<<(N+1))-1)&O);
                if(k==0) break;
                k = (k-1)&j;
            }
        }
    }
    if(ts.build()){
        std::cout << "Yes" << std::endl;
        std::vector<int> ans;
        for(int i=0;i<(1<<(N+1));i++){
            if(ts[i]) ans.push_back(i);
        }
        for(int i=0;i<(1<<N);i++){
            std::cout << ans[i] << " \n"[i==(1<<N)-1];
        }
    }
    else{
        std::cout << "No" << std::endl;
    }
    return 0;
}
