#include <iostream>
using namespace std;

int main()
{
    // Negative element
    int size, i;

    cout << "Enter the array's size : ";
    cin >> size;

    int a[size];
    cout << "Enter array's element : " << endl;
    for ( i = 0; i < size; i++ )
    {
        cout << "a["<<i<<"] : ";
        cin >> a[i];
    }
    
    cout << "Negative element from an array : ";
    for ( i = 0; i < size; i++)
    {
        if (a[i] < 0)
        {
            cout << a[i] << " ";
        }
    }
     


    // max value.
    int row_size, col_size , i, j;
    cout << "Enter row size : ";
    cin >> row_size;

    cout << "Enter col size : ";
    cin >> col_size;
    
    int a[row_size][col_size];

    cout << "Enter array's element : " << endl;
    for ( i = 0; i < row_size; i++)
    {
       for ( j = 0; j < col_size; j++)
       {
            cout << "a["<< i <<"]["<< j <<"] : ";
            cin >> a[i][j];
       }
       
    }
    
    int max = a[0][0];
    for (i = 0; i < row_size; i++)
    {
        for ( j = 0; j < col_size; j++)
        {
            if (a[i][j] > max)
            {
                max = a[i][j];
            }
        }
    }
    cout << "Max value is : " << max;
    


    // transposed matrix
    int row_size, col_size;
    cout << "Enter row size : ";
    cin >> row_size;

    cout << "Enter col size : ";
    cin >> col_size;

    int a[row_size][col_size];
    int i, j;

    cout << "Enter array's element : " << endl;
    for ( i = 0; i < row_size; i++)
    {
        for ( j = 0; j < col_size; j++)
        {
            cout << "a["<< i <<"]["<< j <<"] : ";
            cin >> a[i][j];
        }
        
    }
    cout << "Matrix of an array : " << endl; 
    for ( i = 0; i < row_size; i++)
    {
        for ( j = 0; j < col_size; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << "transpose matrix of an array : " << endl;
    for ( j = 0; j < col_size; j++)
    {
        for ( i = 0; i < row_size; i++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    


    // sum of elements in row & column
    int row_size, col_size, col_sum = 0, row_sum = 0, row_num, col_num;
    cout << "Enter row size : ";
    cin >> row_size;

    cout << "Enter col size : ";
    cin >> col_size;

    int a[row_size][col_size];
    int i, j;

    cout << "Enter array's element : " << endl;
    for ( i = 0; i < row_size; i++)
    {
        for ( j = 0; j < col_size; j++)
        {
            cout << "a["<< i <<"]["<< j <<"] : ";
            cin >> a[i][j];
        }
        
    }
    
    cout << "Enter row number : ";
    cin >> row_num;
    for ( i = 0; i < row_size; i++)
    {
        for ( j = 0; j < col_size; j++)
        {
            if (row_num == i)
            {
                row_sum += a[row_num][j];
            }
            
        }
    }
    cout << "sum of row :" << row_sum << endl;

    cout << "Enter column number : ";
    cin >> col_num;
    for ( i = 0; i < row_size; i++)
    {
        for ( j = 0; j < col_size; j++)
        {
            if (col_num == j)
            {
                col_sum += a[i][col_num];
            }
            
        }
    }
    cout << "sum of column :" << col_sum << endl;
}


