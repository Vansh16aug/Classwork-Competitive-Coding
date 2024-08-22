#include<bits/stdc++.h>
using namespace std;
void spiralMatrix(vector<vector<int>> arr){
    int n = arr.size();
    int m = arr[0].size();
    int top = 0;
    int left = 0;
    int right = m - 1;
    int bottom = n - 1;

    while(top<=bottom && left<=right){
        // left -> right
        for(int i=left;i<=right;i++){
            cout<<arr[top][i]<<" ";
        }
        top++;
        // top -> bottom
        for(int i=top;i<=bottom;i++){
            cout<<arr[i][right]<<" ";
        }
        right--;
        // right -> left
        if(top<=bottom){        // if top has already crossed the bottom
            for(int i=right;i>=left;i--){
            cout<<arr[bottom][i]<<" ";
        }
        bottom--;
        }
        //bottom -> top
        if(left<=right){         // if left has already crossed the right
            for(int i=bottom;i>=top;i--){
            cout<<arr[i][left]<<" ";
        }
        left++;
        }
    }
}
int main()
{
    vector<vector<int>> arr = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    spiralMatrix(arr);
    return 0;
}
