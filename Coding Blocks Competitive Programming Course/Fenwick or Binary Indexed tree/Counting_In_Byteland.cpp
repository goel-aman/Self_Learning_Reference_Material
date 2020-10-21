#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll f[103][103][103] = {0};

class fenwick{
    public:

    ll n;

    void init(ll n){
        this->n = n;
    }

    void update(ll index_x,ll index_y,ll index_z,ll val){
        ll x = index_x;
        ll y = index_y;
        ll z = index_z;
        while(index_x <= n){
            while(index_y <= n){
                while(index_z <= n){
                    f[index_x][index_y][index_z] += val;
                    index_z += (index_z & (-index_z));
                }
                index_z = z; 
                index_y += (index_y & (-index_y));
            }
            index_y = y;
            index_x += (index_x &(-index_x));
        }

    }

    ll query(ll index_x,ll index_y,ll index_z){
        ll result = 0;
        ll x =index_x;
        ll y = index_y;
        ll z = index_z;
        while(index_x){
            while(index_y){
                while(index_z){
                    result += f[index_x][index_y][index_z];
                    index_z -= (index_z & (-index_z));
                }
                index_z = z;
                index_y -= (index_y & (-index_y));
            }
            index_y = y;
            index_x -= (index_x & (-index_x));
        }
        return result;
    }
};



int main(){
    ll n,q;
    cin>>n>>q;
    fenwick f;
    f.init(n + 1);
    ll total = 0;
    while(q){
        ll num;
        cin>>num;
        if(num == 1){
            ll x,y,z,val;cin>>x>>y>>z>>val;
            x += 1 , y += 1, z+= 1;
            f.update(x,y,z,val);
            total += val;
        }
        else{
            ll x,y,z,X,Y,Z;cin>>x>>y>>z>>X>>Y>>Z;
            x += 1, y += 1, z += 1 , X += 1, Y += 1, Z += 1;
            ll numm = f.query(X,Y,Z) - f.query(X,Y, z - 1) - f.query(x - 1, Y, Z) - f.query(X, y - 1, Z) + f.query(x-1,y-1,Z) + f.query(X,y-1,z-1) + f.query(x-1,Y,z-1) - f.query(x - 1,y-1,z-1); 
            ll ans = total - numm;
            cout<<ans<<endl;
        }
        q--;
    }
    return 0;
}