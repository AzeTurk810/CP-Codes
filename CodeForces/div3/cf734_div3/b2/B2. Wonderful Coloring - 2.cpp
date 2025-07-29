/*
Telebe of Adicto && Mamedov yani AzeTurk810
I see humans but no humanity
Problem: B2. Wonderful Coloring - 2
Contest: Codeforces Round 734 (Div. 3)
Judge: Codeforces
URL: https://codeforces.com/contest/1551/problem/B2
Memory Limit: 256
Time Limit: 2000
Start: Tue 29 Jul 2025 10:03:45 AM +04
*/
#include <iostream>
#include <set>
#include <vector>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18
int n , k;

bool f(int mid,const vector<int> &a , vector<int> &ans) {
    int cnt = 0;
    set<int> st;
    vector<char> used(a.size() , false);
    int cur = 0;
    vector<int> cc(n , 0);
    for(int j = 1;j <= k;j++) {
        for(int i = 0;i < n;i++) {
            if(used[i])
                continue;
            if(st.find(a[i]) != st.end())
                continue;
            cc[i] = j;
            used[i] = true;
            cnt++;
            st.insert(a[i]);
            if(cnt >= mid) {
                cnt = 0;
                st.clear();
                cur++;
                break;
            }
        }
    }
    if(cur == k) {
        for(int i = 0;i < n;i++) {
            ans[i] = cc[i];
        }
    }
    return cur == k;
} 
vector<int> ans;

void solve() {
    int n , k;
    cin >> n >> k;
    ans.assign(n , 0);
    vector<int> a(n);
    for(int i = 0;i < n;i++ ) {
        cin >> a[i];
    }
    vector<vector<int>> ind(n + 1);
    int cnt = 0;
    for(int i = 0;i < n;i++) {
        if(ind[a[i]].size() < k)
            ind[a[i]].push_back(i) , cnt++;
    }
    cnt = (cnt / k * k);
    int col = 0;
    for(int i = 0;i <= n;i++) {
        for(int j = 0;j < ind[i].size();j++) {
            ans[ind[i][j]] = ++(col);
            col %= k;
            cnt--;
            if(cnt == 0)
                return;
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
        for(int i = 0;i < ans.size();i++) {
            cout << ans[i] << ' ';
        }
        cout << ln;
    }
}
// Just Imaginary

