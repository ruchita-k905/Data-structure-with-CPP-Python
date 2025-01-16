#include <iostream>
#include <set>
using namespace std;

class SetADT {
private:
    set<int> elements;

public:
    // Add a new element to the set
    void add(int element) {
        elements.insert(element);
    }

    // Remove an element from the set
    void remove(int element) {
        if (elements.erase(element)) {
            cout << "Element " << element << " removed from the set.\n";
        } else {
            cout << "Element " << element << " not found in the set.\n";
        }
    }

    // Check if an element is in the set
    bool contains(int element) const {
        return elements.find(element) != elements.end();
    }

    // Get the size of the set
    int size() const {
        return elements.size();
    }

    // Display the elements of the set
    void iterator() const {
        cout << "Set elements: ";
        for (int element : elements) {
            cout << element << " ";
        }
        cout << endl;
    }

    // Intersection of two sets
    SetADT intersection(const SetADT& other) const {
        SetADT result;
        for (int element : elements) {
            if (other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // Union of two sets
    SetADT unionSet(const SetADT& other) const {
        SetADT result;
        result.elements = elements;
        for (int element : other.elements) {
            result.add(element);
        }
        return result;
    }

    // Difference between two sets
    SetADT difference(const SetADT& other) const {
        SetADT result;
        for (int element : elements) {
            if (!other.contains(element)) {
                result.add(element);
            }
        }
        return result;
    }

    // Check if the current set is a subset of another set
    bool isSubset(const SetADT& other) const {
        for (int element : elements) {
            if (!other.contains(element)) {
                return false;
            }
        }
        return true;
    }

    // Input all elements of the set
    void inputElements() {
        int n, element;
        cout << "Enter the number of elements: ";
        cin >> n;
        cout << "Enter the elements: ";
        for (int i = 0; i < n; ++i) {
            cin >> element;
            add(element);
        }
    }
};

int main() {
    SetADT set1, set2;

    cout << "Initialize Set 1:\n";
    set1.inputElements();

    cout << "\nInitialize Set 2:\n";
    set2.inputElements();

    int choice, element;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Element to Set 1\n";
        cout << "2. Add Element to Set 2\n";
        cout << "3. Remove Element from Set 1\n";
        cout << "4. Remove Element from Set 2\n";
        cout << "5. Display Size of Set 1\n";
        cout << "6. Display Size of Set 2\n";
        cout << "7. Display Elements of Set 1\n";
        cout << "8. Display Elements of Set 2\n";
        cout << "9. Intersection of Set 1 and Set 2\n";
        cout << "10. Union of Set 1 and Set 2\n";
        cout << "11. Difference (Set 1 - Set 2)\n";
        cout << "12. Check if Set 1 is a Subset of Set 2\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter element to add to Set 1: ";
            cin >> element;
            set1.add(element);
            break;

        case 2:
            cout << "Enter element to add to Set 2: ";
            cin >> element;
            set2.add(element);
            break;

        case 3:
            cout << "Enter element to remove from Set 1: ";
            cin >> element;
            set1.remove(element);
            break;

        case 4:
            cout << "Enter element to remove from Set 2: ";
            cin >> element;
            set2.remove(element);
            break;

        case 5:
            cout << "Size of Set 1: " << set1.size() << " elements.\n";
            break;

        case 6:
            cout << "Size of Set 2: " << set2.size() << " elements.\n";
            break;

        case 7:
            cout << "Elements in Set 1: ";
            set1.iterator();
            break;

        case 8:
            cout << "Elements in Set 2: ";
            set2.iterator();
            break;

        case 9: {
            SetADT inter = set1.intersection(set2);
            cout << "Intersection of Set 1 and Set 2: ";
            inter.iterator();
            break;
        }

        case 10: {
            SetADT uni = set1.unionSet(set2);
            cout << "Union of Set 1 and Set 2: ";
            uni.iterator();
            break;
        }

        case 11: {
            SetADT diff = set1.difference(set2);
            cout << "Difference (Set 1 - Set 2): ";
            diff.iterator();
            break;
        }

        case 12:
            if (set1.isSubset(set2)) {
                cout << "Set 1 is a subset of Set 2.\n";
            } else {
                cout << "Set 1 is NOT a subset of Set 2.\n";
            }
            break;

        case 13:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 15);

    return 0;
}
