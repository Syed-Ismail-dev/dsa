#include<iostream>
#include<vector>
using namespace std;


void merge(vector<int> &arr, int st,int mid, int end);

void mergeSort(vector<int> &arr, int st, int end)
{
    if(st >= end) return;
    int mid = st + (end-st)/2;
    mergeSort(arr, st, mid);//left
    mergeSort(arr, mid+1, end);//right
    merge(arr, st,mid, end);
}

void merge(vector<int> &arr, int st,int mid, int end)
{
    vector<int> temp;   
    int i = st;
    int j = mid+1;
    while(i <= mid && j <= end)
    {
        if(arr[i] < arr[j])
        {
           temp.push_back(arr[i++]);

            
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while(i<=mid)
    {
        temp.push_back(arr[i++]);
    }
    while(j<=end)
    {
        temp.push_back(arr[j++]);
    }
    for(int inx= 0,n= temp.size(); inx<n; inx++)
    {
        arr[st+inx] = temp[inx];
    }

    return;
    
}

int main()
{
    vector<int> v = {12, 31, 35, 8, 32, 17};
    int st = 0;
    int end = v.size();
    mergeSort(v,st,end-1);
    for(int num:v)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}