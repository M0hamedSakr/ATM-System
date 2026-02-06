🏧 C++ ATM System (Console Application)
A simple ATM simulator built using C++ that allows users to log in and perform basic banking operations such as:
✅ Quick Withdraw
✅ Normal Withdraw
✅ Deposit
✅ Check Balance
✅ Logout / Exit
✅ Data saved permanently using a text file (File Handling)
📌 Features
🔐 Authentication
Users can log in using:
Account Number
PIN Code
💰 Transactions
Quick Withdraw (preset amounts)
Normal Withdraw (must be multiple of 5)
Deposit (positive amounts only)
Check Balance
💾 Persistent Storage
All client data is stored in a text file:
Clyents_Data.txt
Format:
نسخ التعليمات البرمجية

AccountNumber||PinCode||FirstName||LastName||Balance
Example:
نسخ التعليمات البرمجية

1001||1234||Mohamed||Sakr||5000
🛠️ Technologies Used
C++
File Handling (fstream)
Windows Console
iomanip for formatting
windows.h for Sleep()
▶️ How to Run
Open the project in Visual Studio (Recommended)
Make sure the file path is correct:
نسخ التعليمات البرمجية
Cpp
D:\\my_programe\\C++lang\\Bank\\Clyents_Data.txt
Run the program.
Enter valid Account Number and PIN Code from the file.
📂 Project Structure
نسخ التعليمات البرمجية

ATM-System/
│── main.cpp
│── Clyents_Data.txt
⚠️ Notes
This is a console-based project made for learning purposes.
The program uses Windows-only functions (Sleep, system("cls")).
✨ Future Improvements
Add Admin Mode
Add Register New Client option
Encrypt PIN Code
Improve file security and validation
👨‍💻 Author
Mohamed Sakr
Computer Engineering Student | AI & Problem-Solving