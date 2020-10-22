#include<bits/stdc++.h>
using namespace std;

class Graph{
    list<int> *l;
    int V;

    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x,int y){
        l[x].push_back(y);
    }  

    bool dfs(int node,vector<int> &visited,vector<int> &track){
        visited[node] = 1;
        track[node] = 1;

        for(auto nbr: l[node]){
            if(visited[nbr] == 1 && track[nbr] == 1){
                return true;
            }
            if(dfs(nbr,visited,track)){
                return true;
            }
        }
        track[node] = 0;
        return false;
    }

    bool contains_cycle(){
        // Check for cycle in Directed Graph
        vector<int> visited(V,0);
        vector<int> track(V,0);

        for(int i=0;i<V;i++){
            if(!visited[i]){
                bool ans = dfs(i,visited,track);
                if(ans == true){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(4,2); // back edge.
    bool a = g.contains_cycle();
    cout<<a<<endl;
}