#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
// tile dimension is 1 x m
long long int dp[1000001];
long long int solve(long long int n,long long int m){
    if(n <= 0 || m <=  0){
        return 0;
    }

    if(dp[n] != -1)
    {
        return dp[n];
    }

    if(n < m){
        return dp[n] = 1;
    }

    if(n == m){
        return dp[n] = 2;
    }

    long long int ans = ( ( (solve(n - m,m) + 0)%MOD) + solve(n - 1, m)) % MOD;

    return dp[n] = ans;
}

int main(){
    long long int t;
    cin>>t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        long long int n,m;
        cin>>n>>m;
        cout<<solve(n,m)<<endl;
    }
    return 0;
}