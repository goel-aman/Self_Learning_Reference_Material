
#include<bits/stdc++.h>
using namespace std;
// #define int long long

string arr[] = {"0","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};

vector<string> v;

void solve(string str,string ans){
    if(str == "" || str.length() == 0 ){
        v.push_back(ans);
        return ;
    }

    if(str[0] == '0'){
        solve(str.substr(1),ans);
        return ;
    }

    if(str.length() == 1){
        // cout<<"input to stoi inside if : "<<str<<endl;
        int val = stoi(str);
        solve(str.substr(1),ans +arr[val]);
        return ;
    }

    // cout<<"input to stoi second last : "<<str.substr(0,2)<<"  string is : "<<str<<endl;
    int val1 = stoi(str.substr(0,2));
    // cout<<"input to stoi last : "<<str.substr(0,1)<<endl;
    int val2 = stoi(str.substr(0,1));

    solve(str.substr(1),ans + arr[val2]);
    if(val1 <= 26){
        solve(str.substr(2),ans + arr[val1]);
    }
    return ;
}

int main(){
    string inp;
    cin>>inp;
    string ans = "";
    solve(inp,ans);
    cout<<"[";
    for(int i=0;i<v.size() - 1;i++){
        cout<<v[i]<<", ";
    }
    cout<<v[v.size() - 1]<<"]";
    return 0;
}