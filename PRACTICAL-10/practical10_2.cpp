/*A library uses a system with 10 shelves numbered 0 to 9. Each book's code is used to decide which shelf it belongs to by taking
the code modulo 10. Unlike the parking lot, each shelf can hold multiple books stacked together — when two books map to the same
shelf, they are simply added to that shelf's stack. Given a sequence of book codes, place each on the correct shelf and display
the final contents of all shelves.*/

#include <iostream>
using namespace std;

const int SHELVES = 10;

struct BookNode {
    int code;
    BookNode* next;
};

class Library {
private:
    BookNode* shelf[SHELVES];   // each shelf is the head of a linked list (chain)

public:
    Library() {
        for (int i = 0; i < SHELVES; i++) shelf[i] = nullptr;
    }

    ~Library() {
        for (int i = 0; i < SHELVES; i++) {
            BookNode* cur = shelf[i];
            while (cur != nullptr) {
                BookNode* next = cur->next;
                delete cur;
                cur = next;
            }
        }
    }

    void addBook(int code) {
        int index = code % SHELVES;                     // hash function
        shelf[index] = new BookNode{code, shelf[index]}; // collision is fine: push on the chain
        cout << "Book " << code << " placed on shelf " << index << endl;
    }

    bool search(int code) const {
        int steps = 0;
        for (BookNode* cur = shelf[code % SHELVES]; cur != nullptr; cur = cur->next) {
            steps++;
            if (cur->code == code) {
                cout << "Book " << code << " found on shelf " << code % SHELVES << " after " << steps << " comparison(s)." << endl;
                return true;
            }
        }
        cout << "Book " << code << " not found (" << steps << " comparison(s))." << endl;
        return false;
    }

    void display() const {
        for (int i = 0; i < SHELVES; i++) {
            cout << "Shelf " << i << ": ";
            if (shelf[i] == nullptr) cout << "empty";
            for (BookNode* cur = shelf[i]; cur != nullptr; cur = cur->next) {
                cout << cur->code;
                if (cur->next != nullptr) cout << " -> ";
            }
            cout << endl;
        }
    }
};

int main() {
    Library lib;
    int choice, code;

    do {
        cout << "\n--- Library Shelves Menu (Chaining) ---\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Display Shelves\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter book code: ";
                cin >> code;
                lib.addBook(code);
                break;
            case 2:
                cout << "Enter book code to search: ";
                cin >> code;
                lib.search(code);
                break;
            case 3:
                lib.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
