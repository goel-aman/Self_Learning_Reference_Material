#include<bits/stdc++.h>
using namespace std;

bool canPlaceCows(int stalls[],int n,int c,int min_sep){
    int last_cow = stalls[0];
    // place the first cow in the first stall
    int cnt = 1;
    for(int i=1;i<n;i++){
       if(stalls[i] - last_cow >= min_sep){
           last_cow = stalls[i];
           cnt++;
           if(cnt == c){
               return true;
           }
       } 
    }
    return false;
}

int main(){
    // Problem : Aggresive Cows (spoj)
    int stalls[] = {1,2,4,8,9};
    int n = 5;
    int cows = 3;

    // Binary Search Algorithm
    int s = 0;
    int e = stalls[n - 1] - stalls[0];
    int ans = 0;
    while(s <= e){
        int mid = (s + e) / 2;
        bool cowsPlaced = canPlaceCows(stalls,n,cows,mid);
        if(cowsPlaced){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    cout<<ans<<endl;
    return 0;
}