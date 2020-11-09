#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define p push

// Minimum spanning tree.

class graph{
    map<int,vector<pair<int,int>>> um;
    int * parent;
    int * rank;
    public:

    graph(int v){
        parent = new int[v];
        rank = new int[v];
        for(int i=0;i<v;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    void addEdges(int u,int v,int weight)
    {
        um[weight].pb(make_pair(v,u));
        // um[weight].pb(make_pair(u,v));
    }

    int findParent(int x){
        if(parent[x] == -1){
            return x;
        }

        return parent[x] = findParent(parent[x]);
    }

    void unionn(int first,int second){
        int x = findParent(first);
        int y = findParent(second);

        if(x != y){
            if(rank[x] < rank[y]){
                parent[x] = y;
                rank[y] += rank[x];
            }
            else{
                parent[y] = x;
                rank[x] += rank[y];
            }
        }

        // parent[findParent(first)] = parent[findParent(second)];
    }

    int answer()
    {
        int ans = 0;
        for(auto x: um){
            int weight = x.first;
            for(auto y: x.second){
                int parent_first = findParent(y.first);
                int parent_second = findParent(y.second);

                if(findParent(y.first) !=  findParent(y.second)){
                    ans += weight;
                    // cout<<"Answer is : "<<ans<<endl;
                    unionn(parent_first,parent_second);
                }
            }   
        }
        return ans;
    }
};

int main(){
    int v,e;
    cin>>v>>e;
    // cout<<v<<e<<endl;
    graph g(v);
    // cout<<"hello world"<<endl;
    for(int i=0;i<e;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        g.addEdges(u,v,weight);
    }
    cout<<g.answer()<<endl;
    return 0;
}