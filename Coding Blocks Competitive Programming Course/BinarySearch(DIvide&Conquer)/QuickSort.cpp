#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(ll * arr,ll start,ll end){
    if(start == end){
        return start;
    }
    ll val = arr[end];
    ll i = start - 1;
    ll j = start;
    while(j <= end){
        if(arr[j] <= val){
            i = i + 1;
            swap(arr[i],arr[j]);
        }
        j++;
    }
    return i;
}

void quicksort(ll * arr,ll start,ll end){
    if(start >= end){
        return ;
    }

    ll index = solve(arr,start,end);
    quicksort(arr,start,index - 1);
    quicksort(arr,index + 1, end);
}

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    unsigned seed = 0;
    shuffle(arr,arr+n,default_random_engine(seed));
    // cout<<"hello world"<<endl;
    quicksort(arr,0,n - 1);
    for(ll i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}