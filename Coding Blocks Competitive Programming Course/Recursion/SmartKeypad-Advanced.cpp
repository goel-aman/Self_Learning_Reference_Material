#include <bits/stdc++.h>
using namespace std;

string table[] = {" ", ".+@$", "abc", "def", "ghi",
                  "jkl", "mno", "pqrs", "tuv", "wxyz"};



unordered_map<string,bool> um;

void solve(string input,string out)
{
    if(input.length() == 0){
        um[out] = true;
        // cout<<out<<endl;
        return ;
    }

    int val = input[0] - '0';
    for(int i=0;i<table[val].length();i++){
        solve(input.substr(1),out + table[val][i]);
    }
    // return ;
}

int main()
{
    string num;
    cin >> num;
    int lenn = num.length();
    solve(num,"");
    string searchIn[] = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
    set<string> ans; 
    for(auto s: searchIn){
        for(int i=0;i<s.length() - lenn;i++){
            if(um.count(s.substr(i,lenn)) > 0){
                ans.insert(s);
                break;
            }
        }
    }
    for(auto prin : ans){
        cout<<prin<<endl;
    }
    return 0;
}
