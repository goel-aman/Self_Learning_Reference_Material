#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int dp[n] = {0};
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            if(a[j] < a[i]){
                dp[i] = max(dp[i],dp[j]);
            }
        }
        dp[i]++;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,dp[i]);
    }
    cout<<ans<<endl;

    return 0;
}