
/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <set>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    int n;
    cin >> n;
    multiset<int> d;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        d.insert(x);
    }
    int x = *(--d.end());
    for(int i = 1;i * i <= x;i++) {
        if(x % i == 0) {
            d.erase(d.find(i));
            if(i * i != x) {
                d.erase(d.find(x / i));
            }
        }
    }
    cout << x << ' ' << *(--d.end()) << ln;
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
