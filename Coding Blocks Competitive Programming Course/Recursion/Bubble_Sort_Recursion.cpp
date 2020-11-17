 // Bubble Sort Recursively
#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void bubble_sort(int a[],int n){
    // base case
    if(n == 1){
        return ;
    }
    // rec case
    for(int j=0;j<n-1;j++){
        if(a[j] > a[j+1]){
            swap(a[j],a[j + 1]);
        }
    }
    bubble_sort(a,n - 1);
}

void bubble_sort_recursive(int a[],int j,int n)
{
    // base 
    if(n == 1){
        return ;
    }

    if( j == n-1){
        // single pass of the current array has been done
        return bubble_sort_recursive(a,0,n-1);
        return ;
    }

    // rec case
    if(a[j] > a[j + 1]){
        swap(a[j],a[j+1]);
    }

    bubble_sort_recursive(a,j+1,n);
    return;
}

// main
int main(){
    int a[] = {5,4,3,1,2};
    int n = 5;
    bubble_sort(a,n);
    return 0;
}