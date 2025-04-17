#include<iostream>
using namespace std;

int main()
{
    int score ;
    char grade ;

    cout << "Enter your score : ";
    cin >> score;



    (score >= 0 && score <= 100)
    ? (score <= 100 && score>=90) 
        ? grade = 'A', cout << "Your grade is A" <<endl
        : (score < 90 && score >= 80) 
            ? grade = 'B',cout << "Your grade is B" <<endl
            : (score < 80 && score >= 70)
                ?grade = 'C',cout << "Your grade is C" <<endl
                : (score < 70 && score >= 60)
                    ?grade = 'D',cout << "Your grade is D" <<endl
                    : (score < 60 && score >= 50)
                        ? grade = 'E',cout << "Your grade is E" <<endl
                        : (score < 50 && score >= 0)
                            ? grade = 'F',cout << "Your grade is F" <<endl
                            : cout<<""
    : cout << "You have entered invalid scroe" <<endl;

    switch (grade)
    {
    case 'A':
        cout << "Excellent Work!" <<endl;
        break;
    case 'B':
        cout << "Well done!" <<endl;
        break;
    case 'C':
        cout << "Good Job!" <<endl;
        break;
    case 'D':
        cout << "You have passed but you could do better" <<endl;
        break;
    case 'E':
        cout << "Just passed the exam" <<endl;
        break;
    case 'F':
        cout << "Sorry you failed" <<endl;
        break;
    default:
        break;
    }

    if(grade >= 'A' && grade <= 'E')
    {
        cout << "Congratulations!";
    }else{
        cout << "Please try again next time";
    }
}