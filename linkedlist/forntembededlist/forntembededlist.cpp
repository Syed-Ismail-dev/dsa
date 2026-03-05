#include <iostream>
using namespace std;

class link
{
public:
    int data;
    link *datalocation;
};
link *Head;
void insert(int data)
{

    link *temp = new link();
    temp->data = data;
    temp->datalocation = Head;
    Head = temp;
}
void print(){
    link *temp = Head;
    cout << "values are" << endl;
    while (temp != NULL)
    {
        cout << temp->data<<" "<<temp<<endl;
        temp = temp->datalocation;
    }
    cout<<endl;
}


int main (){
    Head = NULL;

    int n;
    cout << "Enter number of values" << endl;
    cin >> n;
    cout << "Enter values :" << endl;
    for (int i = 0; i < n; i++)
    {
        int value;
     
        cin >> value;
        insert(value);
    }
     print();
  
   
    


    return 0 ;
}
