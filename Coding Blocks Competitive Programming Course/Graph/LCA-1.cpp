#include<bits/stdc++.h>
using namespace std;

// Lowest common ancestor

const int N = 100005 , M = 22;

vector<int> gr[N];
int Par[N],dep[N];
void dfs(int cur,int par){
    Par[cur] = par;
    for(auto x :gr[cur]){
        if(x != par){
            dep[x] = dep[cur] + 1;
            dfs(x,cur);
        }
    }
    return ;
}
// Time Complexity will be O(n)
int lca_brute(int u,int v){
    // take u to be at more depth
    if(u == v){
        return u;
    }
    if(dep[u] < dep[v]){
        swap(u,v);
    }
    // always depth of u > depth of v
    while(dep[u] > dep[v]){
        u = Par[u];
    }
    // they are at the same level
    while(u != v){
        u = Par[u];
        v = Par[v];
    }
    return u;
}

void solve(){
    int i,j,k,n,m,ans = 0,cnt =  0, sum = 0;
    cin>>n;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    // root as 1 
    dfs(1,0);
    // for(i = 1;i<=n;i++){
    //     cout<<i<<" "<<dep[i]<<" "<<Par[i]<<"\n";
    // }
    cout<<lca_brute(18,16)<<"\n";
}

int main(){

    return 0;
}