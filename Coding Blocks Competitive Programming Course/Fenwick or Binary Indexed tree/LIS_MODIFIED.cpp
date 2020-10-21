#include<bits/stdc++.h>
using namespace std;
#define ll long long int

class element{
    public:
    ll value;
    ll index;
    ll weight;
};

bool ValueCmp(element const & a, element const & b)
{
    return a.value < b.value;
}

class fenwick{
    public:
    vector<long long int> f;
    ll n;

    void init(ll n){
        this->n = n;
        f.resize(n + 1, 0);
    }

    void update(ll index , ll val){
        index++;
        while(index <= n){
            f[index] = max(f[index], val);
            index += (index & (-index));
        }
    }

    ll query(ll index){
        index++;
        ll result = 0;
        while(index){
            result = max(result,f[index]);
            index -= (index & (-index));
        }
        return result;
    }

};


int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        element arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i].value;
            arr[i].index = i;
        }
        for(ll i=0;i<n;i++){
            cin>>arr[i].weight;
        }
        ll dp[n] = {0};
        fenwick f;
        f.init(n);
        // Time Complexity - n*log(n)
        sort(arr,arr+n,ValueCmp);
        for(ll i=0;i<n;i++){
            ll index = arr[i].index;
            ll weight = arr[i].weight;
            ll value = arr[i].value;
            //f.update(index,weight);
            dp[i] = f.query(index - 1) + weight;
            f.update(index,dp[i]);
        }

        ll ans = 0;
        for(ll i=0;i<n;i++){
            ans = max(dp[i],ans);
        }
        cout<<ans<<endl;
    }
    return 0;
}