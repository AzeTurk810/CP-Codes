//Desinged by AzeTurk810 with totorial
#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define pb push_back

int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(1900<=n)
        cout<<"Division 1"<<endl;
        else if(1600 <= n && n<1900)
        cout<<"Division 2"<<endl;
        else if(1400 <=n && n<1600)
        cout<<"Division 3"<<endl;
        else
        cout<<"Division 4"<<endl;
    }
}
