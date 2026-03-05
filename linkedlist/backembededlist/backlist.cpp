#include<iostream>
using namespace std;



class link{
    public:
    int data;
    link* datalocation;

};
link *Head;

void insert(int data){
 link* temp = new link();
    temp->data = data;
    temp->datalocation = NULL;

    if (Head == NULL)
    {
        Head = temp;
        return ;
    }

    link* helper = Head;
    while (helper->datalocation != NULL)
    {
        helper = helper->datalocation;
    }

    helper->datalocation = temp;
}

void print(){

    link *printer = Head;

    cout << "your values are " << endl;
    while (printer != NULL)
    {
        cout << printer->data<<" " << printer->datalocation<<endl;

        printer = printer->datalocation;
    }
    
}





int main(){
    Head = NULL;
     int n;
    cout<<"Enter total number of data values"<<endl;
    cin>>n;

    cout<<"Enter data values"<<endl;
    for (int i = 0; i < n; i++)
    {
        int values;
        cin>>values;
        insert(values);
    }
    
    print();
    




    return 0;
}
