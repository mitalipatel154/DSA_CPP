#include <iostream>
using namespace std;

void addition(float , float);
void subtraction(float , float);
void multiplication(float , float);
void division(float , float);
void remainder(int, int);

int main()
{

    int choice;
    float num1, num2;
    do
    {
        cout << "Press 1 for +" << endl;
        cout << "Press 2 for -" << endl;
        cout << "Press 3 for *" << endl;
        cout << "Press 4 for /" << endl;
        cout << "Press 5 for %" << endl;
        cout << "Press 0 for Exit" << endl;

        cout << "Enter your choice : ";
        cin >> choice; 

       
        if (choice >= 1 && choice <= 5)
        {
            cout << "Enter num1 : ";
            cin >> num1;
            cout << "Enter num2 : ";
            cin >> num2;
        }
        

        switch (choice)
        {
        case 1:
            addition(num1, num2);
            break;
        case 2:
            subtraction(num1, num2);
            break;
        case 3:
            multiplication(num1, num2);
            break;
        case 4:
            if (num2 == 0)
            {
                cout << "num can not divide by Zero" << endl;
                break;
            }
        
            division(num1, num2);
            break;
        case 5:
            if (num2 == 0)
            {
                cout << "num can not divide by Zero" << endl;
                break;
            }

            remainder(num1, num2);
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

void addition(float num1, float num2)
{
    cout << "Addition of " << num1 << " + " << num2 << " = " << num1 + num2 << endl;
}

void subtraction(float num1, float num2)
{
    cout << "Subtraction of " << num1 << " - " << num2 << " = " << num1 - num2 << endl;
}

void multiplication(float num1, float num2)
{
    cout << "Multiplication of " << num1 << " * " << num2 << " = " << num1 * num2 << endl;
}

void division(float num1, float num2)
{
    cout << "Division of " << num1 << " / " << num2 << " = " << num1 / num2 << endl;
}

void remainder(int num1, int num2)
{
    cout << "Remainder of " << num1 << " % " << num2 << " = " << num1 % num2 << endl;
}