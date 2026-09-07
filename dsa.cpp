#include<iostream>
#include<string>

using namespace std;

int main ()
{
    string str = "ab cd ef";

    int i = 0;
    int f = str.size() - 1;

    while( i < f)
    {
        char c = str[i] ;
        str[i] = str[f];
        str[f] = c;
        i++;
        f--;
        
    }

    cout<<str<<endl;
    return 0;
}
