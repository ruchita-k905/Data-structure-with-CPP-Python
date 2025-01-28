#include <iostream>
#include <algorithm> // For std::max
using namespace std;

class node {
public:
    node *leftc, *rightc;
    int data;
};

class bt {
    node *temp;
    char op;
    char ch;

public:
    node *root;

    bt() {
        root = NULL;
    }

    void create();
    void insert(node *, node *);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    int search(node *, int);
    node *deleteNode(node *, int);
    node *findMin(node *);
    int height(node *);
};

void bt::create() {
    do {
        temp = new node;
        cout << "Enter value: ";
        cin >> temp->data;
        temp->leftc = temp->rightc = NULL;

        if (root == NULL) {
            root = temp;
        } else {
            insert(root, temp);
        }

        cout << "Do you want to insert another node? [Y/N]: ";
        cin >> op;

    } while (op == 'y' || op == 'Y');
}

void bt::insert(node *root, node *temp) {
    cout << "Where to insert node " << temp->data << "? [L/R] of " << root->data << ": ";
    cin >> ch;
    if (ch == 'L' || ch == 'l') {
        if (root->leftc == NULL) {
            root->leftc = temp;
        } else {
            insert(root->leftc, temp);
        }
    } else {
        if (root->rightc == NULL) {
            root->rightc = temp;
        } else {
            insert(root->rightc, temp);
        }
    }
}

void bt::preorder(node *root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preorder(root->leftc);
        preorder(root->rightc);
    }
}

void bt::inorder(node *root) {
    if (root != nullptr) {
        inorder(root->leftc);
        cout << root->data << " ";
        inorder(root->rightc);
    }
}

void bt::postorder(node *root) {
    if (root != nullptr) {
        postorder(root->leftc);
        postorder(root->rightc);
        cout << root->data << " ";
    }
}

int bt::search(node *root, int key) {
    if (root == nullptr) {
        return 0; // Key not found
    }
    if (root->data == key) {
        return 1; // Key found
    }
    // Check in the left and right subtrees
    return search(root->leftc, key) || search(root->rightc, key);
}


// Find the node with the minimum value (used for deletion when the node has two children)
node *bt::findMin(node *root) {
    while (root && root->leftc != nullptr) {
        root = root->leftc;
    }
    return root;
}

// Delete a node from the binary tree
node *bt::deleteNode(node *root, int key) {
    if (root == nullptr) {
        return root;
    }

    // Traverse the tree to find the node to delete
    if (key < root->data) {
        root->leftc = deleteNode(root->leftc, key);
    } else if (key > root->data) {
        root->rightc = deleteNode(root->rightc, key);
    } else {
        // Node found
        // Case 1: Node with no children
        if (root->leftc == nullptr && root->rightc == nullptr) {
            delete root;
            return nullptr;
        }
        // Case 2: Node with one child
        else if (root->leftc == nullptr) {
            node *temp = root->rightc;
            delete root;
            return temp;
        } else if (root->rightc == nullptr) {
            node *temp = root->leftc;
            delete root;
            return temp;
        }
        // Case 3: Node with two children
        else {
            node *temp = findMin(root->rightc); // Find minimum value in the right subtree
            root->data = temp->data;           // Replace current node's value with the minimum value
            root->rightc = deleteNode(root->rightc, temp->data); // Delete the duplicate node
        }
    }
    return root;
}

// Function to calculate the height of the binary tree
int bt::height(node *root) {
    if (root == nullptr) {
        return -1; // Return -1 for empty tree; alternatively, use 0 if you consider height of empty tree as 0
    }
    int leftHeight = height(root->leftc);
    int rightHeight = height(root->rightc);
    return max(leftHeight, rightHeight) + 1; // Height is max of left and right subtree heights, plus 1 for root
}

int main() {
    bt b;
    int choice;
    char c;

    do {
        cout << "\nMenu:\n";
        cout << "1. Create BT\n";
        cout << "2. Insert new node in BT\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Postorder Traversal\n";
        cout << "6. Search for a node\n";
        cout << "7. Delete a node\n";
        cout << "8. Calculate height of the tree\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            b.create();
            break;
        case 2:
            b.create();
            break;
        case 3:
            b.preorder(b.root);
            cout << endl;
            break;
        case 4:
            b.inorder(b.root);
            cout << endl;
            break;
        case 5:
            b.postorder(b.root);
            cout << endl;
            break;
        case 6: {
            int key,flag;
            cout << "Enter Key to Search: ";
            cin >> key;
            flag = b.search(b.root, key);
            if(flag==1)
            {
                cout<<"Key "<<key<<" found in the BT"<<endl;
            }
            else
            {
                cout<<"Key "<<key<<" NOT found in the BT"<<endl;
            }
            break;
        }
        case 7: {
            int key;
            cout << "Enter Key to Delete: ";
            cin >> key;
            b.root = b.deleteNode(b.root, key);
            cout << "Node deleted successfully (if it existed).\n";
            break;
        }
        case 8: {
            int treeHeight = b.height(b.root);
            cout << "Height of the tree: " << treeHeight << endl;
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
