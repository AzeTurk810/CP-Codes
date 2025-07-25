/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <string>
#include <string_view>
#include <uchar.h>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define K 64
vector<vector<pair<ll, set<ll>>>> dp(K , vector<pair<ll , set<ll>>>(K));


struct prob {
    ll x , y;
    void init() {
        x = y = 0;
        for(int i = 0;i < K;i++) {
            for(int j = 0;j < K;j++) {
                dp[i][j].first = INFll;
            }
        }
        dp[0][0] = {0 , {}};
        dp[1][0] = dp[0][1] = {2 , {1}};
        dp[0][2] = dp[2][0] = {4 , {2}};
        for(int i = 0;i < K;i++) {
            for(int j = 0;j < K;j++) {
                for(int x = 1;x < K;x++) {
                    if(dp[i][j].second.find(x) != dp[i][j].second.end())
                        continue;
                    if(j + x < K) {
                        if(dp[i][j + x].first > dp[i][j].first + (1LL << x)) {
                            dp[i][j + x].second = dp[i][j].second;
                            dp[i][j + x].first = dp[i][j].first + (1LL << x);
                            dp[i][j + x].second.insert(x);
                        }
                    }
                    if(i + x < K) {
                        if(dp[i + x][j].first > dp[i][j].first + (1LL << x)) {
//                            swap(i , j);
//                            dp[i][j + x].second = dp[i][j].second;
//                            dp[i][j + x].first = dp[i][j].first + (1LL << x);
//                            dp[i][j + x].second.insert(x);
                              dp[i + x][j].second = dp[i][j].second;
                              dp[i + x][j].second.insert(x);
                              dp[i + x][j].first = dp[i][j].first + (1LL << x);
                        }
                    }
                }
            }
        }
    }

    string con(ll x) {
        string res;
        while (x > 0) {
            res.push_back(char((x % 2) + '0'));
            x /= 2;
        }
        return res;
    }

    void in() {
        cin >> x >> y;
    }

    void solve() {
        string x_s = con(x) , y_s = con(y);
        int mn_size = min(x_s.size() , y_s.size());
        ll ans = dp[x_s.size()][y_s.size()].first;
        assert(dp[y_s.size()][x_s.size()].first == ans);
        for(int i = 0;i < mn_size;i ++) {
            if(x_s[i] != y_s[i])
                break;
            ans = min(dp[x_s.size() - 1 - i][y_s.size() - 1 - i].first , ans);
        }
        cout << ans << ln;
    }
} prob;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
         prob.init();
         prob.in();
         prob.solve();
    }
}
// Just Imaginary
