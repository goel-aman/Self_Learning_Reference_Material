#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class Graph{
    list<pair<int,int>> l;
    int V;

    public:
    Graph(int N){
        this->V = N;
    }

    void addEdge(int x,int y){
        l.push_back(make_pair(x,y));
    }

    int findParent(int i,int parent[]){
        if(parent[i] == -1){
            return i;
        }

        return parent[i] = findParent(parent[i],parent);
    }

    int getAnswer(){
        int * parent = new int[V];
        int * rank = new int[V];

        for(int i=0;i<V;i++){
            parent[i] = -1;
            rank[i] = 1;
        }

        for(auto a: l){
            int x =a.first;
            int y = a.second;

            int s1 = findParent(x,parent);
            int s2 = findParent(y,parent);
            if(s1 != s2){
                if(rank[s1] < rank[s2]){
                    parent[s1] = s2;
                    rank[s2] += rank[s1];
                }
                else{
                    parent[s2] = s1;
                    rank[s1] += rank[s2];
                }
            }

        }
        int ans = 0;
        for(int i=0;i<V;i++){
            if(parent[i] == -1){
                ans += rank[i] * (V -  rank[i]);
            }
        }
        delete[] parent;
        delete[] rank;
        return ans/2;
    }

};

int main(){
    ll n,m;
    cin>>n>>m;
    Graph g(n);
    while(m--){
        int x,y;
        cin>>x>>y;
        g.addEdge(x,y);
    }
    cout<<g.getAnswer()<<endl;
    return 0;
}