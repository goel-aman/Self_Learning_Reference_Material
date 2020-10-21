#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll arr[102][102][102] = {0};
ll original[102][102][102] = {0};
void update(ll index_x,ll index_y,ll index_z,ll val,ll n){
    ll x = index_x;
    ll y = index_y;
    ll z = index_z;
    while(index_x <= n){
        while(index_y <= n){
            while(index_z <= n){
                arr[index_x][index_y][index_z] += val;
                index_z += (index_z & (-index_z));
            }
            index_z = z;
            index_y += (index_y & (-index_y));
        }
        index_y = y;
        index_x += (index_x & (-index_x));
    }
}

ll query(ll index_x,ll index_y,ll index_z,ll n){
    ll result = 0;
    ll x = index_x;
    ll y = index_y;
    ll z = index_z;
    while(index_x){
        while(index_y){
            while(index_z){
                result += arr[index_x][index_y][index_z];
                index_z -= (index_z & (-index_z));
            }
            index_z = z;
            index_y -= (index_y &(-index_y)); 
        }
        index_y = y;
        index_x -= (index_x & (-index_x));
    }
    return result;
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        memset(arr,0,sizeof(arr));
        memset(original,0,sizeof(original));        
        while(m){
            string q;
            cin>>q;
            if(q == "UPDATE"){
                ll x,y,z,w;
                cin>>x>>y>>z>>w;
                ll diff = w - original[x][y][z];
                original[x][y][z] = w;
                update(x,y,z,diff,n);
            }
            else{
                ll x1,y1,z1,x2,y2,z2;
                cin>>x1>>y1>>z1>>x2>>y2>>z2;
                ll ans = query(x2,y2,z2,n) - query(x1 - 1, y2,z2,n) - query(x2,y1 - 1,z2,n) - query(x2,y2,z1 - 1,n) + query(x1 - 1, y1 - 1, z2, n) + query(x2,y1 - 1, z1 - 1, n) + query(x1 - 1, y2, z1-1 , n) - query(x1 - 1, y1- 1, z1 - 1,n);
                cout<<ans<<endl;  
            }
            m--;
        }
    }
    return 0;
}