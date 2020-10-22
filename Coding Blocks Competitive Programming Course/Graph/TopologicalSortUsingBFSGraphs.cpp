#include<bits/stdc++.h>
using namespace std;


class Graph{
    list<int> * l;
    int V;
    public:
    Graph(int V){
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int x, int y){
        //directed graph
        l[x].push_back(y);
    }

    void topological_sort(){
        //indegree

        int * indegree = new int[V];
        for(int i=0;i<V;i++){
            indegree[i] = 0;
        }
        //update indegree by traversing edges x -> y
        // indegree[y] ++

        for(int i=0;i<V;i++){
            for(auto val : l[i]){
                indegree[val]++;
            }
        }
        //bfs
        queue<int> q;
        //1. step find nodes with 0 indegree
        for(int i=0;i<V;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        // start removing elements from the queue
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            // cout<<"hello"<<endl;
            q.pop();
            // iterate over nbrs of that node and reduce their indegree.
            for(auto nbr: l[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0){
                    q.push(nbr);
                }
            }

        }

    }
};


int main(){
    Graph g(6);
    g.addEdge(1,2);
    g.addEdge(5,2);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(1,3);
    g.topological_sort();
    return 0;
}