#include <iostream>
#include <memory>
using namespace std;
class circular
{
private:
    unique_ptr<int[]> arr;
    int size;
    int fornt;
    int rare;

public:
    circular(int size)
    {

        this->size = size;
        fornt = -1;
        rare = -1;
        arr = make_unique<int[]>(size);
    }

    void push(int data)
    {
        if (rare == this->size - 1 && fornt == 0)
        {
            cout << "queue is full" << endl;
            return;
        }
        if (rare == this->size - 1)
        {
            rare = (rare + 1) % this->size;
            arr[rare] = data;
            return;
        }

        arr[++rare] = data;

        if (fornt == -1)
        {
            ++fornt;
        }
    }

    void pop()
    {
        if (fornt == this->size - 1)
        {
            fornt = (fornt + 1) % this->size;
            return;
        }
        ++fornt;
    }
    void print()
    {
        if (fornt <= rare)
        {
            for (size_t i = fornt; i < this->size; i++)
            {
                cout << arr[i] << " ";
            }
            return;
        }

        if (rare < fornt)
        {
            for (size_t i = fornt; i < this->size; i++)
            {
                cout << arr[i] << " ";
            }
            for (size_t i = rare; i < fornt; i++)
            {
                cout << arr[i] << " ";
            }
        }
    }
};

int main()
{

    {
        circular test(5);
        test.push(1);
        test.push(2);
        test.push(3);
        test.push(4);
        test.push(5);
        test.print();
        cout << endl;
        test.pop();
        test.print();
        cout << endl;
        cout << "is circular" << endl;
        test.push(6);
        test.print();
        cout << endl;
    }
    return 0;
}