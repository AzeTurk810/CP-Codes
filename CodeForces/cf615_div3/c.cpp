/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <array>
#include <iostream>
#include <utility>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

pair<int, int> ff(int n , int nu) {
    for(int i = 2;i * i < n;i++) {
        if(n % i == 0) {
            if(n /i != nu && i != nu)
                return {n / i , i};
        }
    }
    return {-1 , -1};
}

array<int, 3> f(int n) {
    int f = -1;
    for(int i = 2;i * i<= n;i++) {
        if(n % i == 0) {
            f = i;
            break;
        }
    }
    if(f == -1) {
        return {-1 , -1 , -1};
    }
    auto k = ff(n / f , f);
    if(k.second == -1) {
        return {-1 , -1 , -1};
    }
    return {f , k.first , k.second};
}

void solve() {
    int n;
    cin >> n;
    auto res = f(n);
    if(res[1] == -1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << res[0] << ' ' << res[1] << ' ' << res[2] << ln;
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
