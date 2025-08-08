/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: D - Enemy is weak
Contest: SegmentTree-Classic
Judge: Virtual Judge
URL: https://vjudge.net/contest/736637#problem/D
Memory Limit: 1024
Time Limit: 1000
Start: Mon 04 Aug 2025 09:16:57 PM +04
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

unordered_map<int , int> inv;

int compress(vector<int> a) {
    int n = a.size();
    sort(a.begin() , a.end());
    int temp = 0;
    inv[a[0]] = temp;
    for(int i = 1;i < n;i++) {
        if(a[i] != a[i - 1]) {
            temp++;
            inv[a[i]] = temp;
        } 
    }
    return temp + 1;
}

struct segmentTree {
    int N , Null_val;
    vector<ll> t;

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

    void upd(int v , int l , int r  , int val , int pos) {
        if(l == r) {
            t[v] += val;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= pos) upd((v << 1) , l , mid , val, pos);
        else upd((v << 1)|1 , mid + 1 , r , val , pos);
        t[v] = t[(v << 1)] + t[(v << 1)|1];
    }

    ll ask(int v , int l , int r , int ql , int qr) {
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
    int m = compress(a);
    segmentTree t(m) , p(m);
    ll ans = 0;
    for(int i = 0;i < n;i++) {
         ll temp = t.ask(1 , 0 , m - 1 , inv[a[i]] + 1 , m - 1);
         // cerr << a[i] << ' ' << inv[a[i]] << ' ' << temp << ln;
         ans += p.ask(1 , 0 , m - 1, inv[a[i]] + 1 , m - 1);
         p.upd(1 , 0 , m - 1, temp , inv[a[i]]);
         t.upd(1 , 0 , m - 1, 1 , inv[a[i]]);
    }
    cout << ans << ln;
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


