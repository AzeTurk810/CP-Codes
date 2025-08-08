/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: F - Ant colony
Contest: SegmentTree-Classic
Judge: Virtual Judge
URL: https://vjudge.net/contest/736637#problem/F
Memory Limit: 1024
Time Limit: 1000
Start: Mon 04 Aug 2025 09:16:57 PM +04
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using ll = long long;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct node {
    int g , cnt;
};

struct segmentTree {
    int N ;
    node Null_val;
    std::vector<node> t;
    node marge(node l , node r) {
        node res;
        res.g = std::gcd(l.g , r.g);
        if(l.g == -1)
            return r;
        if(r.g == -1)
            return l;
        res.cnt = 0;
        if(l.g == res.g)
            res.cnt += l.cnt;
        if(r.g == res.g)
            res.cnt += r.cnt;
        return res;
    }

    segmentTree(int _n) {
        t.resize(_n * 4);
        Null_val = {-1 , 0};
        N = _n;
    }

    void build(int v , int l , int r , std::vector<int> &a) {
        if(l == r) {
            t[v] = {a[l] , 1};
            return;
        }
        int mid = (l + r) >> 1;
        build((v << 1) , l , mid , a);
        build((v << 1)|1 , mid + 1 , r , a);
        t[v] = marge(t[(v << 1)] , t[(v << 1)|1]);
    }

    void upd(int v , int l , int r  , int &val , int &pos) {
        if(l == r) {
            t[v] = {val , 1};
            return;
        }
        int mid = (l + r) >> 1;
        if(mid >= pos) upd((v << 1) , l , mid , val, pos);
        else upd((v << 1)|1 , mid + 1 , r , val , pos);
        t[v] = marge(t[(v << 1)] , t[(v << 1)|1]);
    }

    node ask(int v , int l , int r , int ql , int qr) {
        if(ql <= l && r <= qr) return t[v];
        if(ql > r || l > qr) return Null_val;
        int mid = (l + r) >> 1;
        return marge(ask((v << 1) , l , mid , ql , qr),
                   ask((v << 1)|1 , mid + 1 , r , ql , qr));
    }
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for(int i = 0;i < n;i++) {
        std::cin >> a[i];
    }
    segmentTree t(n);
    t.build(1 , 0 , n - 1, a);
    int q;
    std::cin >> q;
    while (q--) {
        int l , r;
        std::cin >> l >> r;
        l -- , r--;
        std::cout << r - l + 1 -  t.ask(1 , 0 , n - 1 , l , r).cnt << ln;
    }
    
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary


