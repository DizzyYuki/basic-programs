#include<iostream>
#include<iomanip>
using namespace std;

class queue{
    private:
        int size;
        int* arr;
        int r = 0;
        int f;
    
    public:
        queue(int len){
            f = 0;
            r = 0;
            size =len;
            arr = new int[size];

        }

        int isEmpty(){
            if(f==r){
                return 1;
            }
            return 0;
        }

        int isFull(){
            if( r== size-1){
                return 1;
            }
            return -1;
        }

        void enqueue(int val){
            if(r < size-1){
                r++;
                arr[r] = val;
            }
            else{
                cout<<"Queue is full"<<endl;
            }
        }

        int dequeue(){
            if(f<r){
                f++;
                int a = arr[f];
                return a;
            }
            else{
                cout<<"Queue is empty"<<endl;
            }
        }
};

int main(){

    queue q(10);   // stores the indices yet to be explored

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
    
    cout<<i<<" ";
    visited[i]=1;
    q.enqueue(i);
    while(!q.isEmpty()){
        int node = q.dequeue();
        for(int j=0; j<7; j++){
            if(a[node][j]==1 && visited[j]==0){
                cout<<j<<" ";
                visited[j]=1;   // marks the visited nodes
                q.enqueue(j);   // stores the nodes to be explored
            }
        }
    }

    return 0;
}