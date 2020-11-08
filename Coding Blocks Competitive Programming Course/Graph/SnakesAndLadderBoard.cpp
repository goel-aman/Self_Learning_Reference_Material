#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
#define pb push_back
#define p push
#define ll long long int
#define doublePrecision(x,y) cout<<fixed<<setprecision(y)<<x

class graph{
    unordered_map<int,vector<int>> umm;
    public:
    
    void addEdge(int u,int v){
        umm[u].push_back(v);
        //umm[v].push_back(u);
    }

    int bfs(int source){
        bool visited[101];
        memset(visited,0,sizeof(visited));
        int * distance= new int[1001];
        for(int i=0;i<101;i++){
            distance[i] = -1;
        }
        // memset(distance,-1,sizeof(distance));
        queue<int> q;
        q.push(source);
        visited[source] = true;
        distance[source] = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto adjancy_list_value: umm[front]){
                if(!visited[adjancy_list_value]){
                    visited[adjancy_list_value] = true;
                    distance[adjancy_list_value] = distance[front] + 1;
                    q.push(adjancy_list_value);
                }
                
            }  
        }
        return distance[100]; 
    }


};

int main(){
    ll t;
    cin>>t;
    while(t--){

        ll n; // number of ladders
        cin>>n;
        unordered_map<long long int,long long int> um;

        for(long long int i=0;i<n;i++){
            ll a,b;
            cin>>a>>b;
            um[a] = b;
        }

        ll m;
        cin>>m;
        for(ll i=0;i<m;i++){
            ll a,b;
            cin>>a>>b;
            um[a] = b;
        }

        graph g;
        
        for(int i=1;i<=100;i++){
            int starting_point = i;
            for(int j=1;j<=6;j++){
                int final_pos = i + j;
                if(final_pos <= 100)
                {
                    if(um.count(final_pos) > 0){
                        final_pos = um[final_pos];
                        g.addEdge(starting_point,final_pos);
                        continue;
                    }
                    else{
                        g.addEdge(starting_point,final_pos);
                    }
                }
            }
        }
        cout<<g.bfs(1)<<endl;
    }
    return 0;
}