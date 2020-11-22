#include<bits/stdc++.h>
using namespace std;
#define ll long long int 

ll dp[3000][3000];

ll solve(ll arr[],ll i,ll j)
{
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    if(i == j){
        return (dp[i][j] = arr[i]);
    }

    if(abs(j - i) == 1){
        return dp[i][j] = max(arr[i],arr[j]);
    }

    return dp[i][j] = max(arr[i] + min(solve(arr,i+2,j),solve(arr,i+1,j-1)),arr[j] + min(solve(arr,i+1,j-1), solve(arr,i,j-2)));
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    ll i = 0;
    ll j = n - 1;
    // 1 means piyush
    // ll ans_turn_1 = 0;
    memset(dp,-1,sizeof(dp));
    cout<<solve(arr,i,j)<<endl;
    return 0;
}