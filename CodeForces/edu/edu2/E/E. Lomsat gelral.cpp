#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("fast-math")

/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: E. Lomsat gelral
Contest: Educational Codeforces Round 2
Judge: Codeforces
URL: https://codeforces.com/problemset/problem/600/E
Memory Limit: 256
Time Limit: 2000
Start: Mon 28 Jul 2025 09:36:02 PM +04
*/
#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <vector>


using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
#define map unordered_map

struct prob {
    int n;
    vector<int> c , last_ans;
    vector<vector<int>> g;
    vector<pair<int, int>> ans;         // solu sum , sagi maks cnt
    vector<map<int , int>> stl;         // cnt
    void in() {
        cin >> n;
        c.resize(n);
        g.resize(n);
        stl.resize(n);
        last_ans.resize(n);
        ans.assign(n , {0 , 0});
        for(int i = 0;i < n;i++) {
            cin >> c[i];
        }
        for(int i = 0;i < n - 1;i++) {
            int u , v;
            cin >> u >> v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    void init() {
        for(int i = 0;i < n;i++) {
            stl[i][c[i]]++;
            ans[i].first  = c[i];
            ans[i].second = 1;
        }
    }

    void dfs(int v , int pa = -1) {
        for(auto to : g[v]) {
            if(to == pa) 
                continue;
            dfs(to , v);
            if(stl[v].size() > stl[to].size()) {
                stl[v].swap(stl[to]);
                ans[v].swap(ans[to]);
            }
            ll temp , temp2 , cr , cnt;
            for(auto it = stl[to].begin(); it != stl[to].end();it++) {
                cr = it->first , cnt = it->second;
                temp2 = stl[v][cr];
                stl[v][cr] += cnt;
                temp = stl[v][cr];
                if(temp > ans[v].second) {
                    ans[v].second = temp;
                    ans[v].first  = cr;
                } else if(ans[v].second == temp && temp2 != ans[v].second) {
                    ans[v].first += cr;
                }
            }
            if(stl[to].size() <= 1e3)
                std::unordered_map<int, int>().swap(stl[to]);
        }
        last_ans[v] = ans[v].first;
    }

    void solve() {
        init();
        dfs(0);
        for(int i = 0;i < n;i++) {
            cout << last_ans[i] <<  ' ';
        }
        cout << ln;
    }
} prob;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    for(int cases = 0 ; cases < t;cases ++) {
         prob.in();
         prob.solve();
    }
}
// Just Imaginary
