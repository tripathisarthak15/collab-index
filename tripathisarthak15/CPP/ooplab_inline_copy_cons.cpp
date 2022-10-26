#include <iostream>
using namespace std;

class sarthak
{
    public:
    int a;
    sarthak(int x)
    {
        a=x;
    }

    sarthak(sarthak &s1)
    {
        a=s1.a;
    }

    void display()
    {
        cout<<a<<endl;
    }


};

inline void add(sarthak s1, sarthak s2)
{
    cout<<s1.a+s2.a<<endl;
}

int main()
{
    sarthak s3(10);
    sarthak s4(s3);
    s3.display();
    s4.display();

    add(s3,s4);

    return 0;



}