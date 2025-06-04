#include <iostream>
using namespace std;

class Stack
{
    public:
        int *arr;
        int capacity;
        int top;
        int counter;

    Stack(int n)
    {
        this->arr = new int[n];
        this->capacity = n;
        this->top = -1;
        this->counter = 0;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void push()
    {
        if(top == capacity-1)
        {
            cout << "Stack Overflow" <<endl;
        }
        else
        {
            this->top++;

            int elem;
            cout << "Enter new element : ";
            cin >> elem;

            arr[top] = elem;
            
            this->counter++;

            cout << "Push operation successfull" << endl;
        }
    }
    void pop()
    {
        if (this->top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            this->top--;
            this->counter--;
            cout << "Pop operation successfull" << endl;
        }
        
    }
    void peek()
    {
        if (this->top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "top element is :" << arr[top] << endl;
        }
        
    }
    void IsEmpty()
    {
        if (this->top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            cout << "stack is not empty" << endl;
        }
        
    }
    void IsFull()
    {
        if (this->top == capacity-1)
        {
            cout << "stack is full" << endl;
        }
        else
        {
            cout << "stack is not full" << endl;
        }
        
    }
    void display()
    {
        for(int i=top; i >= 0; i--)
        {
            cout << arr[i] << endl;
        }
    }
};

int main()
{
    int choice;
    Stack s1(5);

    do
    {
        cout << "Press 1 for push an element" << endl;
        cout << "Press 2 for pop an element" << endl;
        cout << "Press 3 for peek an element" << endl;
        cout << "Press 4 for isEmpty" << endl;
        cout << "Press 5 for isFull" << endl;
        cout << "Press 6 for display" << endl;
        cout << "Press 0 for exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            s1.push();
            break;
        case 2:
            s1.pop();
            break;
        case 3:
            s1.peek();
            break;
        case 4:
            s1.IsEmpty();
            break;
        case 5:
            s1.IsFull();
            break;
        case 6:
            s1.display();
            break;
        case 0:
            break;       
        default:
            cout << "Invalid choice" << endl;
            break;
        }
    } while (choice != 0);
    


    return 0;
}