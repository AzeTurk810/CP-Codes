/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define up int(1e4 + 10)
#define int ll

char is_prime[up];

void sieve() {
    is_prime[2] = true;
    for(int i = 3;i < up;i+=2) {
        is_prime[i] = true;
    }
    for(int i = 3;i * i < up;i+=2) {
        if(is_prime[i]) {
            for(int j = i * i;j < up;j+=i) 
                is_prime[j] = false;
        }
    }
}

ll lca(ll a , ll b) {
    return (a * b) / gcd(a , b);
}

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    int mx = 0;
    for(int &i : d) {
        cin >> i;
        mx = max(mx , i);
    }
    int x = 1 , y = 1;
    sort(d.begin() , d.end());
    mx = min(mx , 10000LL);
    for(int i = 0;i < n;i++) {
        if((i && d[i] == d[i - 1]) || (lca(d[i] , x) > mx && lca(d[i] , y) < mx)) {
            y = lca(d[i] , y);
        } else {
            x = lca(d[i] , x);
        }
    }
    cout << x << ' ' << y << ln;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    sieve();
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary

