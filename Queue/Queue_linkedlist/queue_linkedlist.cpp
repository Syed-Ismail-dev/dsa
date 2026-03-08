#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *datalocation;
};
class queue
{
private:
    node *Head;
    node *Tail;

public:
    queue()
    {
        Head = nullptr;
        Tail = nullptr;
    }
    void push(int data)
    {
        node *temp = new node();
        temp->data = data;
        temp->datalocation = nullptr;
        if (Head == nullptr)
        {
            Head = temp;
            Tail = temp;
            return;
        }
        Tail->datalocation = temp;
        Tail = temp;
    }

    void pop()
    {
        if (Head == nullptr && Tail == nullptr)
        {
            cout << "data does not exist to remove" << endl;
            return;
        }


        node *temp = Head;
        Head = Head->datalocation;
        if (Head == nullptr)
        {
            Tail = nullptr; 
        }
        

        delete (temp);
    }

    void print()
    {
        node *helper = Head;

        while (helper != nullptr)
        {
            cout << helper->data << " ";
            helper = helper->datalocation;
        }
    }
    ~queue()
    {

        while (Head != nullptr)
        {

            pop();
        }
    }
};

int main()
{

    {
        queue test;
        test.push(1);
        test.push(2);
        test.push(3);
        test.push(4);
        test.print();
        cout << endl;
        test.pop();
        test.print();
        cout << endl;
    }

    return 0;
}