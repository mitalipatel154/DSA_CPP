#include <iostream>
#include <vector>
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


class List
{
public:
    int size;
    int *arr;


    Node *HEAD;
    Node *top;
    int count;


    List(int size)
    {
        this->size = size;
        this->arr = new int[this->size];
        this->HEAD = NULL;
        this->top = NULL;
        this->count = 0;


        cout << "Enter array element : " << endl;
        for (int i = 0; i < this->size; i++)
        {
            cout << "arr[" << i << "] : ";
            cin >> this->arr[i];
        }
    }
    ~List()
    {
        delete[] arr;
    }
    void array_sum();
    void array_average();
    void array_largest();
    void array_reverse();
    void printArray();
    void vectors();


    void stack_push();
    void stack_pop();
    void display_stack();


    void insertAtEnding();
    void displayLinkedList();
};


int main()
{
    int size;
    cout << "Enter array size : ";
    cin >> size;


    List l(size);
    int choice;


    do
    {
        cout << endl << "Press 1 for Array sum" << endl;
        cout << "Press 2 for Array average" << endl;
        cout << "Press 3 for Array largest" << endl;
        cout << "Press 4 for Array reverse" << endl;
        cout << "Press 5 for Vector" << endl;
        cout << "Press 6 for Stack push" << endl;
        cout << "Press 7 for Stack pop" << endl;
        cout << "Press 8 for Display stack" << endl;
        cout << "Press 9 for Insert At Ending" << endl;
        cout << "Press 10 for Display Linked List" << endl;
        cout << "Press 0 for exit" << endl;


        cout << endl << "Enter your choice: ";
        cin >> choice;


        switch (choice)
        {
        case 1:
            l.array_sum();
            break;
        case 2:
            l.array_average();
            break;
        case 3:
            l.array_largest();
            break;
        case 4:
            l.array_reverse();
            l.printArray();
            break;
        case 5:
            l.vectors();
            break;
        case 6:
            l.stack_push();
            break;
        case 7:
            l.stack_pop();
            break;
        case 8:
            l.display_stack();
            break;
        case 9:
            l.insertAtEnding();
            break;
        case 10:
            l.displayLinkedList();
            break;
        case 0:
            break;


        default:
            cout << "Invalid choice...";
            break;
        }


    } while (choice != 0);


    return 0;
}


void List::array_sum()
{
    int sum = 0;
    for (int i = 0; i < this->size; i++)
    {
        sum += this->arr[i];
    }
    cout << "Sum of array elements: " << sum << endl;
}
void List::array_average()
{
    int sum = 0;
    for (int i = 0; i < this->size; i++)
    {
        sum += this->arr[i];
    }
    float avg = (float)sum / this->size;
    cout << "Average of array elements: " << avg << endl;
}
void List::array_largest()
{
    int max = this->arr[0];


    for (int i = 1; i < this->size; i++)
    {
        if (this->arr[i] > max)
        {
            max = this->arr[i];
        }
    }
    cout << "Maximum value : " << max << endl;
}
void List::array_reverse()
{
    int left = 0;
    int right = this->size - 1;
    while (left < right)
    {
        int temp = this->arr[left];
        this->arr[left] = this->arr[right];
        this->arr[right] = temp;
        left++;
        right--;
    }
}
void List::printArray()
{
    cout << "Current Array: ";
    for (int i = 0; i < this->size; i++)
    {
        cout << this->arr[i] << " ";
    }
    cout << endl;
}
void List::vectors()
{
    vector<int> vec;
    int num;
    cout << "Enter integers (enter -1 to stop): " << endl;
    while (true)
    {
        cin >> num;
        if (num == -1)
            break;
        vec.push_back(num);
    }


    vector<int> uniqueVec;
    for (int i = 0; i < vec.size(); i++)
    {
        bool found = false;
        for (int j = 0; j < uniqueVec.size(); j++)
        {
            if (vec[i] == uniqueVec[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            uniqueVec.push_back(vec[i]);
        }
    }


    cout << "Vector without duplicates: ";
    for (int i = 0; i < uniqueVec.size(); i++)
    {
        cout << uniqueVec[i] << " ";
    }
    cout << endl;
}
void List::stack_push()
{
    int val;
    cout << "Enter value to push in stack: ";
    cin >> val;


    Node *newNode = new Node(val);
    newNode->next = top;
    top = newNode;


    cout << "Push operation successfull" << endl;
}
void List::stack_pop()
{
    if (top == NULL)
    {
        cout << "Stack Underflow!" << endl;
        return;
    }


    Node *temp = top;
    top = top->next;
    delete temp;
    cout << "Pop successful." << endl;
}
void List::display_stack()
{
    if (top == NULL)
    {
        cout << "Stack is empty." << endl;
        return;
    }


    cout << "Stack elements: ";
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void List::insertAtEnding()
{
    int elem;
    cout << "Enter element to insert at end of Linked List: ";
    cin >> elem;
    Node *newNode = new Node(elem);
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
void List::displayLinkedList()
{
    if (HEAD == NULL)
    {
        cout << "Linked List is empty." << endl;
        return;
    }


    cout << "Linked List: ";
    Node *ptr = HEAD;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
   
}



