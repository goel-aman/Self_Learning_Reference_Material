#include<bits/stdc++.h>
#include<iostream>
#define ll long long int
using namespace std;

// DSU data Structure
// Path Compression + Union By Rank

class dsu{
    
    int * parent;
    int * rank;

    public:

    dsu(int n){
        parent = new int[n];
        rank = new int[n];
        // parent -1, rank = 1
        for(int i=0;i<n;i++){
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find function
    int find(int i){
        // base case
        if(parent[i] == -1){
            return i;
        }
        // otherwise
        return parent[i] = find(parent[i]);
    }

    void unite(int x,int y){
        int s1 = find(x);
        int s2 = find(y);

        if(s1 != s2)
        {
            // union by rank
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
};

class Graph{
    vector<vector<int>> edgelist;
    int V;
    public:

    Graph(int V){
        this->V = V;
    }

    void addEdge(int x,int y,int w)
    {
        vector<int> v;
        edgelist.push_back({w,x,y});
    }

    int kruskal_mst(){
        // Main Logic
        //1. Sort all the edges based upon weight

        sort(edgelist.begin(),edgelist.end());
        // Initialize a dsu
        dsu s(V);
        int ans = 0;
        for(auto edge: edgelist){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // take that edge in mst if it doesn't form a cycle
            if(s.find(x) != s.find(y)){
                s.unite(x,y);
                ans += w;
            }
        }
        return ans;
    }
};


int main(){
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);
    cout<<g.kruskal_mst()<<endl;
    return 0;
}