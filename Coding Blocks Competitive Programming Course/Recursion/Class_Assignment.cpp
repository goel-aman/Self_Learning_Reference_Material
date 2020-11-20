#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll dp[26];

ll solve(ll n){
    return dp[n];
}

int main(){
    ll t;
    cin>>t;
    dp[1] = 2;
    dp[2] = 3;
    for(int i= 3;i<=25;i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    int m = 1;
    while(t--){
        ll n;
        cin>>n;
        cout<<"#"<<m<<" : "<<solve(n)<<endl;
        m++; 
    }
    return 0;
}