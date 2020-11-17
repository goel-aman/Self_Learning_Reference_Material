#include<iostream>
using namespace std;

int stringToInt(string a,int n)
{
    if(n == 0){
        return 0;
    }

    int digit = a[n - 1] - '0';
    int small_ans = stringToInt(a,n-1);
    return small_ans * 10 + digit;

}

int main(){
    string a = "1234";
    int leng = a.length();
    int x = stringToInt(a,leng);
    cout<<x<<endl;
    cout<<x + 1<<endl;
    return 0;
}