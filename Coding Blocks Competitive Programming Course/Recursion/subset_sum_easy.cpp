#include<bits/stdc++.h>
using namespace std;
#define ll long long int

bool solve(vector<long long int> &v,int index,bool element_taken,ll ans,ll &n){
    if(element_taken == true && ans == 0){
        return true;
    }

    if(index == n && ans != 0){
        return false;
    }

    if(index == n && ans == 0 && element_taken == true){
        return true;
    }

    if(index == n && ans == 0 && element_taken == false){
        return false;
    }


    if(element_taken == true){
        bool ans1 = solve(v,index + 1, true,ans + v[index], n);
        bool ans2 = solve(v,index + 1, true,ans,n);
        
        bool ret = (ans1 || ans2);
        return ret;
    }

    bool ans1 = solve(v,index + 1 ,true,ans + v[index], n);
    bool ans2 = solve(v,index + 1, false,ans,n);

    return (ans1 || ans2);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll nn = n;
        set<long long int> s;
        while(nn--){
            ll number;
            cin>>number;
            s.insert(number);
        }
        vector<long long int> v(s.begin(), s.end());
        bool ans =  solve(v,0,false,0,n);
        
        if(ans){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}