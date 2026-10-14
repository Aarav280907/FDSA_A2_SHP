/*A university assigns student IDs to storage slots using a two-step rule. The first rule determines the initial slot. If that slot
is taken, instead of simply moving one slot forward, a second rule based on the ID itself determines how many slots to jump. This
means different IDs that collide will probe different sequences of slots, spreading them more evenly. Given a sequence of student
IDs, assign each to a slot using both rules and display the final state of the table.*/

#include <iostream>
#include <vector>
using namespace std;

class StudentTable {
private:
    int size;
    int occupied;
    vector<int> table;   // -1 means empty

    int hash1(int id) const { return id % size; }              // first rule: initial slot
    int hash2(int id) const { return 7 - (id % 7); }           // second rule: jump size, always 1..7 (never 0)

public:
    StudentTable(int s) : size(s), occupied(0), table(s, -1) {}

    void insert(int id) {
        if (occupied == size) {
            cout << "Table is full. Cannot store " << id << "." << endl;
            return;
        }

        int start = hash1(id);
        int jump = hash2(id);
        cout << "ID " << id << ": h1 = " << start << ", jump (h2) = " << jump << endl;

        // try at most 'size' positions: start, start+jump, start+2*jump, ... (mod size)
        for (int i = 0; i < size; i++) {
            int slot = (start + i * jump) % size;
            if (table[slot] == -1) {
                table[slot] = id;
                occupied++;
                cout << "  stored at slot " << slot << " after " << i << " collision(s)" << endl;
                return;
            }
            cout << "  slot " << slot << " taken" << endl;
        }
        // happens when jump shares a factor with the table size (non-prime size)
        cout << "  could not find a free slot for " << id << " (probe sequence cycled)." << endl;
    }

    void display() const {
        cout << "Slot : Student ID" << endl;
        for (int i = 0; i < size; i++) {
            cout << "  " << i << (i < 10 ? " " : "") << " : ";
            if (table[i] == -1) cout << "empty";
            else cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter table size (a prime such as 11 works best): ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid table size." << endl;
        return 0;
    }

    StudentTable t(size);
    int choice, id;

    do {
        cout << "\n--- Student Table Menu (Double Hashing) ---\n";
        cout << "1. Insert Student ID\n";
        cout << "2. Display Table\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter student ID: ";
                cin >> id;
                t.insert(id);
                break;
            case 2:
                t.display();
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
