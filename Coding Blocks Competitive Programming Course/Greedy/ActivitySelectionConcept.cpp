#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> p1,pair<int,int> p2){
    return p1.second < p2.second;
}

int main(){
    int t,n,s,e;
    cin>>t;
    while(t--){
        cin>>n;
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++){
            cin>>s>>e;
            v.push_back(make_pair(s,e));
        }
        // Acitivity Selection Algorithm
        // Sort
        sort(v.begin(),v.end(),compare);

        // Starting Picking Activities.
        int res = 1;
        int fin = v[0].second;
        
        // Iterate Over remaining Activities.
        for(int i=2;i<n;i++){
            if(v[i].first >= fin){
                fin = v[i].second;
                res++; 
            }
        }
        cout<<res<<endl;
        v.clear();
    }
    return 0;
}