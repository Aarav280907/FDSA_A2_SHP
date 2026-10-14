/*A small parking lot has exactly 10 numbered slots (0 to 9). When a vehicle arrives, its registration number is used to assign
it a slot by taking the last digit of the number. If that slot is already taken, the vehicle moves to the next available slot in
order, wrapping around if necessary. Given a sequence of vehicle registrations, assign each to a slot using this rule and display
the final state of all ten slots.*/

#include <iostream>
using namespace std;

const int SLOTS = 10;

class ParkingLot {
private:
    int table[SLOTS];     // -1 means the slot is free
    int occupied;

public:
    ParkingLot() : occupied(0) {
        for (int i = 0; i < SLOTS; i++) table[i] = -1;
    }

    void park(int reg) {
        if (occupied == SLOTS) {         // without this check the probe would loop forever
            cout << "Parking lot is full. Cannot park " << reg << "." << endl;
            return;
        }
        int slot = reg % SLOTS;          // hash function: last digit
        int probes = 0;
        while (table[slot] != -1) {      // collision -> linear probe to next slot
            cout << "  Slot " << slot << " taken, trying next..." << endl;
            slot = (slot + 1) % SLOTS;   // wrap around
            probes++;
        }
        table[slot] = reg;
        occupied++;
        cout << "Vehicle " << reg << " parked at slot " << slot << " (extra probes: " << probes << ")" << endl;
    }

    void display() const {
        cout << "Slot : Vehicle" << endl;
        for (int i = 0; i < SLOTS; i++) {
            cout << "  " << i << "  : ";
            if (table[i] == -1) cout << "empty";
            else cout << table[i];
            cout << endl;
        }
    }
};

int main() {
    ParkingLot lot;
    int choice, reg;

    do {
        cout << "\n--- Parking Lot Menu (Linear Probing) ---\n";
        cout << "1. Park Vehicle\n";
        cout << "2. Display Slots\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter registration number: ";
                cin >> reg;
                lot.park(reg);
                break;
            case 2:
                lot.display();
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
