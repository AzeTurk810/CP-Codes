/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define _K 26

struct LazySegmentTree {
    int N;
    struct point {
        int a, b, c, d;
        bool is = 0;
    };
    vector<point> t;
    vector<long long> lazy;


    bool f(int a , int b , int c , int d) {
        return 
            a == c ||
            b == d ||
            b == c
            ;
    }

    LazySegmentTree(int _n) {
        N = _n;
        t.assign(4 * N , {0 , 0, 0, 0, 0});
        lazy.assign(4 * N , 0);
    }

    point merge2(point _l , point _r , pair<int, int> l , pair<int,int> r) {
        point res;
        assert(!(_l.a == -1 && _r.a == -1));
        if(_l.a == -1) {
            return _r;
        } else if(_r.a == -1) {
            return _l;
        }
        res.is |= _l.is || _r.is;
        res.is |= (
                _l.d == _r.a ||
                _l.c == _r.a ||
                _l.d == _r.b
                );
        return res;
    }

    point merge(point b, point c, int l, int r) {
        point a;
        int m = (l + r) / 2;
        a.a = b.a;
        a.d = c.d;
        if (m - l + 1 == 1 && r - m == 1) {
            a.b = c.a;
            a.c = b.a;
            a.is = (a.a == a.d);
        }
        else if (m - l + 1 == 1) {
            a.b = c.a;
            a.c = c.c;
            a.is = (b.d == c.a || b.a == c.b || c.is);
        }
        else if (r - m == 1) {
            a.b = b.b;
            a.c = b.d;
            a.is = (b.d == c.a || b.c == c.a || b.is);
        }
        else {
            a.b = b.b;
            a.c = c.c;
            a.is = (b.d == c.a || b.c == c.a || b.d == c.b || b.is || c.is);
        }
        return a;
    }

    void push(int v, int l, int r) {
        lazy[v] %= _K;
        if(lazy[v]) {
            ll &o = lazy[v];
            t[v].a += o;
            t[v].b += o;
            t[v].c += o;
            t[v].d += o;
            t[v].a %= _K;
            t[v].b %= _K;
            t[v].c %= _K;
            t[v].d %= _K;
            if(l != r) {
                lazy[(v << 1)] += lazy[v];
                lazy[(v << 1) | 1] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void build(int v, int l, int r , string &s) {
        if(l == r) {
            s[l] -= 'a';
            t[v] = {s[l] , s[l] , s[l] , s[l] , 0};
            return;
        }
        int mid = (l + r) >> 1;
        build((v << 1) , l , mid , s);
        build((v << 1) | 1 , mid + 1 , r , s);
        t[v] = merge(t[(v << 1)] , t[(v << 1) | 1] , l  , r);
    }

    void update(int v, int l, int r, int ql, int qr, int val) {
        push(v, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[v] += val;
            push(v, l, r);
            return;
        }
        int mid = (l + r) >> 1;
        update((v << 1), l, mid, ql, qr, val);
        update((v << 1) | 1, mid+1, r, ql, qr, val);
        t[v] = merge(t[(v << 1)] , t[(v << 1) | 1] , l , r);
    }
    void upd(int l , int  r , int val) {
        update(1 , 0 , N - 1,l , r , val);
    }

    point query(int v, int l, int r, int ql, int qr) {
        push(v, l, r);
        if (qr < l || r < ql) return {-1 , -1 , -1 , -1 ,0};
        if (ql <= l && r <= qr) return t[v];
        int mid = (l + r) >> 1;
        point r1 = query(v*2, l, mid, ql, qr) , r2 = query(v*2+1, mid+1, r, ql, qr);
        if(r1.a == -1) 
            return r2;
        else if(r2.a == -1)
            return r1;
        return merge(r1 , r2 , l , r);;
    }
};

void solve() {
    int n , m;
    cin >> n >> m;
    string s;
    cin >> s;
    LazySegmentTree t(n);
    t.build(1 , 0 , n - 1,s);
    while(m--) {
        int tt;
        cin >> tt;
        if(tt == 1) {
            int l , r , x;
            cin >> l >> r >> x;
            t.upd(--l,--r,x);
        } else {
            int l , r;
            cin >> l >> r;
            --l,--r;
            if(t.query(1 , 0 , n - 1 , l , r).is) {
                cout << "No" << ln;
            } else {
                cout << "Yes" << ln;
            }
        }
    }
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
