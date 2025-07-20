#include <bits/stdc++.h>
#include <cassert>
#include <iterator>
#include <vector>
using namespace std;
#define ln '\n'

vector<int> leafs , non_leafs ;
vector<vector<int>> g;
int rr;

bool ask(vector<int> vertices) {
    bool rev = false;
    if(vertices.size() == 1) {
        int n = leafs.size();
        vector<int> temp;
        for(int i = 0;i < n;i++) {
            if(leafs[i]  != vertices[0]) {
                temp.push_back(leafs[i]);
            }
        }
        rev = true;
        vertices = temp;
    }
    cout << "? " << vertices.size();
    for(int x: vertices) {
        cout << " " << x;
    }
    cout << endl << flush;
    string answer;
    cin >> answer;
    return (answer == "YES") ^ rev;
}

vector<char> used;

void init(int &n) {
    g.clear();
    g.resize(n);
    non_leafs.clear();
    leafs.clear();
    used.assign(n , false);
}

void anss(int l) {
    cout << "! " << l;
    cout.flush();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    
    init(n);
    
    for(int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
// return 0;
// return 0;
    for(int i = 0;i < n;i ++) {
        if(g[i].size() == 1) {
            leafs.push_back(i + 1);
        } else {
            non_leafs.push_back(i + 1);
        }
    }
    int l = 1 , r = n, mid;
    while(r - l >= 1) {
        mid = (l + r) >> 1;
        vector<int> temp;
        int cur = mid;
        int i = 0;
        while(cur > 0 && i < leafs.size()) {
            cur--;
            temp.push_back(leafs[i++]);
        }
        i = 0;
        while(cur > 0) {
            cur--;
            assert(i < non_leafs.size());
            temp.push_back(non_leafs[i++]);
        }
        bool flag = ask(temp);
        if(flag) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    assert(l == r);
    if(l <= leafs.size()) {
        cout << '!' << ' ' << leafs[l - 1] << ln;
    } else {
        l -= leafs.size() + 1;
        cout << "! " << non_leafs[l] << ln;
    }
    return 0;
}

