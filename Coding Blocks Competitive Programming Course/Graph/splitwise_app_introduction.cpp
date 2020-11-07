#include<bits/stdc++.h>
using namespace std;

// Money Splitwise Algorithm
int main(){
    int no_of_transactions, friends;
    cin>>no_of_transactions>>friends;
    int x,y,amount;
    // make a one-d array to store the net amount that each person will have to take at the end
    int net[10000] = {0};
    while(no_of_transactions--){
        cin>>x>>y>>amount;
        net[x] -= amount;
        net[y] += amount;
    }

    // Init a list && sort it => multiset will do
    multiset<int> m;
    for(int i=0;i<friends;i++){
        if(net[i] != 0){
            m.insert(net[i]);
        }
    }
    


    return 0;
}