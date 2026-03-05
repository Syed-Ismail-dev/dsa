#include <iostream>
using namespace std;

int main(){
    
    int arr[10];
    
    cout<<"Enter your data upto ten vaues"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cin>> arr[i];
    }

    cout<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout<< arr[i]<<endl;
    }
    cout<<&arr[0];




    return 0 ;
}