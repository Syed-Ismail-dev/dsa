#include<iostream>
using namespace std;

class link{
    public:
    int data;
    link* datalocation;
};

link*Head;
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
    Tail->datalocation = temp; // tail has the access of previous node( Head->node1->node2<-tail) so we easy can insert new node at last with constant time
    Tail = temp;
}

void insertat(int data,int position){
    
    if (position < 1)
    {
        cout<<" Invalid position"<<endl;
        return;
    }

    link *temp = new link();
    temp->data = data;
    temp->datalocation = NULL;
        link*Healper = Head;
        if (position !=1 && Head == NULL)
        {
            delete(temp);
            cout<<"Invaid access"<<endl;
            return ;
        }
        
        if (position == 1)
        {
            temp->datalocation = Healper;
            Head = temp;
            if(Tail == NULL)
            {
                Tail=temp;
            }
            return;
        }
        if (Head == NULL)
        {
            cout << " Data does not exists to insert" << endl;
            return;
        }

    for (size_t i = 1; i < position-1 && Healper !=NULL; i++)
    {
        Healper = Healper->datalocation;
    }
    if (Healper == NULL)
    {
        cout << "Position out of range" << endl;
        return;
    }
    temp->datalocation = Healper->datalocation;
    Healper->datalocation = temp;
if (temp->datalocation == NULL)
{
    Tail = temp;
}
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

int main(){
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
    int data, m;
    cout<<"Enter position to insert data"<<endl;
    cin>>m;
    cout<<"Enter data :"<<endl;
    cin>>data;
    insertat(data,m);
    print();

    return 0 ;

}