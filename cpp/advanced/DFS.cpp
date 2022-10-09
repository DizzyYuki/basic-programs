#include<iostream>
#include<iomanip>
using namespace std;

void DFS(int i, int arr[][7], int visited[7]){   // indirectly stack based
    cout<<i<<" ";
    visited[i]=1;
    for(int j=0;j<7;j++){    // exploring a visited node
        if(arr[i][j]==1 && visited[j]==0){
            DFS(j, arr, visited);
        }
    }
}

int main(){

    int visited[7] = {0,0,0,0,0,0,0};   // stores the indices that are visited
    int i=1;      // starting node: can be 0 1 2 3 4 5 6
    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    
    DFS(i, a, visited);

    return 0;
}