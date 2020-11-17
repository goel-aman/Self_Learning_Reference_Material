#include<bits/stdc++.h>
using namespace std;
#define ll long long int



void solve(int n,int m,string tillnow,vector<string> &ans){
    if(n == 0 && m == 0){
        ans.push_back(tillnow);
        return;
    }
    if(m > n){
        string one = tillnow + ")";
        solve(n,m-1,one,ans);
        if(n > 0){
            string two = tillnow + "(";
            solve(n-1,m,two,ans);
        }
    }

    if(n == m){
        string two = tillnow + "(";
        solve(n -1, m,two,ans);
    }
}

int main()
{
    int n;
    cin>>n;
    string tillnow = "";
    vector<string> ans;
    solve(n,n,tillnow,ans);
    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    for(auto a: ans){
        cout<<a<<endl;
    }
    return 0;
}