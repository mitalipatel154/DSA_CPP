#include <iostream>
#include <string>
using namespace std;

class BankAccount {
public:
    int accountNumber;
    string accountHolderName;

private:
    double balance;

public:
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited successfully." << endl;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful." << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    void setBalance() {
        cout << "Enter account balance: ";
        cin >> balance;
    }

    double getBalance() {
        return balance;
    }

    void displayAccountInfo() {
        cout << "Account No: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
    }

    virtual void calculateInterest() {
        cout << "Base account has no interest." << endl;
    }
};

class SavingAccount : public BankAccount {
public:
    int interestRate = 3;

    void calculateInterest() override {
        double interest = getBalance() * interestRate / 100.0;
        cout << "Interest on saving account: " << interest << endl;
    }
};

class CheckingAccount : public BankAccount {
public:
    int overdraftLimit = 1000;

    void checkOverdraft() {
        cout << "Overdraft limit is: " << overdraftLimit << endl;
    }
};

class FixedDepositAccount : public BankAccount {
public:
    int term = 2;

    void calculateInterest() override {
        double interest = getBalance() * 0.05 * term;
        cout << "Interest on fixed deposit: " << interest << endl;
    }
};

int main() {
    SavingAccount s[100];
    CheckingAccount c[100];
    FixedDepositAccount f[100];
    int sCount = 0, cCount = 0, fCount = 0;

    int choice, accType;

    do {
        cout << "Press 1 for creating an Account" << endl;
        cout << "Press 2 for checking balace" << endl;
        cout << "Press 3 for withdraw" << endl;
        cout << "Press 4 for deposite" << endl;
        cout << "Press 5 for checking interest rate" << endl;
        cout << "Press 6 for displaying your account" << endl;
        cout << "Press 7 for setting overdraft limit" << endl;
        cout << "Press 8 for grtting overdraft limit" << endl;
        cout << "Press 0 for exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        int accNo;

        switch (choice) {
        case 1:

            cout << "Press 1 for SavingAccount" << endl;
            cout << "Press 2 for CheckingAccout" << endl;
            cout << "Press 3 for FixedDepositeAccount" << endl;

            cout << "Enter your bank account type: ";
            cin >> accType;

            switch (accType)
            {
            case 1:
                cout << "Enter account number: ";
                cin >> s[sCount].accountNumber;
                cout << "Enter account holder name: ";
                cin >> s[sCount].accountHolderName;
                s[sCount].setBalance();
                sCount++;
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> c[cCount].accountNumber;
                cout << "Enter account holder name: ";
                cin >> c[cCount].accountHolderName;
                c[cCount].setBalance();
                cCount++;
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> f[fCount].accountNumber;
                cout << "Enter account holder name: ";
                cin >> f[fCount].accountHolderName;
                f[fCount].setBalance();
                fCount++;
                break;

            default:
                cout << "Invalid account type" << endl;
                break;
            }
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> accNo;
            for (int i = 0; i < sCount; i++)
                if (s[i].accountNumber == accNo)
                    cout << "Balance: " << s[i].getBalance() << endl;
            for (int i = 0; i < cCount; i++)
                if (c[i].accountNumber == accNo)
                    cout << "Balance: " << c[i].getBalance() << endl;
            for (int i = 0; i < fCount; i++)
                if (f[i].accountNumber == accNo)
                    cout << "Balance: " << f[i].getBalance() << endl;
            break;

        case 3:
            cout << "Enter account number to withdraw: ";
            cin >> accNo;
            double wAmt;
            cout << "Enter amount: ";
            cin >> wAmt;
            for (int i = 0; i < sCount; i++)
                if (s[i].accountNumber == accNo)
                    s[i].withdraw(wAmt);
            for (int i = 0; i < cCount; i++)
                if (c[i].accountNumber == accNo)
                    c[i].withdraw(wAmt);
            for (int i = 0; i < fCount; i++)
                if (f[i].accountNumber == accNo)
                    f[i].withdraw(wAmt);
            break;

        case 4:
            cout << "Enter account number to deposit: ";
            cin >> accNo;
            double dAmt;
            cout << "Enter amount: ";
            cin >> dAmt;
            for (int i = 0; i < sCount; i++)
                if (s[i].accountNumber == accNo)
                    s[i].deposit(dAmt);
            for (int i = 0; i < cCount; i++)
                if (c[i].accountNumber == accNo)
                    c[i].deposit(dAmt);
            for (int i = 0; i < fCount; i++)
                if (f[i].accountNumber == accNo)
                    f[i].deposit(dAmt);
            break;

        case 5:
            cout << "Enter account number to calculate interest: ";
            cin >> accNo;
            for (int i = 0; i < sCount; i++)
                if (s[i].accountNumber == accNo)
                    s[i].calculateInterest();
            for (int i = 0; i < fCount; i++)
                if (f[i].accountNumber == accNo)
                    f[i].calculateInterest();
            break;

        case 6:
            cout << "Enter account number to display: ";
            cin >> accNo;
            for (int i = 0; i < sCount; i++)
                if (s[i].accountNumber == accNo)
                    s[i].displayAccountInfo();
            for (int i = 0; i < cCount; i++)
                if (c[i].accountNumber == accNo)
                    c[i].displayAccountInfo();
            for (int i = 0; i < fCount; i++)
                if (f[i].accountNumber == accNo)
                    f[i].displayAccountInfo();
            break;

        case 7:
            cout << "Overdraft limit is set in CheckingAccount class. You can customize this in code." << endl;
            break;

        case 8:
            cout << "Enter Checking account number to see overdraft limit: ";
            cin >> accNo;
            for (int i = 0; i < cCount; i++)
                if (c[i].accountNumber == accNo)
                    c[i].checkOverdraft();
            break;

        case 0:
            cout << "Exit..." << endl;
            break;

        default:
            cout << "Invalid choice..." << endl;
        }

    } while (choice != 0);

    return 0;
}