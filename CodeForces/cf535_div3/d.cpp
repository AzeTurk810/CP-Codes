/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

map<char , int> rev;
char ver[] = {'R' , 'B' , 'G'};

void solve() {
    int n;
    cin >> n;
    rev['R'] = 0;
    rev['B'] = 1;
    rev['G'] = 2;
    string s , res;
    cin >> s;
    vector<vector<int>> dp(n , vector<int> (3)) , pa(n , vector<int>(3, -1));
    for(int j = 0; j <3;j++) {
        dp[0][j] = 1;
    }
    dp[0][rev[s[0]]] = 0;
    for(int i = 1;i < n;i++) {
        for(int j = 0;j < 3;j++) {
            if(rev[s[i]] == j) {
                dp[i][j] = min(dp[i - 1][(j + 1) % 3] , dp[i - 1][(j + 2) % 3]);
                if(dp[i - 1][(j + 1) % 3] == dp[i - 1][(j + 2) % 3] && j != rev[s[i - 1]]) {
                    pa[i][j] = rev[s[i - 1]];
                } else if(min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) == dp[i - 1][(j + 1) % 3]) {
                    pa[i][j] = (j + 1) % 3;
                } else {
                    pa[i][j] = (j + 2) % 3;
                }
            } else {
                dp[i][j] = min(dp[i - 1][(j + 1) % 3] , dp[i - 1][(j + 2) % 3]) + 1;
                if(dp[i - 1][(j + 1) % 3] == dp[i - 1][(j + 2) % 3] && j != rev[s[i - 1]]) {
                    pa[i][j] = rev[s[i - 1]];
                } else if(min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) == dp[i - 1][(j + 1) % 3]) {
                    pa[i][j] = (j + 1) % 3;
                } else {
                    pa[i][j] = (j + 2) % 3;
                }
            }
        }
    }
    res.resize(n);
    int minj = min_element(dp[n - 1].begin() , dp[n - 1].end()) - dp[n - 1].begin();
    int cur = minj;
    pa[0] = {0 , 0, 0};
    for(int i = n - 1;i >= 0;i--) {
        res[i] = ver[cur];
        assert(pa[i][cur] != -1); 
        cur = pa[i][cur];
    }
    cout << min({dp[n - 1][0] , dp[n - 1][1] , dp[n - 1][2]})  << ln;
    cout << res << ln;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary
