#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(ll n,ll * arr,ll m){
    sort(arr,arr + n);
    ll i = 0;
    ll j = n - 1;
    ll diff = 1000000000;
    ll ans_i = 0; 
    ll ans_j = 0;

    while(i < j){
        if(arr[i] + arr[j] == m){
            if(arr[j] - arr[i] <= diff ){
                diff = arr[j] - arr[i];
                ans_i = i;
                ans_j = j;
            }
            i++;
            j--;
        }
        else if(arr[i] + arr[j] > m){
            j--;
        }
        else{
            i++;
        }
    }
    ll small = min(arr[ans_i],arr[ans_j]);
    ll big = max(arr[ans_i],arr[ans_j]);


    // string out = "Deepak should buy roses whose prices are " + to_string(small) + " and " + to_string(big) + ".";
    cout<<"Deepak should buy roses whose prices are "<<small<<" "<<"and"<<" "<<big<<"."<<endl;
    // return out; 
}

int main(){
    ll t;
    cin>>t;
    while(t--){
       ll n;cin>>n;
       ll arr[n];
       for(int i=0;i<n;i++){
           cin>>arr[i];
       }
       ll m;cin>>m;
    //    string str;
    //    getline(cin,str);
       solve(n,arr,m);
       
    }
    return 0;
}