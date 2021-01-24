#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(ll ** matrix,ll i,ll j,ll left,ll n){
    
    for(ll p = i;p<n;p++){
        for(ll q = j;q<n;q++){
            if(matrix[])
        }
    }

}

int main(){
    ll n;
    cin>>n;
    ll** matrix = new ll*[n];
    for(int i=0;i<n;i++){
        matrix[i] = new ll[n];
        for(ll j=0;j<n;j++){
            matrix[i][j] = 1;
        }
    }
    solve(matrix,0,0,n,n);
    for(int i=0;i<n;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    return 0;
}