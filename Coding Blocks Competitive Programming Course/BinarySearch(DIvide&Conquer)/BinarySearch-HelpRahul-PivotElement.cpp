#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int find(int a[],int n,int key){
    int  s = 0;
    int e = n - 1;
    while(s <= e){
        int mid = (s + e) / 2;
        if(a[mid] == key){
            return mid;
        }
        else if(a[s] <= a[mid]){
            // 2 cases -> element list on the left or the right of the mid
            if(key >= a[s] && key <= a[mid]){
                e = mid - 1;
            }else{
                s = mid + 1;
            }
        }
        else{
            // 2 cases -> 
            if(key >= a[mid] && key <= a[e]){
                s = mid + 1;

            }else{
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int n;
    cin>>n;
    int a[1000];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int key;
    cin>>key;
    cout<<find(a,n,key);

    return 0;    
}