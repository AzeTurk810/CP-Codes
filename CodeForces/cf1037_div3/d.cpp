/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <algorithm>
#include <iostream>
#include <istream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct real {
    int l , r , a;
};

istream& operator>>(istream& in , real &x) {
    return in >> x.l >> x.r >> x.a;
}

ostream& operator<<(ostream& out , real &x) {
    return out << x.l << ' ' << x.r << ' ' << x.a;
}

bool comp(const real &a , const real &b) {
    if(a.a == b.a) 
        return a.l < b.l;
    return a.a < b.a;
}

int bs(const vector<real> &a , int x , int l = 0) {
    int _n = a.size();
    int r = _n - 1 , mid , ans = -1;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(a[mid].l <= x && x <= a[mid].r) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}

void solve() {
    int n ;
    ll k;
    cin >> n >> k;
    vector<real> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    sort(a.begin() , a.end() , comp);
    int ans = k , l = 0;
    for(int i = 0;i < n;i++) {
        if(a[i].l <= ans && ans <= a[i].a) {
            ans = a[i].a;
        }
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
