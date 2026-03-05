#include <iostream>
using namespace std;
//***************sample code to test logic ************************/
// int arr[10];

// int rare = -1;
// void push(int data)
// {
//     if (rare == 9)
//     {
//         cout << "Array is full" << endl;
//         return;
//     }

//     arr[++rare] = data;
// }

// void pop()
// {
//     if (rare == -1)
//     {
//         cout << "empty array" << endl;
//         return;
//     }

//     rare--;
// }
// void print()
// {
//     for (size_t i = 0; i <= rare; i++)
//     {
//         cout << arr[i] << " ";
//     }
// }
// void top()
// {
//     if (rare == -1)
//     {
//         cout << "Array is empty" << endl;
//         return;
//     }

//     cout << endl
//          << arr[rare] << endl;
// }

// int main()
// {

//     push(5);
//     push(2);
//     push(3);
//     push(4);

//     print();
//     cout << endl;
//     top();
//     pop();

//     print();
//     cout << endl;
//     top();

//     return 0;
// }

//************acutal code working professionally *********************/


class stack{
    private:
    int *arr;
    int top_index;
    int size;
    public:
    stack(int size){
        this->size = size;
        top_index = -1;
        arr = new int[this->size];
    }
    void push(int data){
        if (top_index == this->size-1)
        {
            cout<<"Error: Array is full"<<endl;
            return;
        }
        arr[++top_index] = data;
    }
    void pop(){
        if (top_index == -1)
        {
            cout<<"Error: Array is empty"<<endl;
            return;
        }
        top_index--;
    }
    void isempty(){
        if (top_index == -1)
        {
            cout<<"Error: Array is empty"<<endl;
        }

    }
     void top(){
         if (top_index == -1)
         {
             cout << "Error: Array is empty" << endl;
             return;
         }
         cout << arr[top_index] << endl;
    }
    void print(){
        if (top_index == -1)
        {
            cout << "Error: Array is empty" << endl;
            return;
        }
        for (size_t i = 0; i <= top_index; i++)
        {
            cout << arr[i] ;
        }
        
    }

};


void main(){
    stack arr_1(5);
    arr_1.push(1);
    arr_1.push(2);
    arr_1.push(3);
    arr_1.push(4);
    arr_1.push(5);
    arr_1.print();
    arr_1.pop();
    cout<<endl;
    arr_1.print();
    cout<<endl;
    arr_1.top();



}