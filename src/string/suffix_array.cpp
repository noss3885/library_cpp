// Suffix Array
// construct O(|S|(log|S|)^2)
// contain O(|T|log|S|)
// 
// Longest Common Prefix Array
// construct O(|S|)

#include <bits/stdc++.h>
using namespace std;

// BEGIN

struct SuffixArray{
    int n, k;
    string s;
    vector<int> rank, tmp, sa;

    function<bool(const int&, const int&)> comp = [&](const int &i, const int &j){
        if(rank[i] != rank[j]) return rank[i] < rank[j];
        else{
            int ri = i+k <= n ? rank[i+k] : -1;
            int rj = j+k <= n ? rank[j+k] : -1;
            return ri < rj;
        }
    };
    void construct(const string &str){
        s = str;
        n = s.size();
        rank.resize(n+1);
        tmp.resize(n+1);
        sa.resize(n+1);

        for(int i=0;i<=n;i++){
            sa[i] = i;
            rank[i] = i < n ? s[i] : -1;
        }

        for(k = 1; k<=n; k<<=1){
            sort(sa.begin(), sa.begin()+n+1, comp);
            tmp[sa[0]] = 0;
            for(int i=1;i<=n;i++){
                tmp[sa[i]] = tmp[sa[i-1]] + (comp(sa[i-1],sa[i]) ? 1 : 0);
            }
            for(int i=0;i<=n;i++){
                rank[i] = tmp[i];
            }
        }
    }
    bool contain(const string &t){
        int a = 0, b = n;
        while(b-a > 1){
            int c = (a+b)/2;
            if(s.compare(sa[c], t.size(), t) < 0){
                a = c;
            }else{
                b = c;
            }
        }
        return s.compare(sa[b], t.size(), t) == 0;
    }
    // 辞書順でi番目であるsuffixの開始位置
    int operator[] (int i) const {
        return sa[i];
    }
};

struct LCP{
    int n;
    vector<int> rank;
    vector<int> lcp;
    SuffixArray sa;

    void construct(const string &str){
        int n = str.size();
        sa.construct(str);
        rank.resize(n+1);  // rank[i]=開始位置がiであるsuffixの辞書順位置
        lcp.resize(n);  // sa[i]とsa[i+1]の common prefix の長さ
        for(int i=0;i<=n;i++) rank[sa[i]] = i;

        int h = 0;
        for(int i=0;i<n;i++){
            int j = sa[rank[i]-1];
            if(h>0) h--;
            for(; j+h < n && i+h < n; h++){
                if(str[j+h] != str[i+h]) break;
            }
            lcp[rank[i]-1] = h;
        }
    }
    int operator[] (int i) const {
        return lcp[i];
    }
};

// END