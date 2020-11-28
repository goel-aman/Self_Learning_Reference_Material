#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {20,30,40,40,40,50,100,1100};
    int n = sizeof(arr)/sizeof(int);
    // search in a sorted array.

    int key;
    cin>>key;
    bool present = binary_search(arr,arr+n,key);
    if(present){
        cout<<"present";
    }else{
        cout<<"absent";
    }
    cout<<endl;
    // Two more things.
    // Get the index of the elemnt
    // lower_bound(s,e,key)

    auto it = lower_bound(arr,arr+n,40);
    cout<<it-arr<<endl;
    
    // upper bound
    auto itt = upper_bound(arr,arr+n,40);
    cout<<itt-arr<<endl;

    cout<<"Occurence Freq of 40 is "<<itt - it<<endl;
    return 0;
}