#include<bits/stdc++.h>
using namespace std;
#define ll long long int

set<vector<long long int>> ans;

void solve(ll n,ll a[],ll target,vector<long long int>& v)
{
    if(target == 0){
        sort(v.begin(),v.end());
        // for(auto s : v){
        //     cout<<s<<" ";
        // }
        ans.insert(v);
    }

    if(n == 0){
        return ;
    }

    if(a[0] <= target){
        v.push_back(a[0]);
        solve(n - 1, a + 1,target - a[0], v);
        v.pop_back();
    } 

    solve(n -1, a + 1, target,v);
}

int main()
{
    ll n;
    cin>>n;
    ll a[n];
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    ll target;
    cin>>target;
    vector<long long int> v;
    solve(n,a,target,v);
    // cout<<"Size of ans is : "<<ans.size()<<endl;
    for(auto answer : ans){
        for(auto an : answer){
            cout<<an<<" ";
        }
        cout<<endl;
    }
}