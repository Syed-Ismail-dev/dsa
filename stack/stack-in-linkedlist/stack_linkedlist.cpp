#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*datalocation;
};
class stack{
    private:
    node* Top;
    public:
    stack(){
        Top = NULL;

    }

    void push(int data){
        node* temp = new node();
        temp->data = data;
        temp->datalocation = Top;
        Top = temp;
    }
    void pop(){
        if (Top == NULL)
        {
            cout<<"ERROR: stack is empty"<<endl;
            return;
        }
        node*helper = Top;
        Top = helper->datalocation;
        delete(helper);

        
    }
   int top(){
        if (Top == NULL)
        {
            cout << "ERROR: stack is empty" << endl;
            return -1;
        }
        cout<<Top->data<<endl;
    }

    void isempty(){
        if (Top == NULL)
        {
            cout << "stack is empty" << endl;
            
        }else{
            cout<<"stack is not empty"<<endl;
        }
        
    }
    ~stack()
    {
        while (Top != NULL)
        {
            pop();
        }
    }
    void print(){
        node*helper = Top;
       while (helper != NULL)
       {
        cout<<helper->data<<" ";
        helper = helper->datalocation;
       }
       
        
    }


};