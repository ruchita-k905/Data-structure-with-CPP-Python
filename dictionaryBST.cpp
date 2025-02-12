#include<iostream>
using namespace std;

class node
{ 
    public:
        node *leftc;
        string word;
        string meaning;
        node *rightc;
};

class BST
{
    private:
        node *temp;
        int op;
    public:
        node *root;
      
        BST()
        {
            root = NULL;
        }

        void create();
        void insert(node*, node*);
        void inorder(node*);
        void converse_inorder(node*);
        void search(node*, string);
        void modify(node*, string);
        node* min_value_node(node*);
        int max_comparisons(node*, int);
};

int main()
{
    BST B;
    int choice;
    string value;
    while(1)
    {
        cout << "\n----------------------------MENU----------------------------------" << endl;
        cout << "1. Create and Insert a new node in the binary search tree" << endl;
        cout << "2. Display Ascending (Inorder) tree" << endl;
        cout << "3. Display Descending (Converse Inorder) tree" << endl;
        cout << "4. Search for a value in the tree" << endl;
        cout << "5. Modify the meaning of node" << endl;
        cout << "6. Find maximum comparisons required for searching a keyword" << endl;
        cout << "7. Exit" << endl;
        cout << "----------------------------------------------------------------------\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;
    
        switch(choice)
        {
            case 1:
                B.create();
                break;
            case 2:
                B.inorder(B.root);
                break;
            case 3:
                B.converse_inorder(B.root);
                break;
            case 4:
                cout << "Enter the value to search: ";
                cin >> value;
                B.search(B.root, value);
                break;
            case 5:
                cout << "Enter the value to modify: ";
                cin >> value;
                B.modify(B.root, value);
                break;
            case 6:
                cout << "Maximum comparisons required for finding any keyword: " << B.max_comparisons(B.root, 0) << endl;
                break;
            case 7:
                cout << "Exiting....!" << endl;
                exit(0);
                break;
        }
    }
    return 0;
}

void BST::create()
{
    string word, meaning;
    do
    {
        temp = new node;
        cout << "Enter the word: ";
        cin >> word;
        cout << "Enter the meaning: ";
        cin >> meaning;
        
        temp->word = word;
        temp->meaning = meaning;
        temp->leftc = temp->rightc = NULL;

        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp);
        }

        cout << "Enter 1 to insert another node, 0 to stop: ";
        cin >> op;
    } while (op == 1);
}

void BST::insert(node *root, node *temp)
{
    if (temp->word < root->word)
    {
        if (root->leftc == NULL)
            root->leftc = temp;
        else
            insert(root->leftc, temp);
    }
    else
    {
        if (root->rightc == NULL)
            root->rightc = temp;
        else
            insert(root->rightc, temp);
    }
}

void BST::inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->leftc);
        cout << "\nWord: " << root->word << "\tMeaning: " << root->meaning;
        inorder(root->rightc);
    }
}

void BST::converse_inorder(node *root)
{
    if (root != NULL)
    {    
        converse_inorder(root->rightc);
        cout << "\nWord: " << root->word << "\tMeaning: " << root->meaning;
        converse_inorder(root->leftc);
    }
}

void BST::search(node *root, string value)
{
    if (root == NULL)
    {
        cout << "Value " << value << " not found in the tree." << endl;
        return;
    }
    if (root->word == value)
    {
        cout << "Value " << value << " found in the tree." << endl;
        return;
    }
    else if (value < root->word)
    {
        search(root->leftc, value);
    }
    else
    {
        search(root->rightc, value);
    }
}

void BST::modify(node *root, string value)
{
    if (root == NULL)
    {
        cout << "Value " << value << " not found in the tree." << endl;
        return;
    }
    if (root->word == value)
    {
        cout << "Enter new meaning: ";
        cin >> root->meaning;
        cout << "Meaning Updated!" << endl;
        return;
    }
    else if (value < root->word)
    {
        modify(root->leftc, value);
    }
    else
    {
        modify(root->rightc, value);
    }
}

int BST::max_comparisons(node *root, int depth)
{
    if (root == NULL)
        return depth;
    return max(max_comparisons(root->leftc, depth + 1), max_comparisons(root->rightc, depth + 1));
}
