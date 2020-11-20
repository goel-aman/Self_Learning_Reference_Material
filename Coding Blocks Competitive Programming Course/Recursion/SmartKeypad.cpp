#include<bits/stdc++.h>
using namespace std;
#define ll long long int

string table[] = {" ",".+@$","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void solve(string input,string out){
    if(input.length() == 0){
        cout<<out<<endl;
        return ;
    }

    int val = input[0] - '0';
    for(int i=0;i<table[val].length();i++){
        solve(input.substr(1),out + table[val][i]);
    }
    // return ;
}

int main(){
    string input;
    cin>>input;
    solve(input,"");
    return 0;
}