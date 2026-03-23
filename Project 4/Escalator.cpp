#include<iostream>
using namespace std;

class Stack
{
    int arr[100];
    int top;
    int size;

public:

    Stack(int s)
    {
        size = s;
        top = -1;
    }

    void push(int x)
    {
        if(top == size - 1)
        {
            cout<<"Stack full"<<endl;
        }
        else
        {
            top = top + 1;
            arr[top] = x;
            cout<<"Pushed"<<endl;
        }
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack empty"<<endl;
        }
        else
        {
            cout<<"Deleted element: "<<arr[top]<<endl;
            top = top - 1;
        }
    }

    void peek()
    {
        if(top == -1)
        {
            cout<<"No element"<<endl;
        }
        else
        {
            cout<<"Top element: "<<arr[top]<<endl;
        }
    }

    void checkEmpty()
    {
        if(top == -1)
            cout<<"Empty"<<endl;
        else
            cout<<"Not empty"<<endl;
    }

    void checkFull()
    {
        if(top == size - 1)
            cout<<"Full"<<endl;
        else
            cout<<"Not full"<<endl;
    }
};

int main()
{
    int n;
    cout<<"Enter size: ";
    cin>>n;

    Stack s(n);

    int ch, val;

    do
    {
        cout<<"\n1 Push\n2 Pop\n3 Peek\n4 Empty?\n5 Full?\n0 Exit\n";
        cout<<"Enter choice: ";
        cin>>ch;

        if(ch == 1)
        {
            cout<<"Enter value: ";
            cin>>val;
            s.push(val);
        }
        else if(ch == 2)
        {
            s.pop();
        }
        else if(ch == 3)
        {
            s.peek();
        }
        else if(ch == 4)
        {
            s.checkEmpty();
        }
        else if(ch == 5)
        {
            s.checkFull();
        }

    } while(ch != 0);

    return 0;
}