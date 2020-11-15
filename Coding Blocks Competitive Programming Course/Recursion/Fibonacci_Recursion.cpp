#include<iostream>
using namespace std;

int f(int n){
    
    // Base case
    if(n == 0 || n == 1){
        return n;
    }

    int f1 = f(n -1);
    int f2 = f(n - 2);
    return f1 + f2; 
}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
    return 0;
}