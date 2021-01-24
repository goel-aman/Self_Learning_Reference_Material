#include<bits/stdc++.h>
using namespace std;
#define ll long long int

set<string> s;

void solve(string input, int index){
    if(input.length() == index){
        s.insert(input);
    }

    for(int j = index;j<input.length();j++){
        swap(input[j],input[index]);
        solve(input,index + 1);
        swap(input[j],input[index]);
    }
    return;
}

int main(){
    string input;
    cin>>input;
    string in = input;
    solve(input,0);
    vector<string> vs;
    for(auto m: s){
        vs.push_back(m);
    }
    auto it = upper_bound(vs.begin(),vs.end(),in);
    while(it != vs.end()){
        cout<<*it<<endl;
        it++;
    }
    return 0;
}