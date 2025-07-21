/*
 * TODO : Query1 handle , Query2 handle , updater , asker;
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
*/
#include <iostream>
#include <utility>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define D 400

struct prob {
    vector<vector<int>> g;
    vector<int> a;
    vector<pair<int, int>> edges;
    int n , m , t;

    int pos[D + 1][D + 1];
    ll mask[51];

    void in() {
        cin >> n >> m;
        g.resize(n);
        edges.resize(m);
        for(int i = 0;i < m;i++) {
            int u , v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            edges[i] = {u , v};
        }
        cin >> t;
        a.resize(t);
        for(int i = 0;i < t;i++) {
            cin >> a[i];
            a[i]--;
        }
    }

    void init_m() {
        for(int i = 0;i < n;i++) {
            mask[i] = (1LL << i);
        }
    }

    void build() {
        for(int i = 0;i < t / D;i++) {
            if((i + 1) * D >= t)
                break;
            init_m();
            for(int j = i * D;j < (i + 1) * D;j++) {
                mask[edges[a[j]].second] |= mask[edges[a[j]].first];
                if(edges[a[j]].first == edges[a[j]].second) {
                    continue;
                }
                mask[edges[a[j]].first] = 0LL;
            }

            for(int j = 0;j < n;j++) {
                for(int k = n - 1;k >= 0;k--) {
                    if(mask[j] & (1ll << k)) {
                        pos[i][k] = j;
                    }
                }
            }
        }
    }

    void update(int ps , int val) {
        a[ps] = val;
        if(((ps / D) + 1) * D >= t)
            return;
        int l = ps / D;
        init_m();
        for(int i = l * D;i < (l + 1) * D;i++) {
            mask[edges[a[i]].second] |= mask[edges[a[i]].first];
            if(edges[a[i]].second != edges[a[i]].first) {
                mask[edges[a[i]].first] = 0LL;
            }
        }
        for(int j = 0;j < n;j++) {
            for(int k = n - 1;k >= 0;k--) {
                if(mask[j] & (1ll << k)) {
                    pos[l][k] = j;
                }
            }
        }
    }

    int ask(int l , int r , int s) {
        int ll = (l) / D , rr = r / D;
        ll++;
        for(int i = l;(i < ll * D) && i <= r;i++) {
            if(edges[a[i]].first == s) {
                s = edges[a[i]].second;
            }
        }
        
        for(int i = ll;i < rr;i++) {
            s = pos[i][s];
        }

        if(ll != rr) {
            for(int i = (rr * D);i <= r;i++) {
                if(edges[a[i]].first == s) {
                    s = edges[a[i]].second;
                }
            } 
        }

        return s;
    }

    void solve() {
        build();
        int q;
        cin >> q;
        while(q--) {
            int tt;
            cin >> tt;
            if(tt == 1) {
                int l , r , s;
                cin >> l >> r >> s;
                l--;r--;s--;
                cout << 1 + ask(l , r , s) << ln;
            } else {
                int pos , val;
                cin >> pos >> val;
                pos--;val--;
                update(pos , val);
            }
        }
    }
} prob;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
//    cin >> t;
    for(int cases = 0 ; cases < t;cases ++) {
         prob.in();
         prob.solve();
    }
}
// Just Imaginary

