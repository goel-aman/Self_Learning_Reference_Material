#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#define ll long long int

class fenwick{
    public:
    vector<int> f;
    int n;

    void init(int n)
    {
        this->n = n;
        f.resize(n + 1,0);
    }
    
    void update(int index,int val){
        index++;
        while(index <= n){
            f[index] += val;
            index += (index & (-index)); 
        }
    }

    int query(int index){
        index++;
        int sum = 0;
        while(index){
            sum += f[index];
            index -= (index & (-index));
        }
        return sum;
    }
    
};

int main(){
    ll n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    fenwick arr[26];
    for(int i=0;i<26;i++){
        arr[i].init(n);
    }
    for(int i=0;i<s.length();i++){
        int k = s[i] - 'a';
        arr[k].update(i,1);        
    }
    while(q){
        int num;
        cin>>num;
        if(num == 1){
            int lth;
            cin>>lth;
            char c;
            cin>>c;
            int ss = c - 'a';
            int m = s[lth - 1] - 'a';
            arr[m].update(lth-1,-1);
            arr[ss].update(lth-1,+1);
            s[lth - 1] = c;
        }
        else{
            int num1, num2;
            cin>>num1>>num2;
            string ans = "yes";
            int num_count = 0;
            for(int i=0;i<26;i++)
            {
                int k = arr[i].query(num2 - 1) - arr[i].query(num1 - 1 - 1);
                if(k%2 != 0){
                    num_count ++;
                    if(num_count > 1){
                        ans = "no";
                        break;
                    }
                }
            }
            cout<<ans<<endl;
        }
        q--;
    }
    return 0;
}

