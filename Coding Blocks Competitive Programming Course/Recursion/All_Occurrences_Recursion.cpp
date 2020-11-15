#include<iostream>
using namespace std;
#define ll long long int

int storeOcc(int* a,int i,int n,int key,int* out,int j){
    //base case
    if(i==n){
        return j;
    }

    if(a[i] == key){
        out[j] = i;
        return storeOcc(a,i+1,n,key,out,j+1);
    }
    // remains unchanged
    return storeOcc(a,i+1,n,key,out,j);

}

void allOcc(int * a,int i,int n,int key){
    if( i == n)
    {
        return ;
    }

    if(a[i] == key){
        cout<<i<<" ";
    }

    allOcc(a,i+1,n,key);
}

int main(){
    int key = 17;
    int arr[] = {1,2,3,17,4,5,6,17,10};
    int n = sizeof(arr)/sizeof(int);
    allOcc(arr,0,n,key);

    int output[100];
    int cnt = storeOcc(arr,0,n,key,output,0);
    cout<<"Count "<<cnt<<endl;
    for(int k =0;k<cnt;k++){
        cout<<output[k]<<" ";
    }
    return 0;
}