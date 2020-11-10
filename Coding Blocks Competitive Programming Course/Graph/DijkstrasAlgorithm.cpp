#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define p push
#define ll long long int
#define mp make_pair
class graph{
    // node,node,weight
    unordered_map<int,vector<pair<int,int>>> um;
    int v;
    public:
    graph(int v){
        this->v = v;
    }

    void addEdge(int x,int y,int r){
        um[x].pb(make_pair(y,r));
        um[y].pb(make_pair(x,r));
    }

    vector<int> answer(int starting_point){
        int* distance = new int[v + 1];
        for(int i=0;i<=v;i++){
            distance[i] = INT_MAX;
        }
        distance[starting_point] = 0;
        // first int is for weight , second for node
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>> > pq;
        pq.push(mp(0,starting_point));
        while(!pq.empty()){
            pair<int,int> pa = pq.top();
            pq.pop();
            int parent_distance = pa.first;
            for(auto x: um[pa.second]){
                int node = x.first;
                int weight = x.second;
                if(parent_distance + weight < distance[node]){
                    distance[node] = parent_distance + weight;
                    pq.push(mp(distance[node],node));
                }
            }
        }
        vector<int> vv;
        for(int i=1;i<=v;i++)
        {
            if(i != starting_point){
                if(distance[i] >= INT_MAX - 1000){
                    vv.push_back(-1);
                    continue;
                }
                vv.push_back(distance[i]);
            }
        }
        return vv;
    }

};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,e;
        cin>>n>>e;
        graph g(n);
        for(int i=0;i<e;i++){
            int x,y,r;
            cin>>x>>y>>r;
            g.addEdge(x,y,r);
        }
        int s;
        cin>>s;
        vector<int> vv = g.answer(s);
        for(int i=0;i<vv.size();i++){
            cout<<vv[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}