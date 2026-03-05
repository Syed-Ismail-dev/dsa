#include <iostream>
using namespace std;
//****************************sample logic test */
// int arr[5];
// int fornt = -1;
// int rare = -1;

// void push(int data){
//     if (rare == 4)
//     {
//         cout<<"queue is full"<<endl;
//         return;
//     }

//     arr[++rare] = data;

//     if (rare == 0)
//     {
//         ++fornt;
//     }

// }

// void pop(){
//     if (fornt == -1)
//     {
//         cout<<"data not exists"<<endl;
//         return;
//     }
//     ++fornt;

// }

// void print()
// {
//        for (size_t i = fornt; i <= rare; i++)
//           {
//                  cout<<arr[i]<<"  "<<"fornt:"<<fornt<<"rare:"<<rare<<"  ";
//             }
// }

// int main(){
//     push(1);
//     print();
//     cout << endl;
//     push(2);
//     print();
//     cout << endl;
//     push(3);
//     print();
//     cout << endl;
//     push(4);
//     print();
//     cout << endl;
//     push(5);
//     print();
//     cout<<endl;
//     pop();
//     cout<<endl;
//     print();
// return 0;
// }
 //*********************actal code */


class queue
{
private:
    int *arr;
    int fornt;
    int rare;
    int size;

public:
    queue(int size)
    {
        this->size = size;
        fornt = -1;
        rare = -1;
        arr = new int[size];
    }
    void push(int data)
    {
        if (rare == this->size - 1)
        {
            cout << "queue is full" << endl;
            return;
        }

        arr[++rare] = data;
        if (rare == 0)
        {

            ++fornt;
        }
    }
    void pop()
    {
        if (fornt == -1)
        {
            cout << "Data does not exist to remove" << endl;
            return;
        }
        if (fornt >= size)
        {
           cout<<"nothing to pop"<<endl;

           fornt = -1;
           rare = -1;
           return;
        }

        ++fornt;
      
    }
    void print()
    {

        for (size_t i = fornt; i <= rare; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

int main()
{

    queue test(5);
    test.push(1);
    test.push(2);
    test.push(3);
    test.push(4);
    test.push(5);
    // test.print();
    cout << endl;
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    test.pop();
    // cout << endl;
    // test.print();
    // cout << endl;

    return 0;
}