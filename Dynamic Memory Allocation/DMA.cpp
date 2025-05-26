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
        next = NULL;
    }
};

class DMA
{
public:
    Node *HEAD;
    int count;

    DMA()
    {
        HEAD = NULL;
        count = 0;
    }

    void insertAtBeginning(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = HEAD;
        HEAD = newNode;
        count++;
    }

    void append(int data)
    {
        Node *newNode = new Node(data);
        if (HEAD == NULL)
        {
            HEAD = newNode;
        }
        else
        {
            Node *ptr = HEAD;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
        count++;
    }

    void search(int data)
    {
        Node *ptr = HEAD;
        int position = 0;
        bool found = false;

        while (ptr != NULL)
        {
            if (ptr->data == data)
            {
                cout << "Element " << data << " at position " << position << endl;
                found = true;
            }
            ptr = ptr->next;
            position++;
        }
    }

    void deleteByValue(int data)
    {
        if (HEAD->data == data)
        {
            Node *temp = HEAD;
            HEAD = HEAD->next;
            delete temp;
            count--;
            cout << "Element " << data << " deleted successfully." << endl;
            return;
        }

        Node *current = HEAD->next;
        Node *prev_ptr = HEAD;

        while (current != NULL)
        {
            if (current->data == data)
            {
                prev_ptr->next = current->next;
                delete current;
                count--;
                cout << "Element " << data << " deleted successfully." << endl;
                return;
            }
            prev_ptr = current;
            current = current->next;
        }

        cout << "Element " << data << " not found in the list." << endl;
    }

    void reverse()
    {
        Node *prev_ptr = NULL;
        Node *current = HEAD;
        Node *next_ptr = NULL;

        while (current != NULL)
        {
            next_ptr = current->next;
            current->next = prev_ptr;
            prev_ptr = current;
            current = next_ptr;
        }

        HEAD = prev_ptr;
    }

    void display()
    {
        Node *ptr = HEAD;
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
    DMA list;
    int choice, elem;

    do
    {
        cout << "Press 1 for insert at beginning" << endl;
        cout << "Press 2 for append" << endl;
        cout << "Press 3 for delete" << endl;
        cout << "Press 4 for reverse" << endl;
        cout << "Press 5 for display" << endl;
        cout << "Press 6 for Search element" << endl;
        cout << "Press 0 exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> elem;
            list.insertAtBeginning(elem);
            cout << "Inserted at beginning." << endl;
            break;

        case 2:
            cout << "Enter the value to append: ";
            cin >> elem;
            list.append(elem);
            cout << "Appended at end." << endl;
            break;

        case 3:
            cout << "Enter the value to delete: ";
            cin >> elem;
            list.deleteByValue(elem);
            break;

        case 4:
            list.reverse();
            cout << "reversed successfully." << endl;
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Enter the value to search: ";
            cin >> elem;
            list.search(elem);
            break;

        case 0:
            cout << "Exit" << endl;
            break;

        default:
            cout << "Invalid choice" << endl;
        }

    } while (choice != 0);

    return 0;
}
