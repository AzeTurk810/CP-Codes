#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int &x: a) cin >> x;

        // k==1 means you can delete ANY single element at any time, so you
        // can always reduce to empty (palindrome).
        if(k == 1){
            cout << "YES\n";
            continue;
        }

        // 1) Compute can_delete[i] via sliding-window max of size k.
        vector<char> can_delete(n, 0);
        deque<int> dq;  // will store indices of a[], decreasing by value
        // Build first window [0..k-1]
        for(int i = 0; i < k; i++){
            while(!dq.empty() && a[dq.back()] <= a[i])
                dq.pop_back();
            dq.push_back(i);
        }
        // The front is the max index in [0..k-1]
        can_delete[dq.front()] = 1;

        // Slide window from i=1..n-k
        for(int start = 1; start + k - 1 < n; start++){
            int end = start + k - 1;
            // Pop out-of-window indices
            while(!dq.empty() && dq.front() < start)
                dq.pop_front();
            // Push new end
            while(!dq.empty() && a[dq.back()] <= a[end])
                dq.pop_back();
            dq.push_back(end);
            // Mark this window's maximum
            can_delete[dq.front()] = 1;
        }

        // 2) Two-pointer peel
        int l = 0, r = n-1;
        bool ok = true;
        while(l < r){
            if(a[l] == a[r]){
                l++; 
                r--;
            }
            else if(can_delete[l]){
                l++;
            }
            else if(can_delete[r]){
                r--;
            }
            else {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}

