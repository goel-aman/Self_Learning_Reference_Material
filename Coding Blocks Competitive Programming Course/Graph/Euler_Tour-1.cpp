#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
const int N = 100005, M = 22;

vector<int> gr[N];
int tin[N],tout[N],timer;

void euler_tour_1(int cur,int par)
{
    cout<<cur<<" ";
    tin[cur] = timer++;
    for(auto x: gr[cur]){
        if(x != par){
            euler_tour_1(x,cur);
            cout<< cur <<" ";
            tout[cur] = timer++;
        } 
    }
    return ;
}

void euler_tour_2(int cur,int par)
{
    cout<<cur<<" ";
    tin[cur] = timer++;
    for(auto x: gr[cur]){
        if(x != par){
            euler_tour_2(x,cur);           
        } 
    }
    tout[cur] = timer++;
    cout<< cur <<" ";
    return ;
}

void euler_tour_3(int cur,int par){
    cout<<cur<<" ";
    // enter a node
    tin[cur] = ++ timer;
    for(auto x : gr[cur]){
        if(x != par){
            euler_tour_3(x,cur);
        }
    }
    // leave a node
    tout[cur] = timer;
    return ;
}

// whether x is ancester of y or not

bool is_ancestor(int x,int y){
    return (tin[x]<= tin[y] && tout[x] >= tout[y]);
}

void solve(){
    int i,j,k,n,m,ans = 0,cnt = 0,sum = 0;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        gr[x].pb(y);
        gr[y].pb(x);
    }
    timer = 0;
    // euler_tour_1(1,0);
    
    // euler_tour_2(1,0);
    
    euler_tour_3(1,0);
    cout<<endl;
    cout<<"Time in is : "<<endl;
    for(int i=1;i<=9;i++){
        cout<<tin[i]<<" ";
    }

    cout<<endl;
    cout<<"time out is : "<<endl;
    for(int i=1;i<=9;i++){
        cout<<tout[i]<<' ';
    }
    cout<<endl;
    if(is_ancestor(6,7)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }

}

int main(){
    solve();
}