#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[91] = {0};

int main(){
    ll t;
    cin>>t;
    dp[1] = 2;
    dp[2] = 3;
    for(int i=3;i<=90;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    } 
    while(t--){
        ll n;
        cin>>n;
        cout<<dp[n]<<endl;  
    }
    return 0;
}