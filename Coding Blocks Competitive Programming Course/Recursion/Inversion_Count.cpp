#include<bits/stdc++.h>
using namespace std;

// Inversion Count

int merge(int * a, int s, int e){
    int mid = (s + e) / 2;
    int i =s;
    int j = mid + 1;
    int k = s;
    int temp[100000];
    int cnt = 0; // cross inversions
    while(i <= mid && j <= e){
        if(a[i] <= a[j]){
            temp[k] = a[i];
            k++;
            i++;
        }
        else{
            temp[k++] = a[j++];
            cnt += mid - i + 1;
        }
    }
    // fill the array if some elements are left in one of the arrays
    while( i <= mid){
        temp[k++] = a[i++];
    }

    while( j <= e){
        temp[k++] = a[j++];
    }
    // copy all the elements back to array a
    for(int i=s;i<=e;i++){
        a[i] = temp[i];
    }
    return cnt;
}

int inversion_count(int * arr, int s , int e){
    // base case 
    if(s >= e){
        return 0;
    }

    // merge sort
    int mid = (s + e) / 2;
    int x = inversion_count(arr,s,mid);
    int y = inversion_count(arr,mid+1,e);
    int z = merge(arr,s,e);// cross inversion
    return x + y + z;
}

int main(){

    int arr[] = {1,5,2,6,3,0};
    int n = sizeof(arr)/sizeof(int);
    cout<<inversion_count(arr,0,n-1)<<endl;
    return 0;
}