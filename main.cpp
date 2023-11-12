/*
*** This program receives a group of names
*** and sorts them using binary tree
*** Author: Ehsan Ahmadi 11.11.2023
*/

#include <iostream>
#include <string>

using namespace std;

// Definition of a Node in a Binary Tree
struct node {
    // Data stored in the node (in this case, a string representing a name)
    string name;

    // Pointers to the left and right children nodes
    struct node* left;
    struct node* right;

    // Constructor to initialize a node with a given name, and left and right to nullptr
    node(const string& name) : name(name), left(nullptr), right(nullptr) {}
};

// BinaryTree Class Definition
class BinaryTree {
    private:
        // Pointer to the root node of the binary tree
        node* root;

    public:
        // Default Constructor: 
        // Initializes the BinaryTree with an empty tree (root set to nullptr)
        BinaryTree() : root(nullptr) {}

        // Insert a new node with the given name into the binary tree
        void insert(const string& name) {
            // Call the recursive insert function starting from the root
            root = insertRecursive(root, name);
        }
        
        // Recursive function to insert a new node with the given name into the binary tree
        node* insertRecursive(node* current, const string& name) {
            // Base Case: If the current node is nullptr, create a new node with the given name
            if (current == nullptr) {
                return new node(name);
            }

            // Recursive Case: Insert into the left or right subtree based on name comparison
            if (name < current->name) {
                current->left = insertRecursive(current->left, name);
            }
            else if (name > current->name) {
                current->right = insertRecursive(current->right, name);
            }
    
            // Return the current node after insertion
            return current;
        }

        // Display the binary tree using in-order traversal
        void display() {
            inOrderTraversal(root);
        }

        // Recursive function for in-order traversal of the binary tree
        void inOrderTraversal(node* current) {
        // Base Case: If the current node is not nullptr
        if (current != nullptr) {
            // Traverse the left subtree
            inOrderTraversal(current->left);
            
            // Process the current node (print its name)
            cout << current->name << "  ";

            // Traverse the right subtree
            inOrderTraversal(current->right);
        }
    }
};

int main() {

    BinaryTree tree;
    string name;
    string user_input;

    // Determining the qty of the names as the user wishes
    cout << "How many names do you want to enter/ give an integer: " << endl;
    cin >> user_input;

    // Using try, catch to avoid a certain amount of user mistakes
    try {
        // Attempt to convert the string to an integer
        int qty = std::stoi(user_input);
        
        // If successful, get the names
        cout << "You want to add " << qty << " names " << endl;
        cout << "Now enter the names ... " << endl;
        cout << "After writing each name hit Enter button " << endl;
        
        for(int i = 0; i < qty + 1; ++i) {
            getline(cin, name);
            tree.insert(name);
        } 
    }
    catch (const invalid_argument& e) {
        // Conversion failed (input is not an integer)
        std::cerr << "Invalid input, push a key to close the program." << std::endl;
        system("pause");
        return 0;
    }
    catch (const std::out_of_range& e) {
        // Conversion failed (input is out of the valid range for int)
        std::cerr << "Input is out of range for an integer, push a key to close the program" << std::endl;
        system("pause");
        return 0;
    }

    cout << "This is the sorted List of inputs: " << endl;

    // Display the list, while it is sorted
    tree.display();

    cout << "\nPress Enter to close the program." << endl;
    cin.get();

}
