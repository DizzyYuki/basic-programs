#include<iostream>
using namespace std;

bool isPresent(int arr[],int n,int k)
{
    for(int i=0;i<n;i++)
        if(arr[i]==k)
            return true;
    return false;
}

int BinarySearch(int arr[],int n,int k)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(arr[mid]==k)
            return mid;
        else if(arr[mid] < k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[]={2,5,9,10,36,78};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target=10;
    cout<<BinarySearch(arr,size,target)<<endl;

    return 0;
}