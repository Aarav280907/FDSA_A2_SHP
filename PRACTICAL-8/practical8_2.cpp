/*A school library uses a system where every book is assigned a unique code when it arrives. Books are organized so that at any
shelf position, all books to the left have smaller codes and all books to the right have larger codes. Given a sequence of book
codes arriving one by one, insert each into the correct position and print the inorder sequence after all insertions are complete.*/

#include <iostream>
using namespace std;

struct BookNode {
    int code;
    BookNode* left;
    BookNode* right;
    BookNode(int c) : code(c), left(nullptr), right(nullptr) {}
};

// Insert a code: smaller goes left, larger goes right. Duplicates are rejected.
BookNode* insertBook(BookNode* root, int code, bool& inserted) {
    if (root == nullptr) {          // empty spot found -> new link created here
        inserted = true;
        return new BookNode(code);
    }
    if (code < root->code)
        root->left = insertBook(root->left, code, inserted);
    else if (code > root->code)
        root->right = insertBook(root->right, code, inserted);
    else
        inserted = false;           // same code already on the shelf
    return root;
}

void inorder(BookNode* node) {
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->code << " ";
    inorder(node->right);
}

// Inorder of a correct BST must be strictly increasing; this checks it.
bool isSorted(BookNode* node, long long& previous) {
    if (node == nullptr) return true;
    if (!isSorted(node->left, previous)) return false;
    if (node->code <= previous) return false;
    previous = node->code;
    return isSorted(node->right, previous);
}

void freeTree(BookNode* node) {
    if (node == nullptr) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main() {
    BookNode* root = nullptr;
    int choice, code;

    do {
        cout << "\n--- Library BST Menu ---\n";
        cout << "1. Insert Book Code\n";
        cout << "2. Display Inorder Sequence\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter book code: ";
                cin >> code;
                bool inserted = false;
                root = insertBook(root, code, inserted);
                if (inserted)
                    cout << "Book " << code << " inserted." << endl;
                else
                    cout << "Book " << code << " already exists. Ignored." << endl;
                break;
            }
            case 2: {
                if (root == nullptr) {
                    cout << "Shelf is empty." << endl;
                    break;
                }
                cout << "Inorder: ";
                inorder(root);
                long long previous = -1000000000000LL;
                cout << "\nSorted check: " << (isSorted(root, previous) ? "PASS" : "FAIL") << endl;
                break;
            }
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    freeTree(root);
    return 0;
}
