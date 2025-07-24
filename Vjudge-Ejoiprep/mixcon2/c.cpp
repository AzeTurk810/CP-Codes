/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

struct prob {
    int n , m , k;
    vector<vector<int>> a , dp;
    void init() {
        n = m = 0;
        a.clear();
    }
    void in() {
        cin >> n >> m >> k;
        a.resize(n , vector<int>(m));
        dp.assign(n , vector<int>(m , INFll));
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cin >> a[i][j];
            }
        }
    }
    void solve() {
        for(int i = 0;i < n;i++) {
            for(int s = 0;s < m;s++) {
                vector<int> tmp(m , INFll);
                for(int j = 0;j < m;j++) {
                    if(i)
                        tmp[j] = dp[i - 1][j] + s * k + a[i][(j + s) % m];
                    if(!i && !j) {
                        tmp[j] = s * k + a[i][(j + s) % m];
                    }
                }
                for(int j = 0;j < m;j++) {
                    int w = a[i][(j + s) % m] , cur = (j + s) % m;
//                    if(i ==0 && j == 0) {
//                        dp[i][j] = min(tmp[0] , w + (k * s));
//                    }
                    if(j) {
                        tmp[j] = min(tmp[j] , tmp[j - 1] + w);
                    }
                }
                for(int j = 0;j < m;j++) {
                    dp[i][j] = min(tmp[j] , dp[i][j]);
                }
            }
        }
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cerr << dp[i][j] << ' ';
            }
            cerr << ln;
        }
        cout << dp[n - 1][m - 1] << ln;
    }
} prob;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
         prob.init();
         cerr << "Init" << endl;
         prob.in();
         cerr << "IN true" << endl;
         prob.solve();
         cerr << "comp true" << endl;
    }
}
// Just Imaginary
