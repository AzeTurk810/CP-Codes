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
#define N int(1e5 + 10)
#define int ll
map<int , int> stl[N];
vector<int> g[N];
pair<int , int> ans[N];
int c[N];

int n;
void in() {
    cin >> n;
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

void dfs(int v ,int &pa) {
    for(auto to : g[v]) {
        if(to == pa) 
            continue;
        dfs(to , v);
        if(stl[v].size() < stl[to].size()) {
            stl[v].swap(stl[to]);
            ans[v].swap(ans[to]);
        }
        for(auto it = stl[to].begin(); it != stl[to].end();it++) {
            stl[v][it->first] += it->second;
            if(stl[v][it->first] > ans[v].second) {
                ans[v].second = stl[v][it->first];
                ans[v].first  = it->first;
            } else if(ans[v].second == stl[v][it->first] && it->second != 0) {
                ans[v].first += it->first;
            }
        }
        if(stl[to].size() <= 1e3)
            std::map<int, int>().swap(stl[to]);
    }
    c[v] = ans[v].first;
}

void solve() {
    init();
    int p = -1;
    dfs(0 , p);
    for(int i = 0;i < n;i++) {
        cout << c[i] <<  ' ';
    }
    cout << ln;
}       

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    in();
    solve();
}
// Just Imaginary

