#include<iostream>
#include<memory>
using namespace std;
class node{
   public:
    int data;
    node* prev;
    unique_ptr<node> next;
    node(int data, node* prev = nullptr, unique_ptr<node> next = nullptr)
    {
        this->data = data;
        this->prev = prev;
        this->next = move(next);
    }
};

class doublelist{
    private:
    unique_ptr<node> Head;
    node* Tail;
   

public:
    doublelist(){
        Head = nullptr;
        Tail = nullptr;
    }

    void insert(int data){
       auto temp = make_unique<node>(data);
       node* prevnode = temp.get();
        if (Head == nullptr && Tail == nullptr)
        {
            Tail = prevnode;
            Head = move(temp);
            cout<<"temptail : "<<Tail<<endl;
            return;
        }
        temp->next = move(temp);
        temp->next->prev = prevnode;
        Head = move(temp);

    }
   
    void print(){
        node *helper = Head.get();
        while (helper != nullptr)
        {
            cout<<helper->data<<" ";
            helper = helper->next.get();
        }
        
    }

    void Rprint(){
       node* helper = Tail;
       cout<<"tail: "<<helper<<endl;
        while (helper != nullptr)
        {
            cout<<helper->data<<" ";
            helper = helper->prev;
        }
        
    }

};

int main(){
    {
        doublelist test;
        for (size_t i = 1; i <=5; i++)
        {
            test.insert(i);
        }
        cout << "forward ";
        test.print();
        cout<<endl<<"reversed";
        test.Rprint();


    }



    return 0;
}