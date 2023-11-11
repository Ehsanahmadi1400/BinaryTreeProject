Binary Tree Sorting Program
This C++ program implements a binary tree to sort a group of names provided by the user. The program utilizes a binary search tree structure to organize the names and then performs an in-order traversal to display the sorted list.

Author
Ehsan Ahmadi
Date: 11.11.2023
Program Overview
The program consists of a BinaryTree class and a main function. The BinaryTree class includes a struct definition for nodes in the binary tree and methods for insertion and in-order traversal.

How to Use
Compile the program using a C++ compiler.

bash
Copy code
g++ main.cpp -o main 
Run the executable.

bash
Copy code
./binary_tree_sort

* Enter the number of names you want to input, and then enter the names.
* The program will display the sorted list of names using an in-order traversal of the binary tree.

Press Enter to close the program.

Program Structure
- struct node
Represents a node in the binary tree.
Contains a string to store the name.
Includes pointers to the left and right children.
Constructor initializes the node with a given name and sets left and right pointers to nullptr.

- class BinaryTree
Manages the binary tree structure.
Private member: Pointer to the root node.

- Public methods:
Constructor: Initializes the binary tree with an empty root.
insert: Inserts a new node with the given name into the binary tree.
insertRecursive: Recursive helper function for node insertion.
display: Initiates in-order traversal of the binary tree.
inOrderTraversal: Recursive function for in-order traversal.

- main Function
Creates an instance of the BinaryTree class.
Accepts user input for the number of names and the names themselves.
Utilizes exception handling to handle potential input errors.
Displays the sorted list of names using the binary tree's in-order traversal.

- Error Handling
The program incorporates error handling using try and catch blocks to handle invalid inputs, such as non-integer values or integers outside the valid range. Users are prompted to press Enter to close the program in case of an error.