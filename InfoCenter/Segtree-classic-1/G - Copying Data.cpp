/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: G - Copying Data
Contest: SegmentTree-Classic
Judge: Virtual Judge
URL: https://vjudge.net/contest/736637#problem/G
Memory Limit: 1024
Time Limit: 1000
Start: Mon 04 Aug 2025 09:16:57 PM +04
*/
#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <ostream>
#include <random>
#include <vector>

using ll = long long;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

struct node {
    int l , k;
    friend std::ostream& operator<<(std::ostream& os , const node& n) {
        os << '(' << ' ' << n.l << ' ' << n.k << " )" << std::endl;
        return os;
    }
};
int N;

struct segtree {
    std::vector<node> t;
    node Null_val;

    node marge(node l , node r) {
        if(l.k == -1)
            return r;
        if(r.k == -1)
            return l;
        // return ;
    }

    segtree (int n) {
        N = n;
        t.assign((n << 2) , {1 , -1});
    }

    void build(std::vector<int> &a ,int v = 1 , int l = 0 ,int r = N - 1) {
        if(l == r) {
            t[v] = {a[l] , -1};
            return;
        }
        int mid = (l + r) >> 1;
        build(a , (v << 1) , l , mid);
        build(a , (v << 1)|1 , mid + 1 , r);
        t[v] = {0 , -1};
    }
    
    void upd(int v , int l , int r , int ql , int qy , int qk) {
        // std::cerr << v << ':' << l << ' ' << r << ' ' << r - l + 1 << ' ' << qk << std::endl;
        if(qk == 0)
            return;
        if(l == qy || r - l + 1 == qk) {
            t[v] = {ql , qk};
            return;
        } else {
            // assert(l != r);
        }
        int mid = (l + r) >> 1;
        int left_len  = std::max(0, std::min(qk, mid - qy + 1));
        int right_len = qk - left_len;
        upd(v<<1,      l,    mid, ql, qy,         left_len);
        upd(v<<1|1, mid+1,    r,  ql + left_len, qy + left_len, right_len);
        t[v] = {0 , -1};
    }

    node ask(int v , int l , int r , int pos) {
        // std::cerr << t[v] << ' ' << l << ' ' << r << '|' << v << std::endl;
        // std::cerr << v << ' ' << ((v << 1)|1) << ' ' <<  (N << 2) - 1 << std::endl;
        if(l == r || t[v].k != -1) {
            if(t[v].k == -1)
                return t[v];
            else {
                return {t[v].l + pos - l, 0};
            }
        }
        int mid = (l + r) >> 1;
        if(mid >= pos) {
            return ask((v << 1) , l , mid , pos);
        } else {
            return ask((v << 1)|1 , mid + 1 , r , pos);
        }
    } 

    int query(int pos , std::vector<int> &a) {
        node res = ask(1 , 0 , N - 1,pos);
        if(res.k == -1)
            return res.l;
        else {
            // std::cerr << res.l << ' ' << res.k << std::endl;
            return a[res.l];
        }
    }

    void update(int x , int y , int k) {
        upd(1 , 0 , N - 1, x , y , k);
    } 

};

void solve() {
    int n , m;
    std::cin >> n >> m;
    std::vector<int> a(n) , b(n);
    for(int &i : a) 
        std::cin >> i;
    for(int &j : b)
        std::cin >> j;
    segtree tt(n);
    tt.build(b);
    while (m--) {
        int t;
        std::cin >> t;
        if(t == 1) {
            int x , y , k;
            std::cin >> x >> y >> k;
            x--;y--;
            // std::cerr << x << ' ' << y << ' ' << k << ' ' << n << ' ' << x + k << ' ' << y + k << std::endl; 
            assert(x + k <= n);
            assert(y + k <= n);
            // k--/
            tt.update(x , y , k);
        } else {
            int pos;
            std::cin >> pos;
            pos--;
            std::cout << tt.query(pos , a) << ln;
        }
    }
    
}

signed main() {
    // ios::sync_with_stdio(0);
    // cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
        solve();
    }
}
// Just Imaginary


