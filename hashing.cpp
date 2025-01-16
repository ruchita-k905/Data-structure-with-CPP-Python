#include <iostream>
#include <string>
#define size 10
using namespace std;

class hashtable {
    string a1[size]; // Linear probing
    string a2[size]; // Quadratic probing

public:
    hashtable() {
        for (int i = 0; i < size; i++) {
            a1[i] = "-1"; // Initialize with a placeholder
            a2[i] = "-1";
        }
    }

    void display() {
        cout << "Displaying Hash Table:" << endl;
        cout << "Table 1 (Linear Probing):" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": " << (a1[i] == "-1" ? "Empty" : a1[i]) << endl;
        }
        cout << "\nTable 2 (Quadratic Probing):" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": " << (a2[i] == "-1" ? "Empty" : a2[i]) << endl;
        }
    }

    void insertL(int record, const string& phone) {
        int k = record % size;  // Hash function
        if (a1[k] == "-1") {
            a1[k] = phone;
            cout << "Inserted in Table 1 using Linear Probing." << endl;
        } else {
            while (a1[k] != "-1") {
                k = (k + 1) % size;  // Linear Probing
            }
            a1[k] = phone;
            cout << "Inserted in Table 1 using Linear Probing." << endl;
        }
    }

    void insertQ(int record, const string& phone) {
        int k = record % size;  // Hash function
        if (a2[k] == "-1") {
            a2[k] = phone;
            cout << "Inserted in Table 2 using Quadratic Probing." << endl;
        } else {
            int i = 1;
            while (a2[k] != "-1") {
                k = (k + (i * i)) % size;  // Quadratic Probing
                i++;
            }
            a2[k] = phone;
            cout << "Inserted in Table 2 using Quadratic Probing." << endl;
        }
    }

    bool searchL(int record) {
        int k = record % size;
        int start = k; // Prevent infinite loop
        while (a1[k] != "-1") {
            if (k == record % size) {
                cout << "Record " << record << " found at index " << k << " with phone number: " << a1[k] << " (Linear Probing)." << endl;
                return true;
            }
            k = (k + 1) % size;  // Linear Probing
            if (k == start) break; // Loop back to start
        }
        cout << "Record " << record << " not found using Linear Probing." << endl;
        return false;
    }

    bool searchQ(int record) {
        int k = record % size;
        int i = 1;
        int start = k; // Prevent infinite loop
        while (a2[k] != "-1") {
            if (k == record % size) {
                cout << "Record " << record << " found at index " << k << " with phone number: " << a2[k] << " (Quadratic Probing)." << endl;
                return true;
            }
            k = (k + (i * i)) % size;  // Quadratic Probing
            i++;
            if (k == start) break;  // Loop back to start
        }
        cout << "Record " << record << " not found using Quadratic Probing." << endl;
        return false;
    }
};

int main() {
    hashtable h1;
    char ch = 'y';
    int n;

    do {
        cout << "1. Insert using Linear Probing\n2. Insert using Quadratic Probing\n";
        cout << "3. Search using Linear Probing\n4. Search using Quadratic Probing\n";
        cout << "5. Display\nEnter your Choice: ";
        cin >> n;

        switch (n) {
        case 1: {
            int record;
            string phone;
            cout << "Enter Record Number: ";
            cin >> record;
            cout << "Enter Phone Number: ";
            cin >> phone;
            h1.insertL(record, phone);
            break;
        }
        case 2: {
            int record;
            string phone;
            cout << "Enter Record Number: ";
            cin >> record;
            cout << "Enter Phone Number: ";
            cin >> phone;
            h1.insertQ(record, phone);
            break;
        }
        case 3: {
            int record;
            cout << "Enter Record Number to search: ";
            cin >> record;
            h1.searchL(record);
            break;
        }
        case 4: {
            int record;
            cout << "Enter Record Number to search: ";
            cin >> record;
            h1.searchQ(record);
            break;
        }
        case 5:
            h1.display();
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        cout << "\nDo you want to continue? [Y/N]: ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return 0;
}