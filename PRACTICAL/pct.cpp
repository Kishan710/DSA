#include<iostream>
using namespace std;

class Program
{
public:

    void reverseArray()
    {
        int n, arr[100];
        cout<<"Enter size: ";
        cin>>n;

        cout<<"Enter elements: ";
        for(int i=0; i<n; i++)
            cin>>arr[i];

        for(int i=0, j=n-1; i<j; i++, j--)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }

        cout<<"Reversed array: ";
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
    }

    void checkSorted()
    {
        int n, arr[100];
        int ok = 1;

        cout<<"Enter size: ";
        cin>>n;

        cout<<"Enter elements: ";
        for(int i=0; i<n; i++)
            cin>>arr[i];

        for(int i=0; i<n-1; i++)
        {
            if(arr[i] > arr[i+1])
            {
                ok = 0;
                break;
            }
        }

        if(ok == 1)
            cout<<"Array is sorted"<<endl;
        else
            cout<<"Array is not sorted"<<endl;
    }

    void moveZeros()
    {
        int n, arr[100];
        cout<<"Enter size: ";
        cin>>n;

        cout<<"Enter elements: ";
        for(int i=0; i<n; i++)
            cin>>arr[i];

        int j = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i] != 0)
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j++;
            }
        }

        cout<<"Result: ";
        for(int i=0; i<n; i++)
            cout<<arr[i]<<" ";
    }

    void charFrequency()
    {
        char str[100];
        int freq[256] = {0};

        cout<<"Enter string: ";
        cin.ignore();
        cin.getline(str, 100);

        for(int i=0; str[i] != '\0'; i++)
            freq[str[i]]++;

        for(int i=0; i<256; i++)
        {
            if(freq[i] > 0)
                cout<<(char)i<<" = "<<freq[i]<<endl;
        }
    }

    void removeDuplicate()
    {
        char str[100];
        int seen[256] = {0};

        cout<<"Enter string: ";
        cin.ignore();
        cin.getline(str, 100);

        cout<<"Result: ";
        for(int i=0; str[i] != '\0'; i++)
        {
            if(seen[str[i]] == 0 && str[i] != ' ')
            {
                cout<<str[i];
                seen[str[i]] = 1;
            }
        }
    }
};

int main()
{
    Program p;
    int ch;

    do
    {
        cout<<"\n1 Reverse Array";
        cout<<"\n2 Check Sorted";
        cout<<"\n3 Move Zeros";
        cout<<"\n4 Character Frequency";
        cout<<"\n5 Remove Duplicate";
        cout<<"\n0 Exit";

        cout<<"\nEnter choice: ";
        cin>>ch;

        if(ch == 1)
            p.reverseArray();

        else if(ch == 2)
            p.checkSorted();

        else if(ch == 3)
            p.moveZeros();

        else if(ch == 4)
            p.charFrequency();

        else if(ch == 5)
            p.removeDuplicate();

    } while(ch != 0);

    return 0;
}
