#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

enum options { Quick_Withdraww = 1, Normal_Withdraww, Depositt, Check_Balancee, logoutt, Exitt };

void login();
void FillCly(vector<string> dataCl, string accountNumber, string pincode);

fstream ClientData;

void NewLine(char x, int y) {
    for (int i = 0; i < y; i++) {
        cout << x;
    }
    cout << endl;
}

void welcome() {
    cout << setw(50) << "Welcome to ATM System\n" << endl;
}

vector<string> splitline(string line) {
    vector<string> dataCl;
    int pos = 0;
    while ((pos = line.find("||")) != string::npos) {
        dataCl.push_back(line.substr(0, pos));
        line.erase(0, pos + 2);
    }
    dataCl.push_back(line);
    return dataCl;
}


bool checkValidation(string accountNumber, string pincode, vector<string>& dataCl) {
    string line;

    ClientData.open("D:\\my_programe\\C++lang\\Bank\\Clyents_Data.txt", ios::in);

    if (!ClientData.is_open()) {
        cout << "Error: Cannot open clients file!\n";
        system("pause>0");
        return false;
    }

    while (getline(ClientData, line)) {
        dataCl = splitline(line);

        if (dataCl.size() >= 5 && dataCl[0] == accountNumber && dataCl[1] == pincode) {
            ClientData.close();
            cout << "\nLogin Successfully...." << endl;
            Sleep(1000);
            return true;
        }
    }

    ClientData.close();

    system("cls");
    NewLine('-', 50);
    cout << "               Login Screen \n";
    NewLine('-', 50);
    cout << "Invalid Account Number or PIN Code" << endl;
    return false;
}

void Menu_Screen() {
    system("cls");
    NewLine('=', 50);
    cout << "              ATM Main Menue Screen \n";
    NewLine('=', 50);
    cout << "1. Quick Withdraw." << endl;
    cout << "2. Normal Withdraw." << endl;
    cout << "3. Deposit." << endl;
    cout << "4. Check Balance" << endl;
    cout << "5. Logout." << endl;
    cout << "6. Exit." << endl;
    NewLine('=', 50);
    cout << "Choose what do you want to do? 1,...6 ? ";
}

void Check_Balance(vector<string> dataCl) {
    NewLine('-', 50);
    cout << "              Check Balance Screen \n";
    NewLine('-', 50);
    cout << "Your Balance is: $" << dataCl[4] << endl;
    cout << "\nPress any key to go back to Main Menue...\n";
    system("pause>0");
}

void Quick_Withdrawscreen() {
    NewLine('-', 50);
    cout << "              Quick Withdraw Screen \n";
    NewLine('-', 50);

    cout << left;
    cout << setw(20) << "1. $20" << setw(20) << "2. $50" << "\n";
    cout << setw(20) << "3. $100" << setw(20) << "4. $200" << "\n";
    cout << setw(20) << "5. $400" << setw(20) << "6. $600" << "\n";
    cout << setw(20) << "7. $800" << setw(20) << "8. $1000" << "\n";
    cout << setw(20) << "9. Exit" << "\n";

    NewLine('-', 50);
}

void Quick_Withdraw(vector<string>& dataCl) {
    string input;
    int choice;
    int amount = 0; 
    int bal = stoi(dataCl[4]);

    Quick_Withdrawscreen();

    cout << "Your Balance is : " << dataCl[4];
    cout << "\nChoose the amount you want to withdraw? 1,...9 ? ";
    cin >> input;

    try {
        choice = stoi(input);
    }
    catch (...) {
        cout << "Invalid input! Please enter a number.\nEnter any key to continue.\n";
        system("pause>0");
        return;
    }

    switch (choice) {
    case 1: amount = 20; break;
    case 2: amount = 50; break;
    case 3: amount = 100; break;
    case 4: amount = 200; break;
    case 5: amount = 400; break;
    case 6: amount = 600; break;
    case 7: amount = 800; break;
    case 8: amount = 1000; break;
    case 9: return;
    default:
        cout << "Invalid choice! Please choose a number between 1 and 9.\nEnter any key to continue.\n";
        system("pause>0");
        return;
    }

    if (amount <= bal) {
        char c;
        cout << "Are you sure you want perfrom this transaction? Y/N? ";
        cin >> c;

        if (toupper(c) == 'Y') {
            dataCl[4] = to_string(bal - amount);
            FillCly(dataCl, dataCl[0], dataCl[1]);
            cout << "Done Successfully. New balance is: " << dataCl[4] << endl;
            cout << "Press any key to go back to Main Menue...\n";
            system("pause>0");
        }
        else {
            cout << "Transaction cancelled.\n";
            cout << "Press any key to go back to Main Menue...\n";
            system("pause>0");
        }
    }
    else {
        cout << "The amount exceeds your balance, make another choice.\n";
        cout << "Press any key to go back to Main Menue...\n";
        system("pause>0");
    }
}

void Normal_Withdraw(vector<string>& dataCl) {
    string amunt;
    int amount = 0, bal;

    NewLine('-', 50);
    cout << "              Normal Withdraw Screen \n";
    NewLine('-', 50);

    cout << "Your Balance is: " << dataCl[4] << endl;

    while (true) {
        cout << "Enter an amount multiple of 5's ? ";
        cin >> amunt;

        try {
            amount = stoi(amunt);
        }
        catch (...) {
            cout << "Invalid input! Please enter a number.\nEnter any key to continue.\n";
            system("pause>0");
            continue; 
        }

        if (amount <= 0) {
            cout << "Amount must be positive.\n";
            system("pause>0");
            continue;
        }

        if (amount % 5 != 0) {
            cout << "Amount must be multiple of 5.\n";
            system("pause>0");
            continue;
        }

        break;
    }

    bal = stoi(dataCl[4]);

    if (amount <= bal) {
        char c;
        cout << "Are you sure you want perfrom this transaction? Y/N? ";
        cin >> c;

        if (toupper(c) == 'Y') {
            bal -= amount;
            dataCl[4] = to_string(bal);
            FillCly(dataCl, dataCl[0], dataCl[1]);
            cout << "Done Successfully. New balance is: " << dataCl[4] << endl;
            cout << "Press any key to go back to Main Menue...\n";
            system("pause>0");
        }
        else {
            cout << "Transaction cancelled.\n";
            cout << "Press any key to go back to Main Menue...\n";
            system("pause>0");
        }
    }
    else {
        cout << "The amount exceeds your balance, make another choice.\n";
        cout << "Press any key to go back to Main Menue...\n";
        system("pause>0");
    }
}

void Deposit(vector<string>& dataCl) {
    NewLine('-', 50);
    cout << "              Deposit Screen Screen \n";
    NewLine('-', 50);

    string input;
    int amount = 0;

    cout << "Enter a positive Deposit Amount? ";
    cin >> input;

    try {
        amount = stoi(input);
    }
    catch (...) {
        cout << "Invalid input! Please enter a number.\n";
        system("pause>0");
        return;
    }

    if (amount > 0) {
        dataCl[4] = to_string(stoi(dataCl[4]) + amount);
        FillCly(dataCl, dataCl[0], dataCl[1]);
        cout << "Done Successfully. New balance is: " << dataCl[4] << endl;
        cout << "Press any key to go back to Main Menue...\n";
        system("pause>0");
    }
    else {
        cout << "Invalid amount! Please enter a positive number.\n";
        cout << "Press any key to go back to Main Menue...\n";
        system("pause>0");
    }
}

void Next_Screen(vector<string>& dataCl) {
    int choice;
    string input;

    while (true) {
        system("cls");
        Menu_Screen();
        cin >> input;

        try {
            choice = stoi(input);
        }
        catch (...) {
            cout << "Invalid input! Please enter a number.\nEnter any key to continue.\n";
            system("pause>0");
            continue;
        }

        options option = static_cast<options>(choice);

        system("cls");

        switch (option) {
        case options::Quick_Withdraww:
            Quick_Withdraw(dataCl);
            break;

        case options::Normal_Withdraww:
            Normal_Withdraw(dataCl);
            break;

        case options::Depositt:
            Deposit(dataCl);
            break;

        case options::Check_Balancee:
            Check_Balance(dataCl);
            break;

        case options::logoutt:
            cout << "Logging out....";
            Sleep(1000);
            login();
            return;

        case options::Exitt:
            cout << "Exiting....";
            Sleep(1000);
            system("cls");
            cout << "\n\n\n\n\n\n                    Thank You  =============== S A K R  =============== \n\n\n\n\n\n\n\n\n";
            exit(0);

        default:
            cout << "Invalid choice! Please choose a number between 1 and 6.\nEnter any key to continue.\n";
            system("pause>0");
            break;
        }
    }
}


void FillCly(vector<string> dataCl, string accountNumber, string pincode) {
    string line;
    vector<string> Clients;
    vector<string> CHk;

    ClientData.open("D:\\my_programe\\C++lang\\Bank\\Clyents_Data.txt", ios::in);

    if (!ClientData.is_open()) {
        cout << "Error: Cannot open clients file!\n";
        system("pause>0");
        return;
    }

    while (getline(ClientData, line)) {
        CHk = splitline(line);

        if (CHk.size() >= 5 && CHk[0] == accountNumber && CHk[1] == pincode) {
            line = dataCl[0] + "||" + dataCl[1] + "||" + dataCl[2] + "||" + dataCl[3] + "||" + dataCl[4];
        }

        Clients.push_back(line);
    }

    ClientData.close();

    // overwrite file (NOT append)
    ClientData.open("D:\\my_programe\\C++lang\\Bank\\Clyents_Data.txt", ios::out);

    if (ClientData.is_open()) {
        for (string& l : Clients) {
            ClientData << l << endl;
        }
        ClientData.close();
    }
}

void login() {
    system("cls");

    string accountNumber, pincode;
    vector<string> dataCl;

    NewLine('-', 50);
    cout << "              Login Screen \n";
    NewLine('-', 50);

    do {
        cout << "Enter Account Number? ";
        getline(cin >> ws, accountNumber);

        cout << "Enter PIN Code? ";
        getline(cin >> ws, pincode);

    } while (!checkValidation(accountNumber, pincode, dataCl));

    Next_Screen(dataCl);
}

int main() {
    welcome();
    login();
}