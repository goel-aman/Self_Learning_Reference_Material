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
    int dp[n + 1];
    // length from 0 - n
    dp[0] = INT_MIN;
    for(int i=1;i<=n;i++){
        dp[i] = INT_MAX;
    }

    for(int i=0;i<n;i++){
        auto it = upper_bound(dp,dp +(n + 1),a[i]);
        int index = it - dp;
        if(dp[index - 1] < a[i] && a[i] < dp[index]){
            dp[index] = a[i];
        }
    }
    int lis = 0;
    for(int i=1;i<=n;i++){
        if(dp[i] != INT_MAX){
            lis = i;
        }
    }
    cout<<lis<<endl;

    return 0;
}