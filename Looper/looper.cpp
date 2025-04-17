#include <iostream>
using namespace std;

int main()
{
    // Q - 1  Alphabet Skipper
    char start = 'a', end = 'z';

    do
    {
        cout << start <<" ";
        start = start + 4;
    } while (start <= end);


    // Q - 2  Digit Counter
    int num, count = 0;
    cout << endl << "Enter a number : ";
    cin >> num;

    while (num > 0)
    {
        count ++;
        num = num /10;
    }
    
    cout << "Total number of digits : "<< count;


    // Q - 3  Sum of a number's first and last digits.
    int num = 167;
    int last = num%10 ;
    int first = 0 ;
    
    while(num>0)
    {
        first = num;
        num = num/10;
    }

    cout<< endl << "The sum of first and last degit : " << last + first;
    
}