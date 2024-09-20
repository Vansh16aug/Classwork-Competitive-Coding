#include <bits/stdc++.h>
using namespace std;
void markRow(vector<vector<int>> &arr, int n, int m, int i)
{
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}
void markCol(vector<vector<int>> &arr, int n, int m, int j)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}
void printMatrix(vector<vector<int>> arr, int n, int m)
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

// -1 to 0
void convertBack(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
            {
                arr[i][j] = 0;
            }
        }
    }
    
    printMatrix(arr, n, m);
}
// to -1
void setMatrixzero(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                markRow(arr, n, m, i);
                markCol(arr, n, m, j);
            }
        }
    }
    convertBack(arr, n, m);
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 1, 1}, {1, 1, 1, 1}};
    setMatrixzero(arr);
    
    return 0;
}