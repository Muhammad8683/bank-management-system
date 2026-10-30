#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <limits>
using namespace std;

struct Account {
    int account_number;
    string account_name;
    float balance;
    long cnic_number;
    string address;
    string date_birth;
};

void write_to_file(Account accounts[], int num_accounts); // Forward declaration

void add_account(Account accounts[], int &num_accounts) {
    system("cls");
    cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Add Account \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    int num;
    cout << "\n\n\t\t\tHow many Accounts you want to add:";
    cin >> num;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t\tInvalid input! Please enter a number.\n";
        Sleep(2000);
        return;
    }
    ofstream outFile("store.txt", ios::app);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    for (int i = 0; i < num; i++) {
        cout << "\n\t\t\t**********************";
        cout << "\n\t\t\t|Enter account number: ";
        cin >> accounts[num_accounts].account_number;
        cout << "\t\t\t|Enter account name: ";
        cin.ignore();
        getline(cin, accounts[num_accounts].account_name);
        cout << "\t\t\t|Enter Your Date Of Birth (dd/mm/yyyy): ";
        getline(cin, accounts[num_accounts].date_birth);
        cout << "\t\t\t|Enter your CNIC Number: ";
        cin >> accounts[num_accounts].cnic_number;
        cout << "\t\t\t|Enter your Address: ";
        cin.ignore();
        getline(cin, accounts[num_accounts].address);
        cout << "\t\t\t|Enter account balance: ";
        cin >> accounts[num_accounts].balance;
        cout << "\t\t\t**********************";
        outFile << accounts[num_accounts].account_number << " "
                << accounts[num_accounts].account_name << " "
                << accounts[num_accounts].date_birth << " "
                << accounts[num_accounts].cnic_number << " "
                << accounts[num_accounts].address << " "
                << accounts[num_accounts].balance << endl;
        num_accounts++;
    }
    cout << "\n\t\tDetails Entered successfully\n\t\tpress any key to go to Main Menu.....";
    outFile.close();
    Sleep(2000);
    system("cls");
}

void update_account(Account accounts[], int num_accounts) {
    int account_number, i;
    system("cls");
    cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Update Account  \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\n\t\t\tEnter account number to update: ";
    cin >> account_number;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t\tInvalid input! Please enter a valid account number.\n";
        Sleep(2000);
        return;
    }
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            cout << "\t\t\tEnter new account name: ";
            cin.ignore();
            getline(cin, accounts[i].account_name);
            cout << "\t\t\tEnter Your Date Of Birth (dd/mm/yyyy): ";
            getline(cin, accounts[i].date_birth);
            cout << "\t\t\tEnter your CNIC Number: ";
            cin >> accounts[i].cnic_number;
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t\t\tInvalid input! Please enter a valid CNIC number.\n";
                Sleep(2000);
                return;
            }
            cout << "\t\t\tEnter your Address: ";
            cin.ignore();
            getline(cin, accounts[i].address);
            cout << "\t\t\tEnter new account balance: ";
            cin >> accounts[i].balance;
            if(cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t\t\tInvalid input! Please enter a valid balance.\n";
                Sleep(2000);
                return;
            }
            cout << "\t\t\tAccount updated successfully!\n";
            write_to_file(accounts, num_accounts);
            return;
        }
    }
    cout << "Account not found!\n";
    Sleep(2000);
    system("cls");
}

void delete_account(Account accounts[], int &num_accounts) {
    int account_number, i, j;
    system("cls");
    cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Delete Account  \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\n\t\t\tEnter account number to delete: ";
    cin >> account_number;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t\tInvalid input! Please enter a valid account number.\n";
        Sleep(2000);
        return;
    }
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            for (j = i; j < num_accounts - 1; j++) {
                accounts[j] = accounts[j + 1];
            }
            num_accounts--;
            cout << "\t\t\tAccount deleted successfully!\n";
            write_to_file(accounts, num_accounts);
            Sleep(2000);
            system("cls");
            return;
        }
    }
    cout << "Account not found!\n";
    Sleep(2000);
    system("cls");
}

void search_account(Account accounts[], int num_accounts) {
    int account_number, i;
    system("cls");
    cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Search Account  \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\n\t\t\tEnter account number to search: ";
    cin >> account_number;
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t\t\tInvalid input! Please enter a valid account number.\n";
        Sleep(2000);
        return;
    }
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            cout << "\t\t\tAccount Number: " << accounts[i].account_number << endl;
            cout << "\t\t\tAccount Name: " << accounts[i].account_name << endl;
            cout << "\t\t\tDate Of Birth: " << accounts[i].date_birth << endl;
            cout << "\t\t\tCNIC Number: " << accounts[i].cnic_number << endl;
            cout << "\t\t\tAddress: " << accounts[i].address << endl;
            cout << "\t\t\tAccount Balance: " << accounts[i].balance << endl;
            cout << "\t\t\tAccount found successfully!\n";
            cout << "\n\t\t\tPress any key to return to the main menu...";
            cin.ignore();
            cin.get();
            return;
        }
    }
    cout << "Account not found!\n";
    Sleep(2000);
    system("cls");
}

void list_accounts(Account accounts[], int num_accounts) {
    system("cls");
    cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 List Accounts  \xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
    for (int i = 0; i < num_accounts; i++) {
        cout << "\n\t\t\tAccount Number: " << accounts[i].account_number << endl;
        cout << "\t\t\tAccount Name: " << accounts[i].account_name << endl;
        cout << "\t\t\tDate Of Birth: " << accounts[i].date_birth << endl;
        cout << "\t\t\tCNIC Number: " << accounts[i].cnic_number << endl;
        cout << "\t\t\tAddress: " << accounts[i].address << endl;
        cout << "\t\t\tAccount Balance: " << accounts[i].balance << endl;
        cout << "\t\t\t--------------------------" << endl;
    }
    cout << "\n\t\t\tPress any key to return to the main menu...";
    cin.ignore();
    cin.get();
}

void load_from_file(Account accounts[], int &num_accounts) {
    ifstream inFile("store.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }
    num_accounts = 0;
    while (inFile >> accounts[num_accounts].account_number) {
        inFile.ignore();
        getline(inFile, accounts[num_accounts].account_name, ' ');
        getline(inFile, accounts[num_accounts].date_birth, ' ');
        inFile >> accounts[num_accounts].cnic_number;
        inFile.ignore();
        getline(inFile, accounts[num_accounts].address, ' ');
        inFile >> accounts[num_accounts].balance;
        num_accounts++;
    }
    inFile.close();
}

void write_to_file(Account accounts[], int num_accounts) {
    ofstream outFile("store.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    for (int i = 0; i < num_accounts; i++) {
        outFile << accounts[i].account_number << " "
                << accounts[i].account_name << " "
                << accounts[i].date_birth << " "
                << accounts[i].cnic_number << " "
                << accounts[i].address << " "
                << accounts[i].balance << endl;
    }
    outFile.close();
}

int main() {
    Account accounts[100];
    int num_accounts = 0;
    load_from_file(accounts, num_accounts);
    int choice;
    while (1) {
        system("cls");
        cout << "\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2 Bank Management System  \xB2\xB2\xB2";
        cout << "\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2";
        cout << "\n\n\n\t\t\t1. Add Account";
        cout << "\n\t\t\t2. Update Account";
        cout << "\n\t\t\t3. Delete Account";
        cout << "\n\t\t\t4. Search Account";
        cout << "\n\t\t\t5. List Accounts";
        cout << "\n\t\t\t6. Exit";
        cout << "\n\n\t\t\tEnter your choice: ";
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) {
            cin.clear(); // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore any remaining input
            cout << "\t\t\tInvalid input! Please enter a number between 1 and 6.\n";
            Sleep(2000);
            continue; // Skip the rest of the loop and prompt again
        }

        switch (choice) {
        case 1:
            add_account(accounts, num_accounts);
            break;
        case 2:
            update_account(accounts, num_accounts);
            break;
        case 3:
            delete_account(accounts, num_accounts);
            break;
        case 4:
            search_account(accounts, num_accounts);
            break;
        case 5:
            list_accounts(accounts, num_accounts);
            break;
        case 6:
            write_to_file(accounts, num_accounts);
            exit(0);
        default:
            cout << "\t\t\tInvalid choice! Please try again.\n";
            Sleep(2000);
        }
    }
    return 0;
}
