#include<bits/stdc++.h>
using namespace std;
#define ll long long int



ll inversionSort(ll arr[],ll start,ll end){
    if(start >= end){
        return 0;
    }
    ll mid = (start + end) / 2;
    ll ans = 0;
    ans += inversionSort(arr,start,mid);
    ans += inversionSort(arr,mid + 1, end);

    vector<ll> v;
    ll i = start;
    ll j = mid + 1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            v.push_back(arr[i]);
            i++;
        }
        else{
            ans += (mid - i + 1);
            v.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        v.push_back(arr[i]);
        i++;
    }
    while(j <= end){
        v.push_back(arr[j]);
        j++;
    }
    ll w = 0;
    for(ll p = start;p<=end;p++){
        arr[p] = v[w];
        w++;
    }
    return ans;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll ans = inversionSort(arr,0,n - 1);
        cout<<ans<<endl;
    }
    return 0;
}