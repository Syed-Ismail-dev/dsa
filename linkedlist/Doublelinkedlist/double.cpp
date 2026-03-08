#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* previous;
    node* next;
    node(int data){
        this->data = data;
        previous = nullptr;
        next = nullptr;

    }
};

class doublelist{
    private:
    node* Head;
    node* Tail;
    public:
    doublelist(){
        Head= nullptr;
        Tail= nullptr;
    }
    void insert(int data){
        node* temp = new node(data);
        if (Head == nullptr)
        {
            Head= temp;
            Tail = temp;
            return;
        }
        Head->previous = temp;
        temp->next = Head;
        Head= temp;

        
    }
    void print(){
        node* helper= Head;
        while (helper != nullptr)
        {
         cout<<helper->data<<" ";
         helper = helper->next;
        }
        cout<<endl;
    }
    void Rprint(){
        node* helper = Tail;
        while (helper != nullptr)
        {
            cout << helper->data << " ";
            helper = helper->previous;
        }
        cout<<endl;
    }


};


int main(){
    doublelist test;
    for (size_t i = 1; i <= 5; i++)
    {
        test.insert(i);
    }
    cout<<"current values : ";
    test.print();
    cout<<endl;
    cout<<"reversed values : ";
    test.Rprint();
    cout<<endl;
}