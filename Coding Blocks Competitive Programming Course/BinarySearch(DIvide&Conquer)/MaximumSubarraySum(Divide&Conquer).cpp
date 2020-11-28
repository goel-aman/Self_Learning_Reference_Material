#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll *a,ll start,ll end){
    if(start > end){
        return 0;
    }

    if(start == end){
        return a[start];
    }

    ll mid = (start + end)/2;
    ll ans1 = solve(a,start,mid);
    ll ans2 = solve(a,mid + 1, end);
    ll value = INT_MIN;
    ll prefix = 0;
    for(ll i=mid + 1;i<=end;i++){
        prefix += a[i];
        value = max(value,prefix);
    }

    ll value2 = INT_MIN;
    ll suffix = 0;
    for(ll i=mid;i>=start;i--){
        suffix += a[i];
        value2 = max(value2,suffix);
    }
    return max(ans1,max(ans2,value + value2));
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;cin>>n;
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll start = 0;
        ll end = n - 1;
        ll ans = solve(a,start,end);
        cout<<ans<<endl;
    }
    return 0;
}