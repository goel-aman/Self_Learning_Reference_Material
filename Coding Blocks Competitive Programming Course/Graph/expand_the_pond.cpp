#include <bits/stdc++.h>
using namespace std;
// #define int long long int

class graph
{
    public:
    int bfs(int **matrix, int n, int m)
    {
        unordered_map<int,int> u_count;
        bool visited[n][m];
        memset(visited, 0, sizeof(visited));
        int value = 2;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (!visited[i][j]){
                    visited[i][j] = true;
                    if (matrix[i][j] == 1){
                        u_count[value] += 1;
                        matrix[i][j] = value;
                        queue<pair<int, int>> q;
                        q.push(make_pair(i,j));
                        while (!q.empty()){
                            pair<int,int> front = q.front();
                            q.pop();
                            int ii = front.first;
                            int jj = front.second;
                            if(ii+1 <= (n-1) && jj <= (m-1) && ii+1 >= 0 && jj >= 0 && !visited[ii+1][jj] && matrix[ii+1][jj] == 1){
                                q.push(make_pair(ii+1,jj));
                                visited[ii+ 1][jj] = true;
                                u_count[value] += 1;
                                matrix[ii+1][jj] = value;
                            }
                            if(ii <= (n - 1) && (jj+1) <= (m-1) && ii >= 0 && jj+1 >= 0 && !visited[ii][jj+1] && matrix[ii][jj+1] == 1){
                                q.push(make_pair(ii,jj + 1));
                                visited[ii][jj+1] = true;
                                u_count[value] += 1;
                                matrix[ii][jj+1] = value;
                            }
                            if(ii <= (n - 1) && ii >= 0 && (jj-1) <= (m-1) && jj-1 >= 0 && !visited[ii][jj-1] && matrix[ii][jj-1] == 1){
                                q.push(make_pair(ii,jj-1));
                                visited[ii][jj-1] = true;
                                u_count[value] += 1;
                                matrix[ii][jj-1] = value;
                            }

                            if(ii-1 <= n-1 && ii-1 >= 0 && jj <= (m-1) && jj >= 0 && !visited[ii-1][jj] && matrix[ii-1][jj] == 1){
                                q.push(make_pair(ii-1,jj));
                                visited[ii-1][jj] = true;
                                u_count[value] += 1;
                                matrix[ii-1][jj] = value;
                            }
                        }
                        value++;
                    }
                }
            }
        }

        int maximum_value = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == 0){
                    set<int> v;
                    if(i-1 < n && i-1 >= 0 && j >= 0 && j < m && matrix[i-1][j] != 0){
                        v.insert(matrix[i-1][j]);
                    }
                    if(i+1 < n && i+1 >= 0 && j>=0 && j< m && matrix[i+1][j] != 0){
                        v.insert(matrix[i+1][j]);
                    }
                    if(i < n && i >= 0 && j+1 >= 0 && j+1 < m && matrix[i][j+1] != 0){
                        v.insert(matrix[i][j+1]);
                    }
                    if(i < n && i >= 0 && j-1 < m && j-1 >= 0 && matrix[i][j-1] != 0){
                        v.insert(matrix[i][j-1]);
                    }
                    
                    int vall = 1;
                    for(auto val: v){
                        vall += u_count[val];
                    }
                    if(vall > maximum_value){
                        maximum_value = vall;
                    }
                }
            }
        }
        return maximum_value;

    }
};

int main()
{
    int n, m;
    cin >> n >>m;
    // cout<<n<<" "<<m<<endl;
    int **matrix = new int *[n];
    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            int value;
            cin >> value;
            matrix[i][j] = value;
        }
    }
    graph g;
    cout<<g.bfs(matrix, n, m)<<endl;
    return 0;
}