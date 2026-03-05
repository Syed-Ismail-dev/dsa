// using Tail node for inserting a node at back of list at constant time

#include <iostream>
using namespace std;

class link
{
public:
    int data;
    link *datalocation;
};
link *Head;
link *Tail;

void insert(int data)
{
    link *temp = new link();
    temp->data = data;
    temp->datalocation = NULL;

    if (Head == NULL)
    {
        Head = temp;
        Tail = temp;
        return;
    }
    Tail->datalocation = temp;//tail has the access of previous node( Head->node1->node2<-tail) so we easy can insert new node at last with constant time 
    Tail = temp;
}

void print()
{

    link *printer = Head;

    cout << "your values are " << endl;
    while (printer != NULL)
    {
        cout << printer->data << " " << printer->datalocation << endl;

        printer = printer->datalocation;
    }
}

int main()
{
    Head = NULL;
    Tail = NULL;
    int n;
    cout << "Enter total number of data values" << endl;
    cin >> n;

    cout << "Enter data values" << endl;
    for (int i = 0; i < n; i++)
    {
        int values;
        cin >> values;
        insert(values);
    }

    print();

    return 0;
}
