#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[9000];
    int n,i,val,diff;

    while(1){
        // Take Input Current Test Case
        int max_load = 0 , load = 0;
        cin>>n;
        // Stop taking input if N = -1
        if(n == -1){
            break;
        }

        for(int i=0;i<n;i++){
            cin>>arr[i];
            load += arr[i];
        }
        if(load%n != 0){
            cout<<-1<<endl;
            continue;
        }
        // find the load that is to be divided equally
        load = load / n;
        // greedy step
        diff = 0;
        for(int i=0;i<n;i++){
            // find the difference btw final load to be assigned and current load
            diff += arr[i] - load;
            max_load = max(max_load,abs(diff));
        }
        cout<<max_load<<endl;
    }
    return 0;
}