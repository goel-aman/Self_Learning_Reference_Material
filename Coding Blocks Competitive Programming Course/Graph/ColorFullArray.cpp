#include <bits/stdc++.h>
#define ll long long int
using namespace std;

class dsu
{   
    public:
    vector<int> par;
    void init(int n)
    {
        par.resize(n);
        for(int i=0;i<n;i++){
            par[i] = i;
        }
    }
    // parent of x
    int get(int x){
        if(x == par[x]){
            return x;
        }

        return par[x] = get(par[x]);
    }

    int unit(int x, int y){
        x = get(x);
        y = get(y);

        if(x != y){
            par[x] = max(par[x],par[y]);
            par[y] = max(par[x],par[y]);
        }
        return par[x];
    }

};

int main()
{
    ll n, q;
    cin >> n >> q;
    ll l[q], r[q], c[q];
    for (ll i = 0; i < q; i++)
    {
        cin>>l[i]>>r[i]>>c[i];
    }
    dsu G;
    int res[n+2] = {0};
    G.init(n+ 2);
    for(int i=q-1;i>=0;i--){
        // index -> rightmost non colored index
        int index = G.get(l[i]);
        while(index <= r[i]){
            res[index] = c[i];
            G.unit(index ,index + 1);
            //rightmost
            index = G.get(index);
        }
    }

    for(int i=1;i<=n;i++){
        cout<<res[i]<<'\n';
    }

    return 0;
}