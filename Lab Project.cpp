#include <iostream>
using namespace std;

void showMenu() {
    cout << "**********MENU**********" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
    cout << "************************" << endl;
}

bool validatePIN(int enteredPIN, int correctPIN) {
    return enteredPIN == correctPIN;
}

int main() {
    system("color 17");
    
    const int correctPIN = 1234;
    int enteredPIN;
    int pinAttempts = 0;
    const int maxAttempts = 3;

    while (pinAttempts < maxAttempts) {
        cout << "Enter your PIN: ";
        cin >> enteredPIN;

        if (validatePIN(enteredPIN, correctPIN)) {
            cout << "PIN accepted. Access granted." << endl;
            break;
        } else {
            pinAttempts++;
            cout << "Incorrect PIN. Try again." << endl;
        }

        if (pinAttempts == maxAttempts) {
            cout << "Maximum attempts reached. Exiting..." << endl;
            return 0;
        }
    }

    int option;
    double balance = 5000;

    do {
        showMenu();
        cout << "Option: ";
        cin >> option;
        system("cls");

        switch (option) {
            case 1:
                cout << "Balance is: " << balance << " PKR" << endl;
                break;
            case 2:
                cout << "Deposit amount: ";
                double depositAmount;
                cin >> depositAmount;
                balance += depositAmount;
                cout << "Deposited " << depositAmount << " PKR. New balance: " << balance << " PKR" << endl;
                break;
            case 3:
                cout << "Withdraw amount: ";
                double withdrawAmount;
                cin >> withdrawAmount;
                if (withdrawAmount <= balance) {
                    balance -= withdrawAmount;
                    cout << "Withdrawn " << withdrawAmount << " PKR. New balance: " << balance << " PKR" << endl;
                } else {
                    cout << "Not enough money, Sorry!" << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    } while (option != 4);

    return 0;
}


