#include<bits/stdc++.h>
#define ll long long int
using namespace std;

template<typename T>
class Graph{
    unordered_map<T,list<pair<T,int>>> m;
    public:
    void addEdge(T u,T v,int dist,bool bidir = true){
        m[u].push_back(make_pair(v,dist));
        if(bidir){
            m[v].push_back(make_pair(u,dist));
        }
    }

    void printAdj(){
        // lets try to print the adjacency list
        // Iterate over all the key value pair in the map
        for(auto j : m){
            cout<<j.first<<"->";
            // Iterater over the list of ciities
            for(auto l: j.second){
                cout<<"("<<l.first<<","<<l.second<<")";
            }
            cout<<endl;
        }
    }

    void dijsktraSSSP(T src){
        unordered_map<T,int> dist;
        // Set all distance to infinity

        for(auto j: m){
            dist[j.first] = INT_MAX;
        }
        dist[src] = 0;
        // Make a set to find a out node with the minimum distance
        set<pair<int,T>> s;
        dist[src] = 0;
        s.insert(make_pair(0,src));

        while(!s.empty()){
            // Find the pair at the front
            auto p = *(s.begin());
            T node = p.second;
            int nodeDist = p.first;
            s.erase(s.begin());

            // Iterate over neighbours/children of the current node
            for(auto childPair: m[node]){
                if(nodeDist + childPair.second < dist[childPair.first] ){

                    // In the set updation of a particular is not possible
                    // we have to remove the old pair, and insert the new pair to simulation updation
                    auto f = s.find(make_pair(childPair.first,dist[childPair.first]));
                    if(f != s.end()){
                        s.erase(f);
                    }

                    dist[childPair.first] = nodeDist + childPair.second;
                    s.insert(make_pair(dist[childPair.first],childPair.first));
                }
            }
        }
        for(auto d:dist){
            cout<<d.first<<" is located at distance of "<<d.second<<endl;
        }
    }
};



int main(){
    Graph<int> g;
    // g.addEdge(1,2,1);;
    // g.addEdge(1,3,4);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,2);
    // g.addEdge(1,4,7);
    // g.printAdj();
    // g.dijsktraSSSP(1);
    return 0;
}