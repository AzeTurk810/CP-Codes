/*
Telebe of Adicto && Mamedov yani AzeTurk810.
I see humans but no humanity.
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int m , x;
    cin >> m >> x;
    vector<int> costs(m);
    int sum = 0;
    int ans = 0;
    for(int i = 0;i < m;i++) {
        cin >> costs[i];
        if(costs[i] <= sum) {
            sum -= costs[i];
            ans++;
        }
        sum += x;
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
