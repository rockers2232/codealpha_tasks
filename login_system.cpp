#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>
#include <cstdlib>   


using namespace std;


void createUserDirectory() {
    struct stat info;

    if (stat("users", &info) != 0) {
        
#ifdef _WIN32
        system("mkdir users");
#else
        system("mkdir -p users");
#endif
    }
}

void registerUser() {
    string username, password;

    cout << "\n--- User Registration ---\n";
    cout << "Enter username: ";
    cin >> username;

    string filename = "users/" + username + ".txt";

    
    ifstream checkFile(filename.c_str());
    if (checkFile.good()) {
        cout << "Error: Username already exists.\n";
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream outFile(filename.c_str());
    outFile << username << endl;
    outFile << password << endl;
    outFile.close();

    cout << "User registered successfully.\n";
}

void loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "\n--- User Login ---\n";
    cout << "Enter username: ";
    cin >> username;

    string filename = "users/" + username + ".txt";

    ifstream inFile(filename.c_str());
    if (!inFile) {
        cout << "Error: Username not found.\n";
        return;
    }

    getline(inFile, storedUsername);
    getline(inFile, storedPassword);
    inFile.close();

    cout << "Enter password: ";
    cin >> password;

    if (password == storedPassword) {
        cout << "Login successful. Welcome, " << storedUsername << "!\n";
    } else {
        cout << "Incorrect password.\n";
    }
}

int main() {
    createUserDirectory();

    int choice;

    while (true) {
        cout << "\n=== Login & Registration System ===\n";
        cout << "1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: registerUser(); break;
            case 2: loginUser(); break;
            case 3: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
