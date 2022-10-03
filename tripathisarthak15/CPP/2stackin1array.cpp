#include <iostream>
#include <stdlib.h>
using namespace std;

#define size 12

int arr[size],top1=-1,top2=12,i;

void push1(int el)
{   
    if(top2-top1>1)
    {
        top1=top1+1;
        arr[top1]=el;

    }
    else
    cout<<"Overflow!";

    
}

void push2(int el)
{
     if(top2-top1>1)
    {
        top2=top2-1;
        arr[top2]=el;
    }

    else
    cout<<"Overflow!";
}

void pop1()
{
    if(top1==-1)
    cout<<"Underflow";
    else
    {   
        cout<<"Element popped: "<<arr[top1];
        top1=top1-1;

    }
}

void pop2()
{
    if(top2==12)
    cout<<"Underflow";
    else
    {   
        cout<<"Element popped: "<<arr[top2];
        top2=top2+1;

    }
}

void display1()
{   cout<<"Stack 1:\n ";
    for(i=0;i<=top1;i++)
    {
        cout<<" "<<arr[i];
    }
}

void display2()
{   cout<<"Stack 2:\n ";
    for(i=size-1;i>=top2;i--)
    {
        cout<<" "<<arr[i];
    }
}

int main()
{
    int ch,ch2,_el;

    while(1)
    {
        cout<<"\n\nEnter your choice from the operations available here:\n1.Push\n2.Pop\n3.Display\n4.Exit\n\nEnter Choice: ";
        cin>>ch;

        switch(ch)
        {
            case 1:     cout<<"Enter Element to push into stack: "; cin>>_el;
            
                        cout<<"\nPush Operation:\nChoose Stack :\n1. Stack 1\n2. Stack 2\nEnter Choice: ";
                        cin>>ch2;
                        switch(ch2)
                        {
                            case 1: push1(_el); break;
                            case 2: push2(_el); break;
                            
                                    
                            default: cout<<"Invalid Input!"; break;
                        }
                        break;
            case 2:     cout<<"\nPop Operation:\nChoose Stack :\n1. Stack 1\n2. Stack 2\nEnter Choice: ";
                        cin>>ch2;
                        switch(ch2)
                        {
                            case 1: pop1(); break;
                            case 2: pop2(); break;
                                 
                            default: cout<<"Invalid Input!"; break;
                        }
                        break;
            
            case 3:     cout<<"\nDisplay\n___________\nChoose Stack to Display-\n1. Stack 1\n2. Stack 2\nEnter Choice: ";
                        cin>>ch2;
                        if(ch2==1)
                        display1();
                        else if(ch2==2)
                        display2();
                        else
                        cout<<"Invalid Input! Try again.";
                        break;

            case 4:     cout<<"\nAre you sure that you want to exit?\nEnter Y or N\nEnter Choice: ";
                        char a;
                        cin>>a;
                        if(a=='Y' || a=='y')
                        {   cout<<"\nAborting Process....";
                            exit(0);
                        }
                    
                        else
                        cout<<"\nNo or Invalid Input received.... Returning Back to Operations page.\n";
                        break;
            
            default:    cout<<"Invalid Input! Try Again.";
                        break;
        }
    }
    return 0;
}