#include<iostream>
using namespace std;

int binsear(int arr[],int tar,int size);

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int tar ;
    int size = sizeof(arr) / sizeof(arr[0]);
    cout<<"Enter search number 1-9: ";
    cin>>tar;
    cout<< "target: "<<binsear(arr,tar, size)<<endl;




    return 0;
}

int binsear(int arr[],int tar, int size)
{
    int str = 0;
    int end = size - 1;
    while(str<=end)
    {
        int mid = str + (end - str) / 2;
        if(arr[mid] == tar)
        {
            return arr[mid];
        }
        else if(arr[mid] < tar)
        {
            str = mid + 1;
        }
        else
        {
            end = mid - 1 ;
        }

    }
    return -1;
}
