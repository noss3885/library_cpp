/*
最長共通部分列(Longest Common Subsequence)
計算量 O(ST)
*/

#include <string>
#include <algorithm>
using namespace std;

const int MAX_N = int(1e3) + 5;

int dp[MAX_N][MAX_N];
string s, t;

int lcs() {
    for (int i = 0; i <= s.size(); i++) fill(dp[i], dp[i] + t.size() + 1, 0);
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
        }
    }
    return dp[s.size()][t.size()];
}

//復元
string get_lcs() {
    int i = s.size(), j = t.size();
    string res = "";
    while (i > 0 && j > 0) {
        if (dp[i][j - 1] == dp[i][j]) {
            j--;
        } else if (dp[i - 1][j] == dp[i][j]) {
            i--;
        } else {
            res += s[i - 1];
            i--;
            j--;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}
