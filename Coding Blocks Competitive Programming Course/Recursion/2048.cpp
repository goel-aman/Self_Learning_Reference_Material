#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// Problem
string words[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

void printSpellings(int n){
    // base case
    if(n == 0)
    {
        return ;
    }

    printSpellings(n / 10);
    cout<<words[n%10]<<" ";
    return ;
}

int main(){
    int n;
    cin>>n;
    printSpellings(n);
    return 0;
}