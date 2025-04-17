#include <iostream>
using namespace std;

int main()
{
    int i, j, k, l;

    // Q - 1
    for ( i = 41; i <= 45; i++)
    {
        for ( j = 41; j <= i; j++)
        {
            cout << j;
        }  
        cout << endl;
    }
    
    // Q - 2
    int n = 11;
    for ( i = 1; i <= 4; i++)
    {
        for ( j = 1; j <= i; j++)
        {
            cout << n;
            n++;
        }  
        cout << endl;
    }

    // Q - 3
    for ( i = 5; i >= 1; i--)
    {
        for ( k = 1; k < i; k++)
        {
            cout << " ";
        }  
        for ( j = 5; j >= i; j--)
        {
            cout << j;
        }  
        cout << endl;
    }


    // Q - 4
    for ( i = 5; i >= 1; i--)
    {
        for ( k = 5; k > i; k--)
        {
            cout << " ";
        }  
        for ( j = 1; j <= i; j++)
        {
            if (j % 2 == 0)
            {
                cout << "0";
            }
            else{
                cout << "1";
            }
        }  
        cout << endl;
    }

    // Q - 5
    for ( i = 5; i >= 1; i--)
    {
        for ( k = 1; k < i; k++)
        {
            cout << " ";
        }  
        for ( j = i; j <= 5; j++)
        {
            cout << j;
        }  
        for ( l = 4; l >= i; l--)
        {
            cout << l;
        }  
        cout << endl;
    }
    
    // Q - 6
    for ( i = 1; i <= 5; i++)
    {
        for ( j = 1; j <= i; j++)
        {
            cout << j;
        }  
        for ( k = 5; k > i; k--)
        {
            cout << "  ";
        }  
        for ( l = 1; l <= i; l++)
        {
            cout << l;
        }  
        cout << endl;
    }

    // Q - 7
    for ( i = 1; i <= 5; i++)
    {
        if (i == 1 || i == 3)
        {
            cout << "* * * * *";
        }else if (i == 2)
        {
            cout << "*\t*";
        }else{
            cout << "*";
        }   
        cout << endl;
    }

    return 0;
}