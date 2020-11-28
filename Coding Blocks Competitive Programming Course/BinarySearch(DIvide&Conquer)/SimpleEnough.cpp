#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll n){
    if(n == 1 || n == 0){
        return 1;
    }

    return ((solve(n / 2) * 2) + 1);
}


ll func(ll number,ll start,ll end,ll l,ll r){

    if(start > r || end < l || start > end){
        return 0;
    }


    ll mid = (start + end)/ 2;
    
    ll ans = 0;
    if(number%2 == 1 && mid <= r && mid >= l ){
        ans += 1;
    }   

    ans+= func(number/2,start,mid - 1,l,r);
    ans+= func(number/2,mid + 1,end,l,r);

    return ans;
}

int main(){
    ll n,l,r;
    cin>>n>>l>>r;
    ll ans = func(n,1,solve(n),l,r);
    cout<<ans<<endl;    
}