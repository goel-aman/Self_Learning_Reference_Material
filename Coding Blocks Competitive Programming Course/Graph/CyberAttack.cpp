#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define p push


class graph{
    // node,node,weight
    int * rank;
    int * parent;
    vector<vector<int>> vector_v;
    int V;
    
    public:
    
    graph(int v){
        this->V = v;
        rank = new int[V + 1];
        parent = new int[V + 1];
    }

    int findParent(int x){
        if(x == -1){
            return x;
        }

        return parent[x] = findParent(x);
    }

    void addEdge(int a,int b,int weight){
        vector_v.pb({weight,a,b});
    }

    void solve()
    {

    }
    
};


int main(){
    ll n,m,s;
    cin>>n>>m>>s;
    graph g(n);
    while(m--){
        int sum = 0;
        int a,b,weight;
        cin>>a>>b>>weight;
        g.addEdge(a,b,weight);
        sum += weight;       
    }
    g.solve();
    return 0;
}