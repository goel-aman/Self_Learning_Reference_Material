#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define p push

class graph{
    unordered_map<int,vector<int>> umm;
    int v;
    bool * visited;
    public:

    graph(int n){
        this->v = n;
        visited = new bool[v+1];
        memset(visited,0,sizeof(visited));

    }

    void addEdge(int x,int y){
        umm[x].push_back(y);
    }

    int bfs(int starting_node){
        queue<int> q;
        visited[starting_node] = true;
        q.push(starting_node);
        int siz = 1;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto x: umm[front]){
                if(!visited[x]){
                    visited[x] = true;
                    siz++;
                    q.push(x);
                }
            }
        }
        return siz;
    }

    int answer(){
        int ans = 100000;
        for(int i=1;i<=v;i++){
            memset(visited,0,sizeof(visited));
            ans = min(ans,bfs(i));
        }
        return ans;        
    }

};

int main(){
    int n,d;
    cin>>n>>d;
    graph g(n);
    while(d--){
        int a,b;
        cin>>a>>b;
        g.addEdge(a,b);
    }
    cout<<g.answer()<<endl;
}