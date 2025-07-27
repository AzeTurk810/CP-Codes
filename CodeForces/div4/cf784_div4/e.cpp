/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

const int K = 26;

void solve() {
    ll ans = 0;
    int n;
    cin >> n;
    vector<pair<char, char>> a(n);
    vector<vector<int>> cnt(K , vector<int>(K , 0));
    for(auto &[l , r]:a) {
        cin >> l >> r;
    }
    for(auto &[l , r] : a) {
        l -= 'a';
        r -= 'a';
        for(int i = 0;i < K;i++) {
            if(i == r)
                continue;
            ans += cnt[l][i]; 
        }
        for(int j = 0;j < K;j++){
            if(j == l)
                continue;
            ans += cnt[j][r];
        }
        cnt[l][r]++;
    }
    cout << ans << ln;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary
