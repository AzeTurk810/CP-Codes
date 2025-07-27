/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <set>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define int ll

struct segmentTree {
    int N , Null_val;
    vector<int> t;

    segmentTree(int _n) {
        t.resize(_n * 4);
        N = _n;
         Null_val = 0;
    }

    void build(int v , int l , int r , vector<int> &a) {
        if(l == r) {
            t[v] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build((v << 1) , l , mid , a);
        build((v << 1)|1 , mid + 1 , r , a);
        t[v] = t[(v << 1)] + t[(v << 1)|1];
    }

    void upd(int v , int l , int r  , int val , int &pos) {
        if(l == r) {
            t[v] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= pos) upd((v << 1) , l , mid , val, pos);
        else upd((v << 1)|1 , mid + 1 , r , val , pos);
        t[v] = t[(v << 1)] + t[(v << 1)|1];
    }

    int ask(int v , int l , int r , int ql , int qr) {
        if(ql <= l && r <= qr) return t[v];
        if(ql > r || l > qr) return Null_val;
        int mid = (l + r) >> 1;
        return  (ask((v << 1) , l , mid , ql , qr) +
                   ask((v << 1)|1 , mid + 1 , r , ql , qr));
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    ll ans = 0;
    ans = n * (n + 1) >> 1LL;
    for(int i = 1;i < n;i++) {
        if(a[i] < a[i - 1]) {
            ans += (n - i )  * (i);
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
