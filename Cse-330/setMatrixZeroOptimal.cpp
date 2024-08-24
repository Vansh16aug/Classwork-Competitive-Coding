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
void markTheCol(vector<vector<int>> &arr, int n, int m, int col0)
{
    // we have to check if the dummy col0 is zero to mark arr[i][0]
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = 0;
        }
    }
    printMatrix(arr, n, m);
}
void markTheRow(vector<vector<int>> &arr, int n, int m, int col0)
{
    // we have to check if arr[0][0] is zero to mark arr[0][j]
    if (arr[0][0] == 0) // if the marking is zero
    {
        for (int j = 0; j < m; j++)
        {
            arr[0][j] = 0;
        }
    }
    markTheCol(arr, n, m, col0);
}
void markToZero(vector<vector<int>> &arr, int n, int m, int col0)
{
    // iterate from the remaining ele not from the marking we made in arr[i][0] and arr[0][j]
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            // if ele is not zero
            if (arr[i][j] != 0)
            {
                // if one of the marking is zero
                if (arr[i][0] == 0 || arr[0][j] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }
    markTheRow(arr, n, m, col0);
}

void setMatrixXero(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    int col0 = 1; // dummy [0][0] ele

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                // if we did arr[0][j] = 0 , then we will alter the value is req later
                if (j != 0)
                {
                    // if it is pointing to anything else 0 means we are not in 0th row then we can mark
                    arr[0][j] = 0;
                }
                else
                {
                    // if we are pointing to the 0th row where we dont want to alter arr[0][0] , instead we made col0 .
                    col0 = 0;
                }
            }
        }
    }
    // we have to create row[n] and col[m] and create markings
    markToZero(arr, n, m, col0);
}
int main()
{
    vector<vector<int>> arr = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 0, 1, 1}, {1, 1, 1, 1}};
    setMatrixXero(arr);
    return 0;
}