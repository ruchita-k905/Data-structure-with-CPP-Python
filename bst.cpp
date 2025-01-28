#include <iostream>
#include <algorithm> // For std::max
using namespace std;

class node {
public:
    node *leftc, *rightc;
    int data;
};

class bst {
public:
    node *root;

    bst() {
        root = NULL;
    }

    void insert(node *&, int);
    void inorder(node *);
    int height(node *);
    int countNodesInLongestPath(node *);
    int findMinValue(node *);
    void mirrorTree(node *);
    int search(node *, int);
};

void bst::insert(node *&root, int value) {
    if (root == nullptr) {
        root = new node;
        root->data = value;
        root->leftc = root->rightc = nullptr;
    } else if (value < root->data) {
        insert(root->leftc, value);
    } else {
        insert(root->rightc, value);
    }
}

void bst::inorder(node *root) {
    if (root != nullptr) {
        inorder(root->leftc);
        cout << root->data << " ";
        inorder(root->rightc);
    }
}

int bst::height(node *root) {
    if (root == nullptr) {
        return -1; // Return -1 for empty tree; alternatively, use 0 if considering empty tree height as 0
    }
    int leftHeight = height(root->leftc);
    int rightHeight = height(root->rightc);
    return max(leftHeight, rightHeight) + 1; // Height is max of left and right subtree heights, plus 1 for root
}

int bst::countNodesInLongestPath(node *root) {
    return height(root) + 1; // Number of nodes in longest path = height + 1
}

int bst::findMinValue(node *root) {
    while (root && root->leftc != nullptr) {
        root = root->leftc;
    }
    return root->data;
}

void bst::mirrorTree(node *root) {
    if (root == nullptr) {
        return;
    }
    // Swap left and right pointers
    swap(root->leftc, root->rightc);

    // Recursively mirror left and right subtrees
    mirrorTree(root->leftc);
    mirrorTree(root->rightc);
}

int bst::search(node *root, int key) {
    if (root == nullptr) {
        return 0; // Key not found
    }
    if (root->data == key) {
        return 1; // Key found
    }
    // Search in the left or right subtree based on key value
    return (key < root->data) ? search(root->leftc, key) : search(root->rightc, key);
}

int main() {
    bst b;
    int choice;
    char c;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert values to construct BST\n";
        cout << "2. Insert a new node into BST\n";
        cout << "3. Inorder Traversal\n";
        cout << "4. Find number of nodes in longest path from root\n";
        cout << "5. Find minimum value in the BST\n";
        cout << "6. Mirror the BST\n";
        cout << "7. Search for a value in the BST\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int n, value;
            cout << "Enter number of values to insert: ";
            cin >> n;
            cout << "Enter values: ";
            for (int i = 0; i < n; i++) {
                cin >> value;
                b.insert(b.root, value);
            }
            cout << "BST constructed.\n";
            break;
        }
        case 2: {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            b.insert(b.root, value);
            cout << "Node inserted.\n";
            break;
        }
        case 3:
            cout << "Inorder Traversal: ";
            b.inorder(b.root);
            cout << endl;
            break;
        case 4: {
            int nodes = b.countNodesInLongestPath(b.root);
            cout << "Number of nodes in the longest path from root: " << nodes << endl;
            break;
        }
        case 5: {
            int minValue = b.findMinValue(b.root);
            cout << "Minimum value in the BST: " << minValue << endl;
            break;
        }
        case 6:
            b.mirrorTree(b.root);
            cout << "BST mirrored.\n";
            break;
        case 7: {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            if (b.search(b.root, key)) {
                cout << "Value " << key << " found in the BST.\n";
            } else {
                cout << "Value " << key << " not found in the BST.\n";
            }
            break;
        }
        default:
            cout << "Invalid choice!\n";
            break;
        }

        cout << "Do you want to continue with main menu? [Y/N]: ";
        cin >> c;

    } while (c == 'Y' || c == 'y');

    return 0;
}
