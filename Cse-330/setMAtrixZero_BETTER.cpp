#include <bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}
void check(vector<vector<int>> &arr, int n, int m, vector<int> &row, vector<int> &col)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                arr[i][j] = 0;
            }
        }
    }
    printMatrix(arr, n, m);
}
void setMatrixZero(vector<vector<int>> &arr, int n, int m, vector<int> &row, vector<int> &col)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    check(arr, n, m, row, col);
}
int main()
{
    vector<vector<int>> arr = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 1, 1}, {1, 1, 1, 1}};
    int n = arr.size();
    int m = arr[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    setMatrixZero(arr, n, m, row, col);
    return 0;
}