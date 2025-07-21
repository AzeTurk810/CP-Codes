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
    int n;
    vector<int> f;
    void init() {
        
    }
    void in() {
        cin >> n;
        f.resize(n + 1);
        for(int i = 0;i < n;i++) {
            cin >> f[i];
        }
        f[n] = 1;
    }
    void solve() {
        bool ok = true;
        int ans = 0 , cur = 1;
        for(int i = n - 1;i >= 0;i--) {
            if(f[i] >= cur) 
                continue;
            ans += cur - f[i];
            cur += cur - f[i];
        }
        cout << ans + 1<< ln;
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
