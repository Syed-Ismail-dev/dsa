#include<iostream>
#include<vector>

using namespace std;

int partition(vector<int> &arr, int st , int end)
{
    int pv = arr[end];
    int idx = st-1;
    for(int j = st; j<end; j++)
    {
        if(arr[j] < pv)
        {
            idx++;
            swap(arr[idx], arr[j]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;
}
void quick_sort(vector<int> &arr, int st, int end)
{
    if(st>=end) return;
    int pvidx = partition(arr, st, end);
    quick_sort(arr,st,pvidx-1);//left
    quick_sort(arr,pvidx+1,end);//right
}

int main()
{
    vector<int> num = {5,2,1,4,6,3};
    quick_sort(num,0,num.size()-1);
    for(int n:num)
    {
        cout<<n<<" ";
    }
    return 0;
}