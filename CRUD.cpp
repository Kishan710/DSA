#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    int count;
    Node *head;

    LinkedList()
    {
        this->head = NULL;
        count = 0;
    }

    void addAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        this->head = newNode;
        this->count++;
    }
    void addAtEnding(int data)
    {
        Node *newNode = new Node(data);
        if (this->head == NULL)
        {
            this->head = newNode;
        }
        else
        {
            Node *ptr = this->head;

            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        this->count++;
    }
    void addAtPosition(int data, int position)
    {
        Node *newNode = new Node(data);
        if (position == 0)
        {
            newNode->next = this->head;
            this->head = newNode;
        }
        else
        {
            Node *ptr = head;
            for (int i = 0; i < position - 1; i++)
            {
                ptr = ptr->next;
            }
            newNode->next = ptr->next;
            ptr->next = newNode;
        }
        this->count++;
    }
    void update(int element, int position)
    {
        if (position < 0 || position > this->count)
        {
            cout << "Invalid position..." << endl;
            return;
        }
        else
        {
            Node *ptr = this->head;
            for (int i = 0; i < position; i++)
            {
                ptr = ptr->next;
            }
            ptr->data = element;
        }
    }
    void deleteFromBeginning()
    {
        if (this->head == NULL || this->count == 0)
        {
            cout << "List is alrady empty..." << endl;
            return;
        }
        Node *temp = this->head;
        this->head = this->head->next;
        delete temp;
        temp = NULL;
        this->count--;
    }

    void deleteFromEnding()
    {
        if (this->head == NULL || this->count == 0)
        {
            cout << "List is alrady empty..." << endl;
            return;
        }
        Node *ptr = this->head;
        while (ptr->next->next != NULL)
        {
            ptr = ptr->next;
        }
        delete ptr->next;
        ptr->next = NULL;
        ptr = NULL;
        this->count--;
    }

    void deleteAtPosition(int position)
    {
        if (this->head == NULL || this->count == 0)
        {
            cout << "List is alrady empty..." << endl;
            return;
        }
        Node *prev = this->head;
        Node *current = this->head;
        for (int i = 0; i < position; i++)
        {
            current = current->next;
        }
        for (int i = 0; i < position - 1; i++)
        {
            prev = prev->next;
        }
        prev->next = current->next;
        delete current;
        current = NULL;
        prev = NULL;
        delete prev;
        this->count--;
    }

    void size()
    {
         cout << "The Size of List " << count  << endl; 
    }

    void viewAllNodes()
    {
        Node *ptr = this->head;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    int choice, element, position;

    do
    {
        cout << "Press 1 for insert a node at the beginning of the list" << endl;
        cout << "Press 2 for insert a node at the ending of the list" << endl;
        cout << "Press 3 for insert a node at any position of the list" << endl;
        cout << "Press 4 for update a node at any position of the list" << endl;
        cout << "Press 5 for delete a node from the beginning of the list" << endl;
        cout << "Press 6 for delete a node from the ending of the list" << endl;
        cout << "Press 7 for delete a node at any postion of the list" << endl;
        cout << "Press 8 for get size of list" << endl;
        cout << "Press 9 for view all nodes" << endl;
        cout << "Press 0 for exit" << endl;

        cout << "Enter Your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value of Element :";
            cin >> element;
            list.addAtBeginning(element);
            cout << "Node inserted at begining of the list successfully..." << endl;
            break;
        case 2:
            cout << "Enter the value of Element :";
            cin >> element;
            list.addAtEnding(element);
            cout << "Node inserted at ending of the list successfully..." << endl;
            break;
        case 3:
            cout << "Enter the value of Element :";
            cin >> element;
            cout << "Enter the position :";
            cin >> position;
            list.addAtPosition(element, position);
            cout << "Node inserted successfully..." << endl;
            break;
        case 4:
            cout << "Enter the value of Element :";
            cin >> element;
            cout << "Enter the position :";
            cin >> position;
            list.update(element, position);
            cout << "Node updated successfully..." << endl;
            break;
        case 5:
            list.deleteFromBeginning();
            cout << "Node deleted successfully..." << endl;
            break;
        case 6:
            list.deleteFromEnding();
            cout << "Node deleted successfully..." << endl;
            break;
        case 7:
            cout << "Enter the position :";
            cin >> position;
            list.deleteAtPosition(position);
            cout << "Node deleted successfully..." << endl;
            break;
        case 8:
            list.size();
            break;
        case 9:
            list.viewAllNodes();
            break;
        case 0:
            break;
        default:
            cout << "Enter a Valid choice!..." << endl;
            break;
        }
    } while (choice != 0);
}
