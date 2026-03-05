#include<iostream>
using namespace std;

class link{
    public:
    int data;
    link* datalocation;
    

};

link*Head = NULL;
link*Tail = NULL;

 int max_node = 0;
void create (int data){

    link *temp = new link();
    temp->data = data;
    temp->datalocation = NULL;
    max_node++;
     if (Head == NULL && Tail == NULL)
    {
        Head = temp;
        Tail = temp;
        return ;

    }
  Tail->datalocation = temp;
    Tail = temp;
   
}


void insertat(int data, int position){
    if ( position <1 || position > max_node + 1)
    {
        cout << " Position invalid "<<endl;
        return;
    }
    
    if (Head == NULL)
    {
        cout<<" Data not existed to insert "<<endl;
        return;
    }
    
    if (position == 1)
    {
        link *temp = new link();
        temp->data = data;
        temp->datalocation = Head;
        Head = temp;
        if(Tail == NULL){
            Tail = temp;
        }
        max_node++;

        return;
    }
 

    link *temp = new link();
    temp->data = data;
    temp->datalocation = NULL;

    link *helper = Head;
    for (size_t i = 1; i < position-1 && helper !=NULL; i++)
    {
        helper = helper->datalocation;
    }

    temp->datalocation = helper->datalocation;
    helper->datalocation = temp;
    max_node++;


  if ( position == max_node)
  {
    Tail= temp;
  }
  if (Tail == NULL)
  {
      Tail = temp;
  }
}

void remove(int position){

    if (position <1 || position > max_node)
    {
        cout << "Invalid position" << endl;
        return;
    }
link*helper= Head;
link*temp;


if (position == 1)
{
    temp = Head;
    Head = temp->datalocation;

    if (Head == NULL)
    {
        Tail = NULL;
    }
    delete (temp);
    max_node--;
    return;
}

for (size_t i = 1; i < position-1; i++)
{
    helper = helper->datalocation;
}

temp = helper->datalocation;
helper->datalocation = temp->datalocation;
if (temp == Tail)
{
    Tail = helper;
}
delete(temp);
max_node--;
}