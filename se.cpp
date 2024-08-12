#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Structure to represent user data
struct User {
    string username;
    string password;
};

// Function prototypes
void registerUser(unordered_map<string, User>& users);
bool loginUser(const unordered_map<string, User>& users, const string& username, const string& password);

int main() {
    unordered_map<string, User> users; // Map to store users

    while (true) {
        int choice;
        cout << "Choose an option:" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                registerUser(users);
                break;
            }
            case 2: {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;

                if (loginUser(users, username, password)) {
                    cout << "Login successful!" << endl;
                } else {
                    cout << "Login failed. Incorrect username or password." << endl;
                }
                break;
            }
            case 3: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
            }
        }
    }

    return 0;
}

// Function to register a new user
void registerUser(unordered_map<string, User>& users) {
    User newUser;
    cout << "Enter new username: ";
    cin >> newUser.username;
    cout << "Enter new password: ";
    cin >> newUser.password;

    // Check if username already exists
    if (users.find(newUser.username) != users.end()) {
        cout << "Username already exists. Please choose another username." << endl;
    } else {
        users[newUser.username] = newUser;
        cout << "Registration successful!" << endl;
    }
}

// Function to authenticate user login
bool loginUser(const unordered_map<string, User>& users, const string& username, const string& password) {
    // Check if username exists
    auto it = users.find(username);
    if (it != users.end()) {
        // Check if password matches
        if (it->second.password == password) {
            return true;
        }
    }
    return false;
}
