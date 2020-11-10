#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define p push
#define ll long long int

const int N = 100;
vector<int> gr[N];
int dp[N],vis[N];
int depth[N];

void dfs(int cur,int par,int dep){
    dp[cur] = dep;
    vis[cur] = 1;
    depth[cur] = dep;
    for(auto x: gr[cur]){
        if(!vis[x]){
            dfs(x,cur,dep + 1);
            dp[cur] = min(dp[cur],dp[x]);
        }else if (x != par) {
            // backedge
            dp[cur] = min(dp[cur],depth[x]);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }

    // root is 1
    dfs(1,0,0);

    return 0;
}