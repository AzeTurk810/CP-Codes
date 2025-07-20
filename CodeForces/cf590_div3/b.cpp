/*
Telebe of Adicto && AzeTurk810 yani AzeTurk810
I see humans but no humanity
*/
#include <deque>
#include <iostream>
#include <set>

using ll = long long;
using namespace std;

#define ln '\n'
#define INFi 1e9
#define INFll 1e18

void solve() {
    deque<int> dq;
    int n , k;
    cin >> n >> k;
    set<int> st;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        if(st.find(x) != st.end()) {
            continue;
        } else {
            if(st.size() < k) {
                st.insert(x);
                dq.push_front(x);
            } else {
                st.erase(st.find(dq.back()));
                dq.pop_back();
                st.insert(x);
                dq.push_front(x);
            }
        }
    }
    cout << dq.size() << ln;
    for(int &i : dq) {
        cout << i<< ' ';
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
