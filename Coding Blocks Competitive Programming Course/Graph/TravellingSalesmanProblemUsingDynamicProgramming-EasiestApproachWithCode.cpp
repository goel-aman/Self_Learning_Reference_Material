#include<bits/stdc++.h>
using namespace std;

// #define INT_MAX 999999

int dp[16][4];
int n =4;
// adj matrix which defines the graph
int dist[10][10] = {
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0},
};

// If all cities has been visited
int VISITED_ALL = (1 << n) - 1;

int tsp(int mask,int pos)
{
    if(mask == VISITED_ALL){
        return dist[pos][0];
    }
    
    // lookup
    if(dp[mask][pos] != -1 ){
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    // try to go to an unvisited city
    for(int city = 0;city<n;city++){
        if((mask & (1<<city)) == 0){
            int newAns = dist[pos][city] + tsp(mask | (1<<city),city);
            ans = min(ans,newAns);
        }
    }
    return dp[mask][pos] = ans;

}


int main(){
    for(int i=0;i<(1<<n);i++){
       for(int j=0;j<n;j++){
           dp[i][j] = -1;
       }
    }
    cout<<tsp(1,0)<<endl;
    return 0;
}