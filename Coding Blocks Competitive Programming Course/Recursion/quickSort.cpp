#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int partition(int *a,int s,int e){
    // Inplace (Can't take extra array)
    int i = s - 1;
    int j = s;

    int pivot = a[e];
    for( ;j<=e-1;){
        if(a[j] <= pivot){
            // merge the smaller element in the region - 1
            i = i + 1;
            swap(a[i],a[j]);
        }
        // expand the larger region
        j = j + 1;
    }

    // place the pivot element in the correct index
    swap(a[i + 1], a[e]);
    return i +1 ;
}

void quickSort(int* arr,int s,int e){
    // base case
    if(s >= e){
        return ;
    }

    // recursive case
    int p = partition(arr,s,e);
    // left part
    quickSort(arr,s,p-1);
    // right part
    quickSort(arr,p+1,e);


}


int main(){
    int arr[] = {2,7,8,6,1,5,4};
    int n = sizeof(arr)/sizeof(int);
    quickSort(arr,0,n-1);
    for(int i=0;i<=n-1;i++){
        cout<<arr[i]<<' ';
    }
    return 0;
}