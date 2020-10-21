#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll arr[100100];

void update(ll index,ll val,ll n){
    while(index <= n){
        arr[index] += val;
        index += (index & (-index));
    }
}

ll query(ll index,ll n){
    ll result = 0;
    while(index){
        result += arr[index];
        index -= (index & (-index));
    }
    return result;
}

int main(){
    ll nn;
    cin>>nn;
    ///in pair first is price and second is quantity
    unordered_map<string,pair<long long int,long long int>> ma;
    ll maxx = 0;
    while(nn--){
        string item;
        ll price;
        cin>>item>>price;
        ma[item].first = price;
        ma[item].second = 0;
        maxx = max(maxx,price);
    }
    memset(arr,0,sizeof(arr));
    ll n = maxx;
    ll q;cin>>q;
    ll cnt = 0;
    while(q){
        char symbol;cin>>symbol;
        if(symbol == '+'){
            string s;
            cin>>s;
            ma[s].second += 1;
            ll s_price = ma[s].first;
            cnt++;
            update(s_price,1,n);
        }
        if(symbol == '-'){
            string s;
            cin>>s;
            if(ma[s].second > 0){
                ma[s].second -= 1;
                ll s_price = ma[s].first;
                update(s_price,-1,n);
                cnt--;
            } 
        }
        if(symbol == '?'){
            ll number;cin>>number;
            ll ans = cnt - query(number,n);
            cout<<ans<<endl;
        }
        q--;
    }
    return 0;
}