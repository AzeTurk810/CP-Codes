#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        vector<int>a(n);
        for(int &x: a) 
            cin >> x;

        // 1) Build freq[0..n]
        vector<int> freq(n+1, 0);
        for(int x: a){
            if(x <= n) 
                freq[x]++;
        }

        // 2) We'll be marking intervals [L_m, R_m] in diff[0..n+1]
        vector<int> diff(n+2, 0);

        // 3) Sweep m=0..n, maintaining that all x<m appear
        bool ok = true;
        for(int m = 0; m <= n; m++){
            if(m > 0 && freq[m-1] == 0){
                ok = false;  // we just lost the ability to make MEX m
            }
            if(!ok) break;

            int L = freq[m];       // must delete every copy of m
            int R = n - m;         // can delete everything except one of each < m
            if(L <= R){
                diff[L]   += 1;     // intervals covering k start
                diff[R+1] -= 1;     // and end just after R
            }
        }

        // 4) Prefix‐sum diff to get, for each k=0..n, the count of m-intervals covering k
        vector<int> ans(n+1);
        int cur = 0;
        for(int k = 0; k <= n; k++){
            cur += diff[k];
            ans[k] = cur;
        }

        // 5) Output
        for(int k = 0; k <= n; k++){
            cout << ans[k] << (k==n?'\n':' ');
        }
    }
    return 0;
}

