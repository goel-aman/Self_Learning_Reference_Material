#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define p push


class graph{
    // node,node,weight
    unordered_map<int,vector<pair<int,int>>> um;
    int V;
    
    public:
    
    graph(int v){
        this->V = v;
    }

    void addEdge(int a,int b,int weight){
        um[a].push_back(make_pair(b,weight));
        um[b].push_back(make_pair(a,weight));
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
        sum += weight;       
    }
    return 0;
}