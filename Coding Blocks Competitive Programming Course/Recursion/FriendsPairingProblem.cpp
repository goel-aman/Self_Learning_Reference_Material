#include<iostream>
#include<bits/stdc++.h>
#define l long long int
using namespace std;

int main(){
	l t; cin>>t;
	l dp[31]; 
	dp[1] = 1;
	dp[2] = 2;
	for(l i=3;i<=30;i++){
		dp[i] = dp[i-1] + (i-1)*dp[i-2];
	}
	while(t--){
		l n; cin>>n;
		cout<<dp[n]<<endl;
	}
	return 0;
}