/*
    author : Aman Goel
*/ 

// space complexity is O(n^2)
// FloydWarshallAlogrithm
// it has a time complexity of n^3
// it is a dp based solution.
// All pair shortest path
// Shortest between all pair of vertices
// works with negative edges
// can detect negative cycles too , with one extra step

#include<bits/stdc++.h>
using namespace std;
#define inf 10000

vector<vector<int>> floyd_warshall(vector<vector<int>> graph){
    vector<vector<int>> dist(graph);
    int V = dist.size();
    // Phases, in kth place we include vertices {1,2 .... k} as intermediate vertices
    for(int k = 0;k<V;k++){
        // Iterate over entire 2D Matrix
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                // if vertex k is included, and can we minimize the dist ?
                if(dist[i][j] > dist[i][k] + dist[k][j] ){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    return dist;
}

int main(){
    vector<vector<int>> graph = {
        {0,inf,-2,inf},
        {4,0,3,inf},
        {inf,inf,0,2},
        {inf,-1,inf,0}
    };

    auto result = floyd_warshall(graph);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result.size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

