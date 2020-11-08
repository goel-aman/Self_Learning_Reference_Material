#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define p push

void bfs(ll * distance,vector<long long int> v[],ll n,ll starting){
    bool visited[n];
    memset(visited,0,sizeof(visited));
    queue<long long int> q;
    q.p(starting);
    distance[starting] = 0;
    while(!q.empty()){
        ll front =q.front();
        visited[front] = true;
        q.pop();
        for(auto k : v[front]){
            if(!visited[k]){
                q.p(k);
                distance[k] = distance[front] + 1;
            }
        }
    }
}

int main(){
    ll q;
    cin>>q;
    while(q--){
        ll n,m;
        cin>>n>>m;
        vector<long long int> v[n + 1];
        while(m--){
            ll uu,vv;cin>>uu>>vv;
            v[uu].pb(vv);
            v[vv].pb(uu);
        }
        ll s;
        cin>>s;
        ll * distance = new ll[n+1];
        for(ll i=0;i<=n;i++){
            distance[i] = -1;
        }
        bfs(distance,v,n,s);
        for(ll i = 1 ;i<=n;i++){
            if(i != s){
                if(distance[i] == -1){
                    cout<<distance[i]<<" ";
                    continue;
                }
                cout<<distance[i]*6<<" ";
            }
            
        }
        cout<<endl;
    }
    return 0;
}