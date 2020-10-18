#include<bits/stdc++.h>
#include<iostream>
using namespace std;

struct fenwick{
    
    vector<int> f;
    int n;
    void init(int n){
        this->n = n + 1;
        f.resize(this->n,0);
    }

    void update(int x, int val){
        x++; // 1 based indexing
        while(x < n){
            f[x] = max(f[x],val);
            x += ((x) & (-x));
        }
    }

    int query(int x){
        x++; // 1 based indexing
        int res = 0;
        while(x){
            res = max(res,f[x]);
            x -= (x & (-x));
        }
        return res;
    }
};

int main(){
    int n;
    cin>>n;
    pair<int,int> a[n];
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second = i;
    }
    //nlog(n)
    sort(a, a + n);
    fenwick tree;
    tree.init(n);
    for(int i= 0;i<n;i++){
        cout<<a[i].first << " "<<a[i].second <<"\n";
    }

    int dp[n];

    // O(n)
    for(int i=0;i<n;i++){
        int val = a[i].first;
        int index = a[i].second;
        // query log(n)
        dp[index] = tree.query(index - 1) + 1;
        // update log(n)
        tree.update(index,dp[index]);
    }
    int lis = 0;
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
        lis = max(lis,dp[i]);
    }
    cout<<endl;
    cout<<lis<<endl;
    cout<<"\n";
    return 0;
}