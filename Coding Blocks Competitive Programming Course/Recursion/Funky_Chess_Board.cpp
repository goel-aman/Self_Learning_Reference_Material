#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main()
{
    int n;
    cin >> n;
    int matrix[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int num;
            cin >> num;
            matrix[i][j] = num;
        }
    }
    v.push_back({+2, 1});
    v.push_back({+2, -1});
    v.push_back({-2, 1});
    v.push_back({-2, -1});
    v.push_back({1, 2});
    v.push_back({-1, 2});
    v.push_back({1, -2});
    v.push_back({-1, -2});

    
    return 0;
}