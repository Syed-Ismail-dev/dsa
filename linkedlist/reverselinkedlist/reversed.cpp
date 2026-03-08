#include <iostream>
#include <memory>
using namespace std;
class node
{
public:
    int data;
    unique_ptr<node> next;
    node(int data, unique_ptr<node> next)
    {
        this->data = data;
        this->next = move(next);
    }
};
class reversed
{
private:
    unique_ptr<node> Head;

public:
    reversed()
    {
        Head = nullptr;
    }
    void insert(int data)
    {
        unique_ptr<node> temp = make_unique<node>(data, move(Head));
        Head = move(temp);
    }

    void reveres()
    {
        unique_ptr<node> helper = move(Head);

        unique_ptr<node> reversed = nullptr;
        while (helper != nullptr)
        {
            unique_ptr<node> previous = move(helper);

            if (previous->next == nullptr)
            {
                previous->next = move(reversed);
                reversed = move(previous);
                break;
            }
            

            unique_ptr<node> current = move(previous->next);

            previous->next = move(reversed);

            unique_ptr<node> next = move(current->next);

            current->next = move(previous);

            reversed = move(current);

            helper = move(next);
        }

        Head = move(reversed);
    }

    void print()
    {
        node *temp = Head.get();
        cout << "Values: ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next.get();
        }
    }
};

int main()
{

    {
        reversed test;
        for (size_t i = 1; i <= 5; i++)
        {
            test.insert(i);
        }

        test.print();
        cout << endl
             << "revesed ";
        test.reveres();
        test.print();
        cout << endl;
    };
    return 0;
}
