/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: A - Xenia and Bit Operations
Contest: SegmentTree-Classic
Judge: Virtual Judge
URL: https://vjudge.net/contest/736637#problem/A
Memory Limit: 1024
Time Limit: 1000
Start: Mon 04 Aug 2025 09:16:57 PM +04
*/
#include <iostream>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct segmentTree {
    int N , Null_val;
    vector<int> t;

    segmentTree(int _n) {
        t.resize(_n * 4);
        N = _n;
         Null_val = 0;
    }

    void build(int v , int l , int r , vector<int> &a , int cur) {
        if(l == r) {
            t[v] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build((v << 1) , l , mid , a , cur ^ 1);
        build((v << 1)|1 , mid + 1 , r , a , cur ^ 1);
        if(cur)
            t[v] = t[(v << 1)] | t[(v << 1)|1];
        else 
            t[v] = t[(v << 1)] ^ t[(v << 1)|1];
    }

    void upd(int v , int l , int r  , int &val , int &pos ,int cur) {
        if(l == r) {
            t[v] = val;
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= pos) upd((v << 1) , l , mid , val, pos , cur ^ 1);
        else upd((v << 1)|1 , mid + 1 , r , val , pos , cur ^ 1);
        if(cur)
            t[v] = t[(v << 1)] | t[(v << 1)|1];
        else 
            t[v] = t[(v << 1)] ^ t[(v << 1)|1];
    }

    int ask(int v , int l , int r , int ql , int qr) {
        if(ql <= l && r <= qr) return t[v];
        if(ql > r || l > qr) return Null_val;
        int mid = (l + r) >> 1;
        return  (ask((v << 1) , l , mid , ql , qr) |
                   ask((v << 1)|1 , mid + 1 , r , ql , qr));
    }
};

void solve() {
    int n , m;
    cin >> n >> m;
    vector<int> a((1 << n));
    for(int i = 0;i < (1 << n);i++) {
        cin >> a[i];
    }
    segmentTree t((1 << n));
    t.Null_val = 0;
    bool ok = n & 1;
    t.build(1 , 0 , (1 << n) - 1 , a , ok);
    while (m--) {
        int p , b;
        cin >> p >> b;
        p--;
        t.upd(1 , 0 , (1 << n) - 1 , b , p , ok);
        cout << t.t[1] << ln;
    }
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


