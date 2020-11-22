#include<bits/stdc++.h>
using namespace std;
#define ll long long int

set<string> s;

void solve(string input,int i){
    if(input.length() == i){
        s.insert(input);
    }

    int j;
    for(j = i; j < input.length();j++){
        swap(input[i],input[j]);
        solve(input,i + 1);
        swap(input[i],input[j]);
    }

}

int main(){
    string input;
    cin>>input;
    solve(input, 0 );
    for(auto ans : s){
        cout<<ans<<endl;
    }
    return 0;
}